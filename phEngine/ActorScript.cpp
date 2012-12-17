#include "stdafx.h"
#include "ActorScript.h"

void ExecuteScript( Script* script, Actor* source, Actor* target)
{
	std::vector<ScriptNode*>::iterator it = script->begin();
	std::vector<ScriptNode*>::iterator end = script->end();

	for (; it != end; ++it)
	{
		(*it)->Execute(source, target);
	}

}

void ClearScript(Script* script)
{
	Script::iterator it = script->begin();
	Script::iterator end = script->end();

	for (; it != end; ++it)
	{
		delete (*it);
	}

	script->clear();
}