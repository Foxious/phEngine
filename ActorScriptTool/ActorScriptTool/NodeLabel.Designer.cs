namespace ActorScriptTool
{
	partial class NodeLabel
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
			this.lbName = new System.Windows.Forms.Label();
			this.pnLabel = new System.Windows.Forms.Panel();
			this.pnLabel.SuspendLayout();
			this.SuspendLayout();
			// 
			// lbName
			// 
			this.lbName.AllowDrop = true;
			this.lbName.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
						| System.Windows.Forms.AnchorStyles.Right)));
			this.lbName.AutoSize = true;
			this.lbName.Location = new System.Drawing.Point(43, 6);
			this.lbName.Name = "lbName";
			this.lbName.Size = new System.Drawing.Size(35, 13);
			this.lbName.TabIndex = 0;
			this.lbName.Text = "label1";
			// 
			// pnLabel
			// 
			this.pnLabel.AllowDrop = true;
			this.pnLabel.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
						| System.Windows.Forms.AnchorStyles.Right)));
			this.pnLabel.BackColor = System.Drawing.Color.White;
			this.pnLabel.Controls.Add(this.lbName);
			this.pnLabel.Location = new System.Drawing.Point(16, 0);
			this.pnLabel.Name = "pnLabel";
			this.pnLabel.Size = new System.Drawing.Size(120, 25);
			this.pnLabel.TabIndex = 1;
			// 
			// NodeLabel
			// 
			this.AllowDrop = true;
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.BackColor = System.Drawing.Color.White;
			this.Controls.Add(this.pnLabel);
			this.Name = "NodeLabel";
			this.Size = new System.Drawing.Size(150, 25);
			this.pnLabel.ResumeLayout(false);
			this.pnLabel.PerformLayout();
			this.ResumeLayout(false);

		}

		#endregion

		private System.Windows.Forms.Label lbName;
		protected System.Windows.Forms.Panel pnLabel;
	}
}
