#include "stdafx.h"

#include "Actor.h"

#define MIN_MOVE 0.09f

Actor::Actor()
{
}

void Actor::SetSprite(MeshInstance* sprite)
{
	mSprite = sprite;
}

void Actor::MoveX(float value)
{
	mSprite->mXform.mPos.x += value;
}

void Actor::MoveY(float value)
{
	mSprite->mXform.mPos.y += value;
}