#include "stdafx.h"

#include "Actor.h"

#define MIN_MOVE 0.09f

Actor::Actor()
	: mPos(0.0f, 0.0f)
{
}

void Actor::SetSprite(MeshInstance* sprite)
{
	mSprite = sprite;
	mSprite->mXform.mPos = mPos;	// I don't like this, it's brittle and duplictes state. - pH
}

void Actor::MoveX(float value)
{
	mPos.x += value;
	mSprite->mXform.mPos.x = mPos.x;
}

void Actor::MoveY(float value)
{
	mPos.y += value;
	mSprite->mXform.mPos.y = mPos.y;
}