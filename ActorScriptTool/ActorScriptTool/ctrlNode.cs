using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;


namespace ActorScriptTool
{
	public class ConnectionLine : UserControl
	{
		public Point start;
		public Point end;
		public bool draw = false;

		protected override void  OnPaint(PaintEventArgs e)
		{
 			base.OnPaint(e);
			if (draw)
			{
				DrawLine(e.Graphics);
			}
		}

		private void DrawLine(System.Drawing.Graphics g)
		{
			Pen myPen = new Pen(Color.Black);
			myPen.Width = 2;
			g.DrawLine(myPen, start, end);
		}

	}

	[System.ComponentModel.Category("Custom")]
	public partial class ctrlNode : UserControl
	{
		public ctrlNode()
		{
			InitializeComponent();
		}

		public Node NodeData
		{
			get { return _node; }
			set
			{
				if (value == null)
				{
					return;
				}
				_node = value;
				int width = this.Size.Width;
				int numInParams = _node.inParams.Count;
				int numOutParams = _node.outParams.Count;
				this.Size = new Size(width, (numInParams + numOutParams) * labelHeight + pnTitle.Height);
				lbName.Text = _node.code.ToString();
				lbName.Size = new Size(this.Size.Width, lbName.Size.Height);
				lbName.TextAlign = ContentAlignment.MiddleCenter;
				pnLabelStage.Controls.Clear();
				pnLabelStage.Size = new Size(width, (numInParams + numOutParams) * labelHeight + pnTitle.Height);
				for (int i = 0; i < _node.outParams.Count; ++i)
				{
					Label data = new Label();
					data.Text = _node.outParams[i].label;
					data.Location = new Point(0, data.Size.Height * i);
					int dataHeight = data.Size.Height;
					data.Size = new Size(this.Size.Width, data.Size.Height);
					data.TextAlign = ContentAlignment.MiddleCenter;
					_node.outParams[i].ConnectionsChanged += new ParamsConnectedEventHandler(ctrlNode_OutConnectionsChanged);
					ConnectionLine newLine = new ConnectionLine();
					newLine.start = data.Location; // I bet this is wrong

					pnLabelStage.Controls.Add(data);
					
				}
				// pH TODO - DRY
				for (int i = 0; i < _node.inParams.Count; ++i)
				{
					Label data = new Label();
					data.Text = _node.inParams[i].label;
					data.Location = new Point(0, data.Size.Height * (i + numOutParams) );
					int dataHeight = data.Size.Height;
					data.Size = new Size(this.Size.Width, data.Size.Height);
					data.TextAlign = ContentAlignment.MiddleCenter;
					pnLabelStage.Controls.Add(data);
				}

			}

		}

		void ctrlNode_OutConnectionsChanged(object sender, ParamsConnectedEventArgs e)
		{
			if (e.eventType == ParamsConnectedEventArgs.EventType.Connected)
			{

			}
		}


		// PRIVATE //////////////////////////////////////////////////////////////////////
		private Node _node;
		private int labelHeight = 25;
		private bool isDragging = false;
		private Point mouseDragStart;
		private List<ConnectionLine> lines;

		private void OnMouseDown(object sender, MouseEventArgs e)
		{
			isDragging = true;
			mouseDragStart = e.Location;
			this.pnTitle.BackColor = Color.Red;
		}
		private void OnMouseMove(object sender, MouseEventArgs e)
		{
			if (isDragging)
			{
				this.Left += e.X - mouseDragStart.X;
				this.Top += e.Y - mouseDragStart.Y;
			}
		}

		private void OnMouseUp(object sender, MouseEventArgs e)
		{
			isDragging = false;
		}

		private void OnMouseEnter(object sender, EventArgs e)
		{
			this.pnTitle.BackColor = Color.Red;
		}

		private void OnMouseLeave(object sender, EventArgs e)
		{
			this.pnTitle.BackColor = Color.Firebrick;
		}
	}

}
