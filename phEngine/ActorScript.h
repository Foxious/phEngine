#ifndef ACTOR_SCRIPT_H
#define ACTOR_SCRIPT_H

#include <vector>

class Actor;

class ScriptNode
{
public:
	virtual void Execute(Actor* source, Actor* target)=0;
};

typedef std::vector<ScriptNode*> Script;

void ExecuteScript(Script* script, Actor* source, Actor* target);
void ClearScript(Script* script);

#endif