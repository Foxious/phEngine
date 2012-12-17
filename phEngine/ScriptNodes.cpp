#include "stdafx.h"
#include "ScriptNodes.h"

#include "ActorManager.h"

// PLAY ANIMATION NODE //////////////////////////////////////////////////////////////////
PlayAnimationNode::PlayAnimationNode(const std::string& animName)
	:animationName(animName)
{
}

void PlayAnimationNode::Execute(Actor* source, Actor* target)
{
	target->GetAnimComponent()->PlayAnim(0u); // TODO: dont' hard code this.
}