// HEADERS //////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"

#include "Actor.h"

#include "Utils.h"


// HELPERS //////////////////////////////////////////////////////////////////////////////
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

/////////////////////////////////////////////////////////////////////////////////////////
Vector2 CalculateDirection(Vector2 direction)
{
	return CalculateDirection(direction.x, direction.y);
}

/////////////////////////////////////////////////////////////////////////////////////////
Vector2 CalculateBoundsPosition(XForm& spriteXForm)
{
	Vector2 scale(spriteXForm.scale.x, spriteXForm.scale.y);
	Vector2 position(spriteXForm.position.x, spriteXForm.position.y);

	return position - (scale * 0.5f);
}

// CONSTANTS ////////////////////////////////////////////////////////////////////////////
#define MIN_MOVE 0.09f

// CTORS ////////////////////////////////////////////////////////////////////////////////
Actor::Actor()
	: speed(210.0f)
	, mInput(0)
	, direction(0.0f, -1.0f)
	, isDead(false)
{
	
}

Actor::~Actor()
{
	//ClearScripts();
}

// PUBLIC ///////////////////////////////////////////////////////////////////////////////
void Actor::Update(float dt)
{
	mInput->Update(this, dt);
	if ( !updateScript.empty() )
	{
		ScriptParams params;
		params.target = this;
		params.deltaTime = dt;
		ExecuteScript(&updateScript, &params);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////
void Actor::SetSprite(MeshInstancePtr sprite)
{
	mSprite = sprite;

	collision.position = CalculateBoundsPosition(mSprite->mXform);

	collision.size.x = mSprite->mXform.scale.x;
	collision.size.y = mSprite->mXform.scale.y;
}

/////////////////////////////////////////////////////////////////////////////////////////
void Actor::OnCollide(Actor* collider)
{
	ScriptParams params;
	params.source = this;
	params.target = collider;
	ExecuteScript(&collisionScript, &params);
}

/////////////////////////////////////////////////////////////////////////////////////////
void Actor::Move(float x, float y)
{
	Move( Vector2(x, y) );
}

/////////////////////////////////////////////////////////////////////////////////////////
void Actor::Move(Vector2 offset)
{
	direction = CalculateDirection(offset.x, offset.y);

	Vector3 absolute = mSprite->mXform.position + offset;

	WarpTo( Vector2(absolute.x, absolute.y) );
}

/////////////////////////////////////////////////////////////////////////////////////////
void Actor::WarpTo(float x, float y)
{
	WarpTo( Vector2(x, y) );
}

/////////////////////////////////////////////////////////////////////////////////////////
void Actor::WarpTo(Vector2 coords)
{
	mSprite->mXform.position = coords;
	collision.position = CalculateBoundsPosition(mSprite->mXform);
}

/////////////////////////////////////////////////////////////////////////////////////////
void Actor::ClearScripts()
{
	ClearScript(&collisionScript);
	ClearScript(&updateScript);
}
