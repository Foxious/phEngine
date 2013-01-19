namespace ActorScriptTool
{
	partial class Form1
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

		#region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			this.inLabel1 = new ActorScriptTool.InLabel();
			this.outLabel1 = new ActorScriptTool.OutLabel();
			this.ctrlNode2 = new ActorScriptTool.CtrlNode();
			this.ctrlNode1 = new ActorScriptTool.CtrlNode();
			this.inLabel2 = new ActorScriptTool.InLabel();
			this.SuspendLayout();
			// 
			// inLabel1
			// 
			this.inLabel1.AllowDrop = true;
			this.inLabel1.BackColor = System.Drawing.Color.White;
			this.inLabel1.Location = new System.Drawing.Point(423, 61);
			this.inLabel1.Name = "inLabel1";
			this.inLabel1.Size = new System.Drawing.Size(150, 25);
			this.inLabel1.TabIndex = 3;
			// 
			// outLabel1
			// 
			this.outLabel1.AllowDrop = true;
			this.outLabel1.BackColor = System.Drawing.Color.White;
			this.outLabel1.Location = new System.Drawing.Point(118, 74);
			this.outLabel1.Name = "outLabel1";
			this.outLabel1.Size = new System.Drawing.Size(150, 25);
			this.outLabel1.TabIndex = 2;
			// 
			// ctrlNode2
			// 
			this.ctrlNode2.BackColor = System.Drawing.Color.White;
			this.ctrlNode2.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
			this.ctrlNode2.Location = new System.Drawing.Point(490, 234);
			this.ctrlNode2.Name = "ctrlNode2";
			this.ctrlNode2.NodeData = null;
			this.ctrlNode2.Size = new System.Drawing.Size(114, 123);
			this.ctrlNode2.TabIndex = 1;
			// 
			// ctrlNode1
			// 
			this.ctrlNode1.BackColor = System.Drawing.Color.White;
			this.ctrlNode1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
			this.ctrlNode1.Location = new System.Drawing.Point(240, 177);
			this.ctrlNode1.Name = "ctrlNode1";
			this.ctrlNode1.NodeData = null;
			this.ctrlNode1.Size = new System.Drawing.Size(114, 123);
			this.ctrlNode1.TabIndex = 0;
			// 
			// inLabel2
			// 
			this.inLabel2.AllowDrop = true;
			this.inLabel2.BackColor = System.Drawing.Color.White;
			this.inLabel2.Location = new System.Drawing.Point(423, 144);
			this.inLabel2.Name = "inLabel2";
			this.inLabel2.Size = new System.Drawing.Size(150, 25);
			this.inLabel2.TabIndex = 4;
			// 
			// Form1
			// 
			this.AllowDrop = true;
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(773, 442);
			this.Controls.Add(this.inLabel2);
			this.Controls.Add(this.inLabel1);
			this.Controls.Add(this.outLabel1);
			this.Controls.Add(this.ctrlNode2);
			this.Controls.Add(this.ctrlNode1);
			this.Name = "Form1";
			this.Text = "ABC - Always Be Codin\'";
			this.ResumeLayout(false);

		}

		#endregion

		private CtrlNode ctrlNode1;
		private CtrlNode ctrlNode2;
		private OutLabel outLabel1;
		private InLabel inLabel1;
		private InLabel inLabel2;






	}
}

