#ifndef ACTOR_H
#define ACTOR_H

#include "Vector.h"
#include "Mesh.h"

#include "Controller.h"

class Actor;
class ActorManager;

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
	const MeshInstance* GetSprite() const { return mSprite; }
	void SetController(InputController* controller) { mInput = controller; }

	Vector2 GetPosition() { return Vector2(mSprite->mXform.position.x, mSprite->mXform.position.y); }

	void Move(float x, float y);
	void Move(Vector2 offset);
	void WarpTo(float x, float y);
	void WarpTo(Vector2 coords);

	AnimationComponent* GetAnimComponent() { return &mSprite->mAnimComponent; }
	
	void Update(float dt);

	float speed;
	Vector2 GetDirection() { return direction; }

private:
	MeshInstance* mSprite;
	InputController* mInput;
	Vector2 mCollision[2];
	Vector2 direction;
};

#endif