using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ActorScriptTool
{
	enum OpCode
	{
		op_noop=0,
		op_end,
		op_push,
		op_forceout,
		op_playanim,
		op_kill,

		NUM_CODES
	}

	enum Type
	{
		type_int=0,
		type_actorPtr,
		type_string,

		NUM_TYPES
	}

	class Param<T>
	{
		public Type type;
		public T data;
	}

	class Node
	{
		public OpCode code;
		List<Param> data;
	}
}
