#include "stdafx.h"
#include "ActorScript.h"

#include <assert.h>
#include <fstream>
#include <string>
#include <unordered_map>

#include "Actor.h"
#include "ActorManager.h"

namespace VM
{
	#define COLLISION_PADDING 0.1f

	std::vector<Script> scripts;
	std::unordered_map<std::string, scriptID> loadedScripts;

	ScriptStack::ScriptStack()
		: tail(0)
	{
		stack = new unsigned char[ptr_max];
		clear();
	}

	ScriptStack::~ScriptStack()
	{
		delete [] stack;
	}

	void ScriptStack::push(unsigned char* data, ptr size)
	{
		assert ( (tail+size) < ptr_max);
		memcpy(stack + tail, data, size);
		tail += size;
	}

	unsigned char* ScriptStack::get(ptr index)
	{
		assert( index < tail );
		return &stack[index];
	}

	void ScriptStack::clear()
	{
		tail = 0;
		memset(stack, 0xCD, ptr_max);
	}


	// FUNCTIONS ////////////////////////////////////////////////////////////////////////
	scriptID AddScript(const Script& script)
	{
		scriptID scriptid = scripts.size();
		scripts.push_back(Script());
		Script& newScript = scripts.back();

		CopyScript(newScript, script);

		return scriptid;
	}
	////////////////////////////////////////////////////////////////////////////////////////
	const Script& GetScript(scriptID id)
	{
		return scripts[id];
	}
	////////////////////////////////////////////////////////////////////////////////////////
	scriptID LoadCompiledScript(const std::string& scriptFile)
	{
		std::unordered_map<std::string, scriptID>::iterator scriptIter = loadedScripts.find(scriptFile);
		if (scriptIter != loadedScripts.end())
		{
			return loadedScripts[scriptFile];
		}
		std::fstream file;
		size_t dataSize;
		unsigned char code;
		unsigned char data[256];
		file.open(scriptFile, std::ios::in | std::ios::binary);

		scriptID newscriptID = scripts.size();
		scripts.push_back(Script());
		Script& newScript = scripts.back();

		size_t scriptSize;
		file.read((char*)&scriptSize, sizeof(size_t));
		newScript.reserve(scriptSize);

		for(size_t i = 0; i < scriptSize; ++i)
		{
			file.read((char*) &dataSize, sizeof(size_t));
			file.read((char*) &code, sizeof(unsigned char));
			file.read((char*) data, sizeof(unsigned char) * dataSize);

			newScript.push_back( Instruction(code, &data[0], dataSize) );
		}

		loadedScripts[scriptFile] = newscriptID;

		return newscriptID;
	}

	/////////////////////////////////////////////////////////////////////////////////////
	void SaveCompiledScript(const std::string& scriptFile, scriptID id)
	{
		std::fstream file;
		file.open(scriptFile, std::ios::out | std::ios::binary);

		Script script = scripts[id];

		Script::const_iterator it = script.begin();
		Script::const_iterator end = script.end();
		size_t scriptSize = script.size();
		file.write((char*)&scriptSize, sizeof(size_t));

		size_t dataSize;
		unsigned char code;
		const unsigned char* data;

		for(; it!= end; ++it)
		{
			dataSize = it->GetDataSize();
			code = it->GetCode();
			data = it->GetData();

			file.write((char*)&dataSize, sizeof(size_t));
			file.write((char*)&code, sizeof(unsigned char));
			file.write((char*)data, sizeof(unsigned char) * dataSize);
		}

		file.close();

	}

	/////////////////////////////////////////////////////////////////////////////////////
	void CopyScript(Script& dst, const Script& source)
	{
		dst.resize(source.size());

		for(size_t i = 0; i < source.size(); ++i)
		{
			dst[i] = source[i];
		}
	}

	// EXECUTE /////////////////////////////////////////////////////////////////////////////
	Actor* GetActor(unsigned char* data)
	{
		return (Actor*)*(unsigned int*)data;
	}

	const unsigned char* DataAtOffset(const unsigned char* data, ptr offset)
	{
		return data + offset * ptr_size;
	}

	void Execute(scriptID id)
	{
		ScriptStack scriptState;
		Execute(id, scriptState);
	}

	/////////////////////////////////////////////////////////////////////////////////////
	void Execute(scriptID id, ScriptStack& scriptState)
	{
		Script script = scripts[id];
		Script::const_iterator ins = script.begin();
		Script::const_iterator end = script.end();
		for (; ins != end; ++ins)
		{
			switch(ins->GetCode())
			{
			/////////////////////////////////////////////////////////////////////////////
			case op_noop:
				break;

			case op_push:
				{
					const unsigned char* data = ins->GetData();
					ptr size = *(ptr*)data; // SIZE MISMATCH, fix it ppeas Phil
					unsigned char* value = (unsigned char*)DataAtOffset(data, 1);
					scriptState.push(value, size);
				}

				break;
			/////////////////////////////////////////////////////////////////////////////
			case op_end:
				return;
				break;

			/////////////////////////////////////////////////////////////////////////////
			case op_forceout:
				{
					// figure out our overlap and how much we have.
					const unsigned char* data = ins->GetData();
					Actor* target = GetActor(scriptState.get(*data));
					Actor* source = GetActor( scriptState.get(*DataAtOffset(data, 1)) );
					const Box* sourceBox = source->GetCollision();
					const Box* targetBox = target->GetCollision();

					if ( !BoxesIntersect(sourceBox, targetBox) )
					{
						return;
					}

					float x1, x2, x3, x4, y1, y2, y3, y4;

					x1 = sourceBox->GetUpperLeft().x;
					x2 = targetBox->GetUpperRight().x;

					x3 = sourceBox->GetUpperRight().x;
					x4 = targetBox->GetUpperLeft().x;

					y1 = sourceBox->GetLowerLeft().y;
					y2 = targetBox->GetUpperLeft().y;

					y3 = sourceBox->GetUpperLeft().y;
					y4 = targetBox->GetLowerLeft().y;

					float bottomOverlap = y1-y2+COLLISION_PADDING;
					float topOverlap = y3-y4-COLLISION_PADDING;

					float leftOverlap = x1-x2-COLLISION_PADDING;
					float rightOverlap = x3-x4+COLLISION_PADDING;

					float moveY = abs(topOverlap) > abs(bottomOverlap) ? bottomOverlap : topOverlap;
					float moveX = abs(leftOverlap) > abs(rightOverlap) ? rightOverlap : leftOverlap;

					Vector2 moveFirst, moveSecond;

					if (abs(moveX) < abs(moveY))
					{
						moveFirst.x = moveX;
						moveSecond.y = moveY;
					}
					else
					{
						moveFirst.y = moveY;
						moveSecond.x = moveX;
					}

					target->Move(moveFirst);

					if ( BoxesIntersect(sourceBox, targetBox) )
					{
						target->Move(moveSecond);
					}
				}
				break;
			/////////////////////////////////////////////////////////////////////////////
			case op_playanim:
				{
					const unsigned char* data = ins->GetData();
					Actor* target = GetActor(scriptState.get(*data));
					unsigned char animName = (unsigned char)*( DataAtOffset(data, 1) );
					target->GetAnimComponent()->PlayAnim((char*)scriptState.get(animName));
				}
				break;

			/////////////////////////////////////////////////////////////////////////////
			case op_kill:
				const unsigned char* data = ins->GetData();
				Actor* target = (Actor*) scriptState.get(*(unsigned int*)data);
				target->MarkForCleanup();
				break;

			} // end switch(instruction)
		} // end for
	} // end Execute

} // end namespace