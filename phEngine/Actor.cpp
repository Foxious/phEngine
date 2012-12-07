#include "stdafx.h"

#include "Actor.h"

#include "Utils.h"

Vector2 CalculateDirection(float x, float y)
{
	float absX = abs(x);
	float absY = abs(y);

	Vector2 retval = Vector2(0.0f,0.0f);
	if (absX >= absY) 
	{
		retval.x = Signum(x);
	}
	else
	{
		retval.y = Signum(y);
	}

	return retval;
}


#define MIN_MOVE 0.09f

Actor::Actor()
	: speed(210.0f)
	, mInput(new PlayerController(0))
	, direction(0.0f, -1.0f)
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
	direction = CalculateDirection(x, y);
	mSprite->mXform.position.x += x;
	mSprite->mXform.position.y += y;
	mCollision[0].x += x;
	mCollision[0].y += y;

}

void Actor::Move(Vector2 move)
{
	Move(direction.x, direction.y);
}
