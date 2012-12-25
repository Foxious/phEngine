#ifndef SCRIPT_NODES_H
#define SCRIPT_NODES_H

#include "ActorScript.h"
#include <string>

#include "Vector.h"


class PlayAnimationNode : public ScriptNode
{
public:
	PlayAnimationNode(const std::string& animName);

private:
	virtual void Execute(const ScriptParams* params);

private:
	std::string animationName;
};

class MoveActorNode : public ScriptNode
{
public:
	MoveActorNode(Vector2 moveAmount);

private:
	virtual void Execute(const ScriptParams* params);

private:
	Vector2 moveAmount;
};

class ForceOutNode : public ScriptNode
{
public:
	ForceOutNode(){}

private:
	virtual void Execute(const ScriptParams* params);
};

class TimerNode : public ScriptNode
{
public:
	TimerNode(float duration);

private:
	virtual void Execute(const ScriptParams* params);
	virtual bool IsFinished() { return isFinished; }

private:
	float time;
	bool isFinished;
};

class KillActorNode : public ScriptNode
{
private:
	virtual void Execute(const ScriptParams* params);
};

#endif