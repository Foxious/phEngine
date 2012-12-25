#ifndef ACTOR_SCRIPT_H
#define ACTOR_SCRIPT_H

#include <vector>

class Actor;
class ScriptNode;

struct ScriptParams
{
	Actor* source;
	Actor* target;
	float deltaTime;
};

typedef std::vector<ScriptNode*> Script;


class ScriptNode
{
public:
	virtual ~ScriptNode();

	void SetScriptCompleteCallback(const Script& script);
	void AddScriptCompleteCallback(ScriptNode* node);

	virtual bool IsFinished() { return true; }

	void operator() (const ScriptParams* params);


private:
	virtual void Execute(const ScriptParams* params)=0;
private:
	Script callbackScript;
};



void ExecuteScript(Script* script, const ScriptParams* params);
void ClearScript(Script* script);

#endif