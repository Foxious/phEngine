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

	class ScriptStack
	{
	public:
		ScriptStack();
		void push(unsigned char* data, size_t size);
		unsigned char* get(size_t index);
	private:
		enum StackSize
		{
			S = 2048
		};
		size_t tail;
		unsigned char stack[S];
	};

	typedef unsigned int scriptID;

	const scriptID noScript = (scriptID)-1;

	void CopyScript(Script& dst, const Script& src);

	void Execute(scriptID id);
	void Execute(scriptID id, ScriptStack& state);
	void SaveCompiledScript(const std::string& file, scriptID id);
	scriptID AddScript(const Script& script);
	const Script& GetScript(scriptID id);
	scriptID LoadCompiledScript(const std::string& scriptFile);		
}

#endif