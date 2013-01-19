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
	public abstract partial class NodeLabel : UserControl
	{
		public NodeLabel()
		{
			InitializeComponent();
			//dragDot.Left = pnLabel.Right;
			SetDotX();
			SetMouseHandler();
			dragDot.Top = (this.Size.Height - dragDot.Size.Height) / 2;
			this.Controls.Add(dragDot);
			DragHandle.BringToFront();
		}

		public DragDot DragHandle
		{
			get
			{
				return dragDot;
			}
		}

		public override string Text
		{
			get
			{
				return lbName.Text;
			}
			set
			{
				lbName.Text = value;
			}
		}

		public Point GetLineLocation()
		{
			Form form = FindForm();
			return form.PointToClient(PointToScreen(DragHandle.Center));
		}

		protected abstract void SetDotX();
		protected abstract void SetMouseHandler();
		protected DragDot dragDot = new DragDot();

	}

	[System.ComponentModel.Category("Custom")]
	[Serializable]
	public class OutLabel : NodeLabel
	{
		public void AddConnection(InLabel connection)
		{
			connections.Add(connection);
		}
		public void RemoveConnection(InLabel connection)
		{
			connections.Remove(connection);
		}
		public InLabel[] Connections
		{
			get 
			{ 
				return connections.ToArray(); 
			}
		}
		protected override void SetMouseHandler()
		{
			dragDot.MouseDown += OnMouseClick;
			dragDot.DragOver += OnDragEnter;
			dragDot.GiveFeedback += OnGiveFeedback;
		}

		protected void OnMouseClick(object sender, MouseEventArgs e)
		{
			dragLine = new ConnectionLine();
			dragLine.Start = FindForm().PointToClient(PointToScreen(DragHandle.Center));
			dragLine.End = PointToClient(e.Location);
			FindForm().Controls.Add(dragLine);
			dragLine.Invalidate();
			DragDropEffects effect = dragDot.DoDragDrop(this, DragDropEffects.Link);
			FindForm().Controls.Remove(dragLine);
			dragLine = null;
			DragHandle.Glowing = false;
		}

		protected void OnGiveFeedback(object sender, GiveFeedbackEventArgs e)
		{
			e.UseDefaultCursors = false;
			dragLine.End = FindForm().PointToClient(new Point(Cursor.Position.X, Cursor.Position.Y));
			FindForm().Invalidate();
		}

		protected void OnDragEnter(object sender, DragEventArgs e)
		{
			DragHandle.Glowing = true;
			e.Effect = DragDropEffects.Link;
		}

		protected override void SetDotX()
		{
			dragDot.Left = pnLabel.Right-1;
		}

		private HashSet<InLabel> connections = new HashSet<InLabel>();
		private ConnectionLine dragLine = null;
	}

	[System.ComponentModel.Category("Custom")]
	[Serializable]
	public class InLabel : NodeLabel
	{
		public void RemoveConnection()
		{
			if (connection != null)
			{
				connection.RemoveConnection(this);
				connection = null;
				FindForm().Controls.Remove(line);
			}
		}
		protected override void SetMouseHandler()
		{
			dragDot.DragEnter	+= OnDragEnter;
			dragDot.DragDrop	+= OnDragDrop;
			dragDot.DragLeave	+= OnDragLeave;
			dragDot.MouseClick	+= OnClick;
		}

		protected override void SetDotX()
		{
			dragDot.Left = pnLabel.Left - dragDot.Width;
		}
		private void OnClick(object sender, EventArgs e)
		{
			RemoveConnection();
		}
		private void OnDragEnter(object sender, DragEventArgs e)
		{
			DragHandle.Glowing = true;
			e.Effect = DragDropEffects.Link;
		}

		private void OnDragLeave(object sender, EventArgs e)
		{
			DragHandle.Glowing = false;
		}

		private void OnDragDrop(object sender, DragEventArgs e)
		{
			if (connection != null)
			{
			    RemoveConnection();
			}

			Form form = FindForm();
			connection = (OutLabel)e.Data.GetData(typeof(OutLabel));
			connection.AddConnection(this);
			DragDot dh = connection.DragHandle;
			this.line = new ConnectionLine();
			this.line.End = form.PointToClient(PointToScreen(DragHandle.Center));
			this.line.Start = form.PointToClient(connection.PointToScreen(dh.Center));
			form.Controls.Add(line);
			form.Invalidate();
		}

		private OutLabel connection;
		private ConnectionLine line;
	}

}
