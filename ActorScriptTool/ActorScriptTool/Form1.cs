using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;


namespace ActorScriptTool
{
	public partial class Form1 : Form
	{
		public List<ConnectionLine> lines = new List<ConnectionLine>();
		public Form1()
		{
			InitializeComponent();
			Node testNode = new Node();
			testNode.code = OpCode.op_kill;

			Node testNode2 = new Node();
			testNode2.code = OpCode.op_playanim;

			Param testParam = new Param();
			testParam.label = "Actor";
			testParam.size = 4;
			testParam.type = Type.pactor;
			testParam.data = 0;

			Param testOutParam = new Param();
			testOutParam.label = "Int";
			testOutParam.size = 4;
			testOutParam.type = Type.pint;
			testOutParam.data = 0;

			testNode2.inParams.Add(testParam);
			testNode.outParams.Add(testOutParam);
			ctrlNode1.NodeData = testNode;
			ctrlNode2.NodeData = testNode2;

			ctrlNode1.ConnectParam(0, ctrlNode2, 0);

		}

	}
}
