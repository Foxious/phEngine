#ifndef ACTOR_H
#define ACTOR_H

#include "Vector.h"
#include "Mesh.h"

#include "Controller.h"

class Actor;

class InputController
{
public:
	virtual void Update(Actor* actor, float dt) = 0;
};

class PhysicsController
{
	void Move(float x, float y);
};

class Actor
{
	// an Actor is a thing on the stage.
public:
	Actor();
	void SetSprite(MeshInstance* sprite);
	void Move(float x, float y);

	AnimationComponent* GetAnimComponent() { return &mSprite->mAnimComponent; }
	
	void Update(float dt);

	float speed;

private:
	MeshInstance* mSprite;
	InputController* mInput;
	Vector2 mCollision[2];
};

class PlayerController : public InputController
{
public:
	PlayerController(int controllerNum)
		: mController(controllerNum)
		, atkBtn(12)
		, runBtn(13)
	{
	}
	virtual void Update(Actor* actor, float dt)
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
			}

		}
	}

private:
	XboxController mController;

	unsigned int atkBtn;
	unsigned int runBtn;

};

#endif