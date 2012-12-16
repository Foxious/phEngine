#include "stdafx.h"
#include "ActorManager.h"

ActorManager::ActorManager()
	: actors(1000)
	, collider(512.0f, 3)
{
	playerController = new PlayerController(0, this);
}

void ActorManager::OnRegister()
{
	Actor* player = CreateActorStub();
	player->SetController(playerController);
}

void ActorManager::Update(float dt)
{
	collider.Clear();
	ObjectPool<Actor>::Iterator it = actors.Begin();

	for (; it.IsValid(); ++it)
	{
		it->Update(dt);
		collider.ResolveCollisions(&(*it));
		collider.Classify(&(*it));
	}

	collider.Clear();
}

Actor* ActorManager::CreateActorStub()
{
	Actor newActor;
	MeshInstance* sprite = gameMaster->GetRenderer().GetMesh("testSpriteDef.json");
	newActor.SetSprite(sprite);
	newActor.SetController(&propController);

	poolIndex index = actors.Insert(newActor);
	return &actors[index];
}

Actor* ActorManager::CloneActor(const Actor* source)
{
	Actor newActor;
	MeshInstance* sprite = gameMaster->GetRenderer().CopyMesh( source->GetSprite() );
	poolIndex index = actors.Insert(newActor);
	return &actors[index];
}

void PlayerController::Update(Actor* actor, float dt)
{
	DeviceState state;
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

		if (state.buttons[atkBtn])
		{
			actor->GetAnimComponent()->PlayAnim(0U);

			Actor* subActor = actorManager->CreateActorStub();
			subActor->WarpTo(actor->GetPosition() + actor->GetDirection() * 350.0f);
			subActor->GetAnimComponent()->PlayAnim(0U);
		}

	}
}