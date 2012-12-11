#ifndef ACTOR_MANAGER_H
#define ACTOR_MANAGER_H

#include <vector>

#include "Actor.h"
#include "Component.h"

class ActorManager : public Component
{
public:
	virtual void Update(float dt);

	Actor* CreateActor(const std::string& name);
	Actor* CreateActorStub(); // for test purposes atm
	Actor* CloneActor(Actor* source);

private:
	std::vector<Actor> actors;
	PlayerController playerController;
	PropController propController;

};

#endif