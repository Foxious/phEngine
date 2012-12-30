#ifndef ACTOR_MANAGER_H
#define ACTOR_MANAGER_H

#include <vector>

#include "Actor.h"
#include "Collision.h"
#include "Component.h"
#include "InputManager.h"
#include "ObjectPool.h"

typedef ObjectPool<Actor>::PoolItemPtr ActorPtr;

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
		: inputMapper( new InputMapper( new InputManager() )) // pH todo - CLEAN UP
		, actorManager(manager)
		, atkBtn(12)
		, runBtn(13)
	{
		inputMapper->BindButton(InputMapper::atkBtn, X360, 12);
		inputMapper->BindButton(InputMapper::runBtn, X360, 13);
		inputMapper->BindAxis(InputMapper::lrAxis, X360, 2);
		inputMapper->BindAxis(InputMapper::duAxis, X360, 3);
	}

	virtual void Update(Actor* actor, float dt);

private:
	//XboxController mController;
	InputMapper* inputMapper;
	ActorManager* actorManager;
	DeviceState state;

	unsigned int atkBtn;
	unsigned int runBtn;

};

class ActorManager : public Component
{
public:
	ActorManager();

	virtual void Update(float dt);
	virtual void OnRegister();

	ActorPtr CreateActor(const std::string& name);
	ActorPtr CreateActorStub(); // for test purposes atm
	ActorPtr CloneActor(const ActorPtr source);

private:
	ObjectPool<Actor> actors;
	SpatialHash collider;
	PlayerController* playerController;
	PropController propController;

};

#endif