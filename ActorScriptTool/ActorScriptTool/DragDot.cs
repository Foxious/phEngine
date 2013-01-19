using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Drawing.Drawing2D;

namespace ActorScriptTool
{
	public partial class DragDot : UserControl
	{
		public DragDot()
		{
			InitializeComponent();
			Glowing = false;
		}

		public bool Glowing
		{
			get
			{
				return glowing;
			}
			set
			{
				glowing = value;
				Refresh();
			}
		}

		public Point Center
		{
			get
			{
				Point returnVal = new Point((Right + Left) / 2, (Bottom + Top) / 2);
				return returnVal;
			}
		}

		protected override void OnPaint(PaintEventArgs e)
		{
			base.OnPaint(e);
			if (Glowing)
			{
				DrawGlow(e.Graphics);
			}
		}

		private void DrawGlow(Graphics g)
		{
			GraphicsPath p = new GraphicsPath();
			Point [] border = {
								new Point(0			, 0			),
								new Point(Width-1	, 0			),
								new Point(Width-1	, Height-1	),
								new Point(0			, Height-1	)
							};
			p.AddPolygon(border);
			g.SmoothingMode = SmoothingMode.AntiAlias;
			g.DrawPath(new Pen(Color.Gold, 3), p);
			g.DrawPath(new Pen(Color.FromArgb(200, Color.White), 1), p);
		}

		private void OnMouseOver(object sender, EventArgs e)
		{
			Glowing = true;
		}

		private void OnMouseLeave(object sender, EventArgs e)
		{
			Glowing = false;
		}

		private bool glowing = false;

	}


}
