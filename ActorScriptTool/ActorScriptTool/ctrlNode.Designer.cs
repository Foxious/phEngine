namespace ActorScriptTool
{
	partial class ctrlNode
	{
		/// <summary> 
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary> 
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing && (components != null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Component Designer generated code

		/// <summary> 
		/// Required method for Designer support - do not modify 
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			this.pnTitle = new System.Windows.Forms.Panel();
			this.lbName = new System.Windows.Forms.Label();
			this.pnLabelStage = new System.Windows.Forms.Panel();
			this.pnTitle.SuspendLayout();
			this.SuspendLayout();
			// 
			// pnTitle
			// 
			this.pnTitle.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
						| System.Windows.Forms.AnchorStyles.Right)));
			this.pnTitle.BackColor = System.Drawing.Color.Firebrick;
			this.pnTitle.Controls.Add(this.lbName);
			this.pnTitle.Location = new System.Drawing.Point(0, 0);
			this.pnTitle.Name = "pnTitle";
			this.pnTitle.Size = new System.Drawing.Size(114, 29);
			this.pnTitle.TabIndex = 0;
			this.pnTitle.MouseLeave += new System.EventHandler(this.OnMouseLeave);
			this.pnTitle.MouseMove += new System.Windows.Forms.MouseEventHandler(this.OnMouseMove);
			this.pnTitle.MouseDown += new System.Windows.Forms.MouseEventHandler(this.OnMouseDown);
			this.pnTitle.MouseUp += new System.Windows.Forms.MouseEventHandler(this.OnMouseUp);
			this.pnTitle.MouseEnter += new System.EventHandler(this.OnMouseEnter);
			// 
			// lbName
			// 
			this.lbName.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
						| System.Windows.Forms.AnchorStyles.Right)));
			this.lbName.AutoSize = true;
			this.lbName.BackColor = System.Drawing.Color.Transparent;
			this.lbName.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.lbName.ForeColor = System.Drawing.SystemColors.ControlText;
			this.lbName.Location = new System.Drawing.Point(9, 4);
			this.lbName.Name = "lbName";
			this.lbName.Size = new System.Drawing.Size(93, 20);
			this.lbName.TabIndex = 0;
			this.lbName.Text = "Node Name";
			this.lbName.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			this.lbName.MouseLeave += new System.EventHandler(this.OnMouseLeave);
			this.lbName.MouseMove += new System.Windows.Forms.MouseEventHandler(this.OnMouseMove);
			this.lbName.MouseDown += new System.Windows.Forms.MouseEventHandler(this.OnMouseDown);
			this.lbName.MouseUp += new System.Windows.Forms.MouseEventHandler(this.OnMouseUp);
			this.lbName.MouseEnter += new System.EventHandler(this.OnMouseEnter);
			// 
			// pnLabelStage
			// 
			this.pnLabelStage.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
						| System.Windows.Forms.AnchorStyles.Left)
						| System.Windows.Forms.AnchorStyles.Right)));
			this.pnLabelStage.Location = new System.Drawing.Point(-1, 30);
			this.pnLabelStage.Name = "pnLabelStage";
			this.pnLabelStage.Size = new System.Drawing.Size(114, 93);
			this.pnLabelStage.TabIndex = 1;
			// 
			// ctrlNode
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.BackColor = System.Drawing.Color.White;
			this.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
			this.Controls.Add(this.pnLabelStage);
			this.Controls.Add(this.pnTitle);
			this.Name = "ctrlNode";
			this.Size = new System.Drawing.Size(114, 123);
			this.pnTitle.ResumeLayout(false);
			this.pnTitle.PerformLayout();
			this.ResumeLayout(false);

		}

		#endregion

		private System.Windows.Forms.Panel pnTitle;
		private System.Windows.Forms.Label lbName;
		private System.Windows.Forms.Panel pnLabelStage;

	}
}
