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
	scripts.resize(NUM_EVENTS);
	ClearScripts();
}

Actor::~Actor()
{
}

// PUBLIC ///////////////////////////////////////////////////////////////////////////////
void Actor::Update(float dt)
{
	mInput->Update(this, dt);
	VM::scriptID updateScript = scripts[ev_update];
	if ( updateScript != VM::noScript )
	{
		VM::ScriptStack state;
		state.push((unsigned char*) this, sizeof(this));
		VM::Execute(updateScript, state);
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
void Actor::SetScriptEvent(unsigned int eventID, VM::scriptID script)
{
	assert (eventID < NUM_EVENTS);
	scripts[eventID] = script;
}

/////////////////////////////////////////////////////////////////////////////////////////
void Actor::OnCollide(Actor* collider)
{
	VM::ScriptParams params;
	params.source = this;
	params.target = collider;

	// target is index 0, source is index 1
	VM::ScriptStack state;
	unsigned int colliderAddr = (unsigned int) collider;
	unsigned int thisAddr = (unsigned int) this;
	state.push((unsigned char*)&colliderAddr, sizeof(collider));
	state.push((unsigned char*)&thisAddr, sizeof(this));

	VM::Execute( scripts[ev_collision], state );
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
	for (int i = 0; i < NUM_EVENTS; ++i)
	{
		scripts[i] = VM::noScript;
	}
}
