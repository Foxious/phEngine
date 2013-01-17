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
			this.ctrlNode1 = new ActorScriptTool.ctrlNode();
			this.ctrlNode2 = new ActorScriptTool.ctrlNode();
			this.SuspendLayout();
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
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(773, 442);
			this.Controls.Add(this.ctrlNode2);
			this.Controls.Add(this.ctrlNode1);
			this.Name = "Form1";
			this.Text = "ABC - Always Be Codin\'";
			this.ResumeLayout(false);

		}

		#endregion

		private ctrlNode ctrlNode1;
		private ctrlNode ctrlNode2;






	}
}

