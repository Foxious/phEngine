#include "stdafx.h"
#include "ActorScript.h"


// PUBLIC ///////////////////////////////////////////////////////////////////////////////
ScriptNode::~ScriptNode()
{
	Script::iterator it = callbackScript.begin();
	Script::iterator end = callbackScript.end();

	for (; it != end; ++it)
	{
		delete *it;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////
void ScriptNode::SetScriptCompleteCallback(const Script& script)
{
	callbackScript = script;
}

/////////////////////////////////////////////////////////////////////////////////////////
void ScriptNode::AddScriptCompleteCallback(ScriptNode* node)
{
	callbackScript.push_back(node);
}

// OPERATORS ////////////////////////////////////////////////////////////////////////////
void ScriptNode::operator()(const ScriptParams* params)
{
	Execute(params);
	if ( IsFinished() )
	{
		ExecuteScript(&callbackScript, params);
	}
}


// STATIC FUNCTIONS /////////////////////////////////////////////////////////////////////
void ExecuteScript(Script* script, const ScriptParams* params)
{
	std::vector<ScriptNode*>::iterator it = script->begin();
	std::vector<ScriptNode*>::iterator end = script->end();

	for (; it != end; ++it)
	{
		(*it)->operator()(params);
	}

}

/////////////////////////////////////////////////////////////////////////////////////////
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