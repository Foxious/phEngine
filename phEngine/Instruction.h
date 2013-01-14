#ifndef INSTRUCTION_H
#define INSTRUCTION_H

namespace VM
{
	typedef unsigned char opcode;
	enum OpCodes
	{
		op_noop = 0,
		op_end,
		op_push,
		op_forceout,
		op_playanim,
		op_kill,

		NUM_CODES
	};


	class Instruction
	{
	public:
		Instruction();
		Instruction(opcode theCode);
		Instruction(opcode theCode, unsigned char* params, size_t paramsSize);
		Instruction(const Instruction& copy);

		~Instruction();

		Instruction operator= (const Instruction& rhs);
		bool operator== (const Instruction& rhs);
		bool operator!= (const Instruction& rhs);

		inline unsigned char GetCode() const { return code; }
		inline size_t GetDataSize() const { return dataSize; }
		inline const unsigned char* GetData() const { return data; }

	private:
		void FreeData();
	private:
		size_t dataSize;
		opcode code;
		unsigned char* data;
	};
}

#endif