#include "stdafx.h"
#include "ActorManager.h"

ActorManager::ActorManager()
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
	std::vector<Actor>::iterator it = actors.begin();
	std::vector<Actor>::iterator end = actors.end();

	for (; it != end; ++it)
	{
		it->Update(dt);
	}

	AddNewActors();

}

Actor* ActorManager::CreateActorStub()
{
	newActors.push_back( Actor() );
	Actor& newActor = newActors.back();
	MeshInstance* sprite = gameMaster->GetRenderer().GetMesh("testSpriteDef.json");
	newActor.SetSprite(sprite);
	newActor.SetController(&propController);

	return &newActor;
}

void ActorManager::AddNewActors()
{
	std::vector<Actor>::iterator it = newActors.begin();
	std::vector<Actor>::iterator end = newActors.end();

	for (; it != end; ++it)
	{
		actors.push_back(*it);
	}

	newActors.clear();
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
		float x = state.axes[2] * actor->speed * dt * multiplier;
		float y = state.axes[3] * actor->speed * dt * multiplier;
		actor->Move(x, y);

		if (state.buttons[atkBtn])
		{
			actor->GetAnimComponent()->PlayAnim(0U);

			Actor* subActor = actorManager->CreateActorStub();
			subActor->WarpTo(actor->GetPosition() + actor->GetDirection() * 256.0f);
		}

	}
}