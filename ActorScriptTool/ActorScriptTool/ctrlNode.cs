using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;

using System.Runtime.InteropServices;
using System.Drawing.Drawing2D;


namespace ActorScriptTool
{
	public class ConnectionLine : UserControl
	{
		public int LineWidth
		{
			get
			{
				return width;
			}
			set
			{
				width = value;
				clip = BuildClipPoly();
			}
		}
		public Color LineColor
		{
			get
			{
				return pen.Color;
			}
			set
			{
				pen.Color = Color.FromArgb(180, value);
			}
		}
		public Point Start
		{
			get
			{
				return start;
			}
			set
			{
				start = value;
				CalcLocation();
				clip = BuildClipPoly();
			}
		}
		public Point End
		{
			get
			{
				return end;
			}
			set
			{
				end = value;
				CalcLocation();
				clip = BuildClipPoly();
			}
		}
		public ConnectionLine()
		{
			this.BringToFront();
			this.SetStyle(ControlStyles.AllPaintingInWmPaint | ControlStyles.UserPaint | ControlStyles.OptimizedDoubleBuffer | ControlStyles.ResizeRedraw | ControlStyles.SupportsTransparentBackColor, true);
			//this.BackColor = Color.Transparent;
		}

		protected override void OnPaint(PaintEventArgs e)
		{
			base.OnPaint(e);
			DrawLine(e.Graphics);
		}

		private void DrawLine(System.Drawing.Graphics g)
		{
			pen.Color = LineColor;
			this.BringToFront();
			using (GraphicsPath p = new GraphicsPath())
			{
				p.AddPolygon(clip);
				//p.AddLine(lStart.X-HalfWidth, lStart.Y-HalfWidth, 
				//g.DrawPath(Pens.Red, p);
				this.Region = new Region(p);
				g.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.AntiAlias;
				g.DrawLine(pen, lStart, lEnd);
			}
		}

		private Point[] BuildClipPoly()
		{
			Point[] clipPoly = {
									new Point(lStart.X-HalfWidth,	lStart.Y-HalfWidth),
									new Point(lStart.X+HalfWidth,	lStart.Y+HalfWidth),
									new Point(lEnd.X+HalfWidth,		lEnd.Y+HalfWidth),
									new Point(lEnd.X-HalfWidth,		lEnd.Y-HalfWidth)
								};
			//System.Diagnostics.Debug.WriteLine("-------- NEW POLYGON --------");
			//System.Diagnostics.Debug.WriteLine(clipPoly[0]);
			//System.Diagnostics.Debug.WriteLine(clipPoly[1]);
			//System.Diagnostics.Debug.WriteLine(clipPoly[2]);
			//System.Diagnostics.Debug.WriteLine(clipPoly[3]);
			return clipPoly;
		}

		private void CalcLocation()
		{
			// make an AABB of start and end
			Point min = new Point(Math.Min(start.X - HalfWidth, end.X - HalfWidth), Math.Min(start.Y - HalfWidth, end.Y - HalfWidth));
			Point max = new Point(Math.Max(start.X + HalfWidth, end.X + HalfWidth), Math.Max(start.Y + HalfWidth, end.Y + HalfWidth));


			Location = min;
			Size = new Size(max.X - min.X,  max.Y - min.Y);
			lStart = new Point(start.X - min.X, start.Y - min.Y);
			lEnd = new Point(end.X - min.X, end.Y - min.Y);

		}

		private int HalfWidth
		{
			get
			{
				return LineWidth / 2 > 1 ? Width/2 : 1;
			}
		}

		private Point start;
		private Point end;
		private Point lStart;
		private Point lEnd;
		private Pen pen = new Pen(Color.FromArgb(180, Color.Black));
		private Point[] clip;
		private int width = 2;
	}

	[System.ComponentModel.Category("Custom")]
	public partial class CtrlNode : UserControl
	{
		public CtrlNode()
		{
			InitializeComponent();
		}

		public List<Label> inParamLabels	= new List<Label>();
		public List<Label> outParamLabels	= new List<Label>();

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

					outParamLabels.Add(data);
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

					inParamLabels.Add(data);
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

		public void ConnectParam(int outParam, CtrlNode node, int inParam)
		{
			//ConnectionLine newLine = new ConnectionLine();
			//newLine.start = new Point(this.Right, this.Top);
			//newLine.end = new Point(node.Left, node.Top);
			
			//lines.Add(newLine);
			//this.Parent.Controls.Add(newLine);
			//(this.Parent as Form1).lines.Add(newLine);
			//this.Parent.Invalidate();
			//newLine.Invalidate();
		}


		// PRIVATE //////////////////////////////////////////////////////////////////////
		private Node _node;
		private int labelHeight = 25;
		private bool isDragging = false;
		private Point mouseDragStart;
		private List<ConnectionLine> lines	= new List<ConnectionLine>();

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
				int newX = e.X - mouseDragStart.X;
				int newY = e.Y - mouseDragStart.Y;
				this.Left += newX;
				this.Top += newY;
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
