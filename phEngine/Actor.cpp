#include "stdafx.h"

#include "Actor.h"

#define MIN_MOVE 0.09f

Actor::Actor()
	: speed(210.0f)
	, mInput(new PlayerController(0))
{
	
}

void Actor::Update(float dt)
{
	mInput->Update(this, dt);
}

void Actor::SetSprite(MeshInstance* sprite)
{
	mSprite = sprite;
}

void Actor::Move(float x, float y)
{
	mSprite->mXform.position.x += x;
	mSprite->mXform.position.y += y;
	mCollision[0].x += x;
	mCollision[0].y += y;

}