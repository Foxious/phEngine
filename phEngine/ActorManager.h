#ifndef ACTOR_MANAGER_H
#define ACTOR_MANAGER_H

#include <vector>

#include "Actor.h"
#include "Component.h"

class ActorManager;

class PropController : public InputController
{
	virtual void Update(Actor* actor, float dt)
	{
	}
};

class PlayerController : public InputController
{
public:
	PlayerController(int controllerNum, ActorManager* manager)
		: mController(controllerNum)
		, actorManager(manager)
		, atkBtn(12)
		, runBtn(13)
	{
	}

	virtual void Update(Actor* actor, float dt);

private:
	XboxController mController;
	ActorManager* actorManager;

	unsigned int atkBtn;
	unsigned int runBtn;

};

class ActorManager : public Component
{
public:
	ActorManager();

	virtual void Update(float dt);
	virtual void OnRegister();

	Actor* CreateActor(const std::string& name);
	Actor* CreateActorStub(); // for test purposes atm
	Actor* CloneActor(Actor* source);

private:
	void AddNewActors();

private:
	std::vector<Actor> actors;
	std::vector<Actor> newActors;
	PlayerController* playerController;
	PropController propController;

};

#endif