#include "stdafx.h"
#include "ScriptNodes.h"

#include "ActorManager.h"

#define COLLISION_PADDING 0.1f

// PLAY ANIMATION NODE //////////////////////////////////////////////////////////////////
PlayAnimationNode::PlayAnimationNode(const std::string& animName)
	:animationName(animName)
{
}

void PlayAnimationNode::Execute(const ScriptParams* params)
{
	params->source->GetAnimComponent()->PlayAnim(0u); // TODO: dont' hard code this.
}

// FORCE OUT NODE ///////////////////////////////////////////////////////////////////////
void ForceOutNode::Execute(const ScriptParams* params)
{
	// figure out our overlap and how much we have.
	const Box* sourceBox = params->source->GetCollision();
	const Box* targetBox = params->target->GetCollision();

	if ( !BoxesIntersect(sourceBox, targetBox) )
	{
		return;
	}

	float x1, x2, x3, x4, y1, y2, y3, y4;

	x1 = sourceBox->GetUpperLeft().x;
	x2 = targetBox->GetUpperRight().x;

	x3 = sourceBox->GetUpperRight().x;
	x4 = targetBox->GetUpperLeft().x;

	y1 = sourceBox->GetLowerLeft().y;
	y2 = targetBox->GetUpperLeft().y;

	y3 = sourceBox->GetUpperLeft().y;
	y4 = targetBox->GetLowerLeft().y;

	float bottomOverlap = y1-y2+COLLISION_PADDING;
	float topOverlap = y3-y4-COLLISION_PADDING;

	float leftOverlap = x1-x2-COLLISION_PADDING;
	float rightOverlap = x3-x4+COLLISION_PADDING;

	float moveY = abs(topOverlap) > abs(bottomOverlap) ? bottomOverlap : topOverlap;
	float moveX = abs(leftOverlap) > abs(rightOverlap) ? rightOverlap : leftOverlap;

	Vector2 moveFirst, moveSecond;

	if (abs(moveX) < abs(moveY))
	{
		moveFirst.x = moveX;
		moveSecond.y = moveY;
	}
	else
	{
		moveFirst.y = moveY;
		moveSecond.x = moveX;
	}

	params->target->Move(moveFirst);

	if ( BoxesIntersect(sourceBox, targetBox) )
	{
		params->target->Move(moveSecond);
	}
}

// TIMER NODE ///////////////////////////////////////////////////////////////////////////

TimerNode::TimerNode(float duration)
	: time(duration)
	, isFinished(false)
{
}

void TimerNode::Execute(const ScriptParams* params)
{
	time -= params->deltaTime;
	if (time < 0.0f)
	{
		isFinished = true;
	}
}

// KILL ACTOR NODE //////////////////////////////////////////////////////////////////////
void KillActorNode::Execute(const ScriptParams* params)
{
	params->target->MarkForCleanup();
}