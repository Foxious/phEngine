#ifndef ACTOR_H
#define ACTOR_H

#include "ActorScript.h"
#include "Controller.h"
#include "Mesh.h"
#include "Shapes.h"
#include "Vector.h"


class Actor;
class ActorManager;

class InputController
{
public:
	virtual void Update(Actor* actor, float dt) = 0;
};

enum ScriptEvents
{
	ev_collision = 0,
	ev_update,

	NUM_EVENTS
};


class Actor
{
	// an Actor is a thing on the stage.
public:
	Actor();
	~Actor();

	void SetSprite(MeshInstancePtr sprite);
	const MeshInstancePtr GetSprite() const { return mSprite; }
	inline void SetController(InputController* controller) { mInput = controller; }
	void SetScriptEvent(unsigned eventID, VM::scriptID script);

	Vector2 GetPosition() { return Vector2(mSprite->mXform.position.x, mSprite->mXform.position.y); }
	Vector2 GetScale() { return Vector2(mSprite->mXform.scale.x, mSprite->mXform.scale.y); }

	void Move(float x, float y);
	void Move(Vector2 offset);
	void WarpTo(float x, float y);
	void WarpTo(Vector2 coords);

	Vector2 GetDirection()	{ return direction; }

	const Box* GetCollision() const { return &collision; }
	void OnCollide(Actor* collider);

	inline bool IsDead() { return isDead; }
	inline void MarkForCleanup() { isDead = true; }
	void ClearScripts();

	AnimationComponent* GetAnimComponent() { return &mSprite->mAnimComponent; }
	
	void Update(float dt);

	float speed;

private:
	MeshInstancePtr mSprite;
	InputController* mInput;
	Box collision;
	Vector2 direction;

	std::vector<VM::scriptID> scripts;

	bool isDead;
};

#endif