#include "stdafx.h"
#include "ActorManager.h"

void ActorManager::Update(float dt)
{
	std::vector<Actor>::iterator it = actors.begin();
	std::vector<Actor>::iterator end = actors.end();

	for (; it != end; ++it)
	{
		it->Update(dt);
	}
}

Actor* ActorManager::CreateActorStub()
{
	actors.push_back( Actor() );
	Actor& newActor = actors.back();

}