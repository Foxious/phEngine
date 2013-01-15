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
				this.Size = new Size(width, _node.data.Count * labelHeight + pnTitle.Height);
				lbName.Text = _node.code.ToString();
				lbName.Size = new Size(this.Size.Width, lbName.Size.Height);
				lbName.TextAlign = ContentAlignment.MiddleCenter;
				pnLabelStage.Controls.Clear();
				pnLabelStage.Size = new Size(width, _node.data.Count * labelHeight + pnTitle.Height);
				for (int i = 0; i < _node.data.Count; ++i)
				{
					Label data = new Label();
					data.Text = _node.data[i].label;
					data.Location = new Point(0, data.Size.Height * i);
					int dataHeight = data.Size.Height;
					data.Size = new Size(this.Size.Width, data.Size.Height);
					data.TextAlign = ContentAlignment.MiddleCenter;
					pnLabelStage.Controls.Add(data);
				}
			}

		}


		// PRIVATE //////////////////////////////////////////////////////////////////////
		private Node _node;
		private int labelHeight = 25;
		private bool isDragging = false;
		private Point mouseDragStart;

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
