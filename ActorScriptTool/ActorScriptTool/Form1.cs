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
		public Form1()
		{
			InitializeComponent();
			Node testNode = new Node();
			testNode.code = OpCode.op_kill;
			Param testParam = new Param();
			testParam.label = "Actor";
			testParam.size = 4;
			testParam.type = Type.pactor;
			testParam.data = 0;

			testNode.data.Add(testParam);
			ctrlNode1.NodeData = testNode;
		}


	}
}
