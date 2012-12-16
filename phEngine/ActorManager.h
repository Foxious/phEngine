#ifndef ACTOR_MANAGER_H
#define ACTOR_MANAGER_H

#include <vector>

#include "Actor.h"
#include "Collision.h"
#include "Component.h"
#include "ObjectPool.h"

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

class CollisionManager
{
public:
	void Update(float dt);
private:
	std::vector<Vector2[2]> boxes;
};

class ActorManager : public Component
{
public:
	ActorManager();

	virtual void Update(float dt);
	virtual void OnRegister();

	Actor* CreateActor(const std::string& name);
	Actor* CreateActorStub(); // for test purposes atm
	Actor* CloneActor(const Actor* source);

private:
	ObjectPool<Actor> actors;
	SpatialHash collider;
	PlayerController* playerController;
	PropController propController;

};

#endif