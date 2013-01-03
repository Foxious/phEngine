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
	collisionScript.push_back(new PlayAnimationNode("Jump"));
	
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
	inputMapper->Update(dt); // todo - this should just be taken care of by the GM

	float multiplier = 1.0f;
	if ( inputMapper->GetButtonState(InputMapper::runBtn) )
	{
		multiplier = 2.0f;
	}

	Vector2 move;
	float moveSpeed = actor->speed * dt * multiplier;
	move.x = inputMapper->GetAxisState(InputMapper::lrAxis) * moveSpeed;
	move.y = inputMapper->GetAxisState(InputMapper::duAxis) * moveSpeed;

	char leftButton		= inputMapper->GetButtonStateToggle(InputMapper::leftBtn);
	char rightButton	= inputMapper->GetButtonStateToggle(InputMapper::rightBtn);
	char upButton		= inputMapper->GetButtonStateToggle(InputMapper::upBtn);
	char downButton		= inputMapper->GetButtonStateToggle(InputMapper::downBtn);

	if (leftButton || rightButton)
	{
		move.x = (rightButton - leftButton) * moveSpeed;
	}
	if (upButton || downButton)
	{
		move.y = (upButton - downButton) * moveSpeed;
	}
		
	if (move != Vector2::Zero )
	{
		actor->Move(move);
		actor->GetAnimComponent()->PlayAnim("Walk");
	}

	if (inputMapper->GetButtonState(InputMapper::atkBtn) == BTN_DOWN)
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