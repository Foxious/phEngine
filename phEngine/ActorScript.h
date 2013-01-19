#ifndef ACTOR_SCRIPT_H
#define ACTOR_SCRIPT_H

#include <vector>

#include "Instruction.h"

class Actor;

namespace VM
{
	typedef unsigned char ptr;
	typedef unsigned int scriptID;
	typedef std::vector<Instruction> Script;

	const ptr ptr_size		= sizeof(ptr);
	const ptr ptr_max		= -1;
	const scriptID noScript = (scriptID)-1;

	class ScriptStack
	{
	public:
		ScriptStack();
		~ScriptStack();
		void push(unsigned char* data, ptr size);
		unsigned char* get(ptr index);

	private:
		void clear();
	private:
		ptr tail;
		unsigned char *stack;
	};

	void CopyScript(Script& dst, const Script& src);
	void Execute(scriptID id);
	void Execute(scriptID id, ScriptStack& state);
	void SaveCompiledScript(const std::string& file, scriptID id);
	scriptID AddScript(const Script& script);
	const Script& GetScript(scriptID id);
	scriptID LoadCompiledScript(const std::string& scriptFile);		
}

#endif