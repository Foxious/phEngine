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

	public class ParamsConnectedEventArgs : EventArgs
	{
		public enum EventType
		{
			Connected,
			Broken
		}

		public EventType eventType;
	}
	public delegate void ParamsConnectedEventHandler(object sender, ParamsConnectedEventArgs e);

	public class Param
	{
		public event ParamsConnectedEventHandler ConnectionsChanged;

		public Type 		type;
		public byte 		data;
		public uint 		size;
		public string		label;
		public Node			parent;

		public Param[] Connections
		{
			get
			{
				return connections.ToArray();
			}
		}

		public void AddConnection(Param connection)
		{
			connections.Add(connection);
			OnConnectionChanged(ParamsConnectedEventArgs.EventType.Connected);
		}

		public void RemoveConnection(Param connection)
		{
			connections.Remove(connection);
			OnConnectionChanged(ParamsConnectedEventArgs.EventType.Broken);
		}

		public void ClearConnections()
		{
			for (int i = connections.Count; i > 0; --i)
			{
				RemoveConnection(connections[i]);
			}
		}

		protected void OnConnectionChanged(ParamsConnectedEventArgs.EventType type)
		{
			if (ConnectionsChanged != null)
			{
				ParamsConnectedEventArgs e = new ParamsConnectedEventArgs();
				e.eventType = type;
				ConnectionsChanged(this, e);
			}
		}

		private List<Param> connections;
	}

	public class Node
	{
		public OpCode		code		= 0;

		public void AddInParam (Param inParam)
		{
			inParams.Add(inParam);
			inParam.parent = this;
		}
		public void AddOutParam (Param outParam)
		{
			outParams.Add(outParam);
			outParam.parent = this;
		}

		public static void ConnectNodeParams(Param outParam, Param inParam)
		{
			// There should only be 1 connection on the inParam.
			// Let's make sure this is the case.
			Param oldInConnection = inParam.Connections[0];
			oldInConnection.RemoveConnection(inParam);
			inParam.ClearConnections();

			outParam.AddConnection(inParam);
			inParam.AddConnection(outParam);
		}

		public List<Param>	inParams	= new List<Param>();
		public List<Param>	outParams	= new List<Param>();
	}
}
