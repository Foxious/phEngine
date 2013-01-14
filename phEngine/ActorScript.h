#ifndef ACTOR_SCRIPT_H
#define ACTOR_SCRIPT_H

#include <vector>

#include "Instruction.h"

class Actor;

namespace VM
{
	struct ScriptParams
	{
		Actor* source;
		Actor* target;
	};

	typedef std::vector<Instruction> Script;
	typedef std::vector<unsigned int> ScriptState;
	typedef unsigned int scriptID;

	const scriptID noScript = (scriptID)-1;

	void CopyScript(Script& dst, const Script& src);

	void Execute(scriptID id);
	void Execute(scriptID id, ScriptState& state);
	void SaveCompiledScript(const std::string& file, scriptID id);
	scriptID AddScript(const Script& script);
	const Script& GetScript(scriptID id);
	scriptID LoadCompiledScript(const std::string& scriptFile);		
}

#endif