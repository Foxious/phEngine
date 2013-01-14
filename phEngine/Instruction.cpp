#include "stdafx.h"

#include "Instruction.h"

#include <assert.h>

namespace VM
{
	// HELPERS /////////////////////////////////////////////////////////////////////////////
	bool CompareParams(unsigned char* param1, unsigned char* param2, size_t paramSize)
	{
		for (size_t i = 0; i < paramSize; ++i)
		{
			if (param1[i] != param2[i])
			{
				return false;
			}
		}

		return true;
	}

	// INSTRUCTION //////////////////////////////////////////////////////////////////////
	Instruction::Instruction()
		: dataSize(0)
		, code(0)
		, data(0)
	{
	}

	/////////////////////////////////////////////////////////////////////////////////////
	Instruction::Instruction(opcode theCode)
		: dataSize(0)
		, code(theCode)
		, data(0)
	{
		assert(code < NUM_CODES);
	}

	/////////////////////////////////////////////////////////////////////////////////////
	Instruction::Instruction(opcode theCode, unsigned char* params, size_t paramsSize)
		: dataSize(paramsSize)
		, code(theCode)
	{
		assert(code < NUM_CODES);

		if (dataSize)
		{
			data = new unsigned char[dataSize];
			memcpy(data, params, dataSize);
		}
	}

	/////////////////////////////////////////////////////////////////////////////////////
	Instruction::Instruction(const Instruction& copy)
		: dataSize(copy.dataSize)
		, code(copy.code)
	{
		assert(code < NUM_CODES);
		if (dataSize)
		{
			data = new unsigned char[dataSize];
			memcpy(data, copy.data, dataSize);
		}
	}

	/////////////////////////////////////////////////////////////////////////////////////
	Instruction::~Instruction()
	{
		FreeData();
	}

	/////////////////////////////////////////////////////////////////////////////////////
	Instruction Instruction::operator= (const Instruction& rhs)
	{
		FreeData();

		code = rhs.code;
		dataSize = rhs.dataSize;
		
		if (dataSize)
		{
			data = new unsigned char[dataSize];
			memcpy(data, rhs.data, dataSize);
		}

		return *this;
	}

	// OPERATORS ////////////////////////////////////////////////////////////////////////
	bool Instruction::operator== (const Instruction& rhs)
	{
		return ( code == rhs.code && dataSize == rhs.dataSize && CompareParams(data, rhs.data, dataSize) );
	}

	/////////////////////////////////////////////////////////////////////////////////////
	bool Instruction::operator!=(const Instruction& rhs)
	{
		return !(*this == rhs);
	}

	// PRIVATE //////////////////////////////////////////////////////////////////////////
	void Instruction::FreeData()
	{
		if (dataSize)
		{
			delete [] data;
			data = 0;
			dataSize = 0;
		}
	}

}