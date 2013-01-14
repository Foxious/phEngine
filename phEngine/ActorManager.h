#ifndef ACTOR_MANAGER_H
#define ACTOR_MANAGER_H

#include <unordered_map>
#include <vector>

#include "Actor.h"
#include "ActorScript.h"
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
		// binds for X360
		inputMapper->BindButton(InputMapper::atkBtn, X360, 12);
		inputMapper->BindButton(InputMapper::runBtn, X360, 13);
		inputMapper->BindAxis(InputMapper::lrAxis, X360, 2);
		inputMapper->BindAxis(InputMapper::duAxis, X360, 3);

		// binds for windows keyboard
		/*inputMapper->BindButton(InputMapper::atkBtn, KEYBOARD, 0x20 - 0x08);
		inputMapper->BindButton(InputMapper::runBtn, KEYBOARD, 0x11 - 0x08);

		inputMapper->BindButton(InputMapper::leftBtn, KEYBOARD, 0x41 - 0x08);
		inputMapper->BindButton(InputMapper::rightBtn, KEYBOARD, 0x44 - 0x08);
		inputMapper->BindButton(InputMapper::upBtn, KEYBOARD, 0x57 - 0x08);
		inputMapper->BindButton(InputMapper::downBtn, KEYBOARD, 0x53 - 0x08);*/

	}

	virtual void Update(Actor* actor, float dt);

private:
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

	ActorPtr GetActor(const std::string& name);
	ActorPtr CreateActorStub(); // for test purposes atm
	ActorPtr CloneActor(const ActorPtr source);

private:
	ActorPtr DeserializeActor(const std::string& actorData, const std::string& name);

private:
	ObjectPool<Actor> actors;
	std::unordered_map<std::string, Actor> actorDefinitions;
	SpatialHash collider;
	PlayerController* playerController;
	PropController propController;

};

#endif