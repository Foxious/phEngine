#include "stdafx.h"
#include "ActorManager.h"

#include "ActorScript.h"
#include "ScriptNodes.h"

// CTOR /////////////////////////////////////////////////////////////////////////////////
ActorManager::ActorManager()
	: actors(1000)
	, collider(512.0f, 3)
{
	playerController = new PlayerController(0, this);
}

// PUBLIC //////////////////////////////////////////////////////////////////////////////
void ActorManager::OnRegister()
{
	ActorPtr player = CreateActorStub();
	player->SetController(playerController);

	Script collisionScript;
	collisionScript.push_back(new PlayAnimationNode(""));
	
	player->SetCollisionScript(collisionScript);
}

/////////////////////////////////////////////////////////////////////////////////////////
void ActorManager::Update(float dt)
{
	collider.Clear();
	ObjectPool<Actor>::Iterator it = actors.Begin();

	for (; it.IsValid(); ++it)
	{
		it->Update(dt);
		collider.ResolveCollisions(&(*it));
		collider.Classify(&(*it));

		if ( it->IsDead() )
		{
			gameMaster->GetRenderer().RemoveMeshInstance(it->GetSprite());
			it->ClearScripts();
			actors.Remove(&it);
		}
	}

	collider.Clear();
}

/////////////////////////////////////////////////////////////////////////////////////////
ActorPtr ActorManager::CreateActorStub()
{
	Actor newActor;
	MeshInstancePtr sprite = gameMaster->GetRenderer().GetMesh("testSpriteDef.json");
	newActor.SetSprite(sprite);
	newActor.SetController(&propController);

	Script collisionScript;
	collisionScript.push_back(new ForceOutNode());

	newActor.SetCollisionScript(collisionScript);

	ActorPtr actor = actors.Insert(newActor);
	return actor;
}

/////////////////////////////////////////////////////////////////////////////////////////
ActorPtr ActorManager::CloneActor(const ActorPtr source)
{
	Actor newActor;
	MeshInstancePtr sprite = gameMaster->GetRenderer().CopyMesh( source->GetSprite() );
	ActorPtr actor = actors.Insert(newActor);
	return actor;
}

// PLAYER CONTROLLER ////////////////////////////////////////////////////////////////////
void PlayerController::Update(Actor* actor, float dt)
{
	mController.Poll(&state);
	if (mController.IsConnected())
	{
		float multiplier = 1.0f;
		if (state.buttons[runBtn])
		{
			multiplier = 2.0f;
		}
		Vector2 move;
		move.x = state.axes[2] * actor->speed * dt * multiplier;
		move.y = state.axes[3] * actor->speed * dt * multiplier;
		
		if (move != Vector2::Zero )
		actor->Move(move);

		if (state.buttons[atkBtn] == BTN_RELEASE)
		{
			actor->GetAnimComponent()->PlayAnim(0U);

			ActorPtr subActor = actorManager->CreateActorStub();
			subActor->WarpTo(actor->GetPosition() + actor->GetDirection() * 350.0f);
			subActor->GetAnimComponent()->PlayAnim(0U);
			
			ScriptNode* killActor = new KillActorNode();
			ScriptNode* delay = new TimerNode(3.0f);
			delay->AddScriptCompleteCallback(killActor);

			subActor->updateScript.push_back(delay);
		}

	}
}