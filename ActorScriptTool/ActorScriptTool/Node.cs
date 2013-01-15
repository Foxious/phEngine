using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ActorScriptTool
{
	public enum OpCode
	{
		op_noop=0,
		op_end,
		op_push,
		op_forceout,
		op_playanim,
		op_kill,

		NUM_CODES
	}

	public enum Type
	{
		pint=0,
		pactor,
		pstring,
		buffer,

		NUM_TYPES
	}

	public class Param
	{
		public Type 		type;
		public byte 		data;
		public uint 		size;
		public string		label;
		public Node			parent;

		// think about doing connections with a static method, 
		// that way you guarantee that things get connected and that
		// nodes of the same type can't get connected
		public static void ConnectNodes(OutParam outParam, InParam inParam)
		{
			inParam.BreakConnection();
			outParam.SetConnection(inParam);
			inParam.SetConnection(outParam);
		}

		public static void TestFunction()
		{
			Param outParam = new OutParam();
			Param inParam = new InParam();

			ConnectNodes(outParam, inParam);
		}

		public abstract void SetConnection(Param inConnection);
		public abstract IEnumerable<Param> GetConnections();
		public abstract void ClearConnections();
	}
	public class InParam : Param
	{
		protected override void SetConnection(Param inConnection)
		{
			connection = inConnection as OutParam;
		}

		public void BreakConnection()
		{
			connection.RemoveConnection(this);
			this.connection = null;
		}
		private OutParam connection;
	}
	public class OutParam : Param
	{
		public override void SetConnection(Param inConnection)
		{
			// todo - see if this is already connected
			connections.Add(inConnection as InParam);
		}
		public void RemoveConnection(InParam connection)
		{
			for (int i = 0; i < connections.Count; ++i)
			{
				if (connections[i] == connection)
				{
					connections.Remove(connections[i]);
					return;
				}
			}
		}

		private List<InParam> connections;
	}

	public class Node
	{
		public OpCode		code	= 0;
		public List<Param>	data	= new List<Param>();
	}
}
