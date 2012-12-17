#ifndef SCRIPT_NODES_H
#define SCRIPT_NODES_H

#include "ActorScript.h"
#include <string>

#include "Vector.h"


class PlayAnimationNode : public ScriptNode
{
public:
	PlayAnimationNode(const std::string& animName);
	virtual void Execute(Actor* source, Actor* target);

private:
	std::string animationName;
};

class MoveActorNode : public ScriptNode
{
public:
	MoveActorNode(Vector2 moveAmount);
	virtual void Execute(Actor* source, Actor* target);

private:
	Vector2 moveAmount;
};

class ForceOutNode : public ScriptNode
{
public:
	ForceOutNode();
	virtual void Execute(Actor* source, Actor* target);
};

#endif