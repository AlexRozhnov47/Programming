namespace MatModel
{
    partial class Form1
    {
        /// <summary>
        /// Требуется переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Обязательный метод для поддержки конструктора - не изменяйте
        /// содержимое данного метода при помощи редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.SkorostBox = new System.Windows.Forms.TextBox();
            this.YgolBox = new System.Windows.Forms.TextBox();
            this.RasstoyanieBox = new System.Windows.Forms.TextBox();
            this.VisotaBox = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.Start = new System.Windows.Forms.Button();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.ImageBox = new System.Windows.Forms.PictureBox();
            this.button1 = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.ImageBox)).BeginInit();
            this.SuspendLayout();
            // 
            // SkorostBox
            // 
            this.SkorostBox.Location = new System.Drawing.Point(261, 15);
            this.SkorostBox.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.SkorostBox.Name = "SkorostBox";
            this.SkorostBox.Size = new System.Drawing.Size(51, 22);
            this.SkorostBox.TabIndex = 0;
            this.SkorostBox.Text = "20";
            // 
            // YgolBox
            // 
            this.YgolBox.Location = new System.Drawing.Point(261, 47);
            this.YgolBox.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.YgolBox.Name = "YgolBox";
            this.YgolBox.Size = new System.Drawing.Size(51, 22);
            this.YgolBox.TabIndex = 1;
            this.YgolBox.Text = "30";
            // 
            // RasstoyanieBox
            // 
            this.RasstoyanieBox.Location = new System.Drawing.Point(660, 15);
            this.RasstoyanieBox.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.RasstoyanieBox.Name = "RasstoyanieBox";
            this.RasstoyanieBox.Size = new System.Drawing.Size(184, 22);
            this.RasstoyanieBox.TabIndex = 2;
            // 
            // VisotaBox
            // 
            this.VisotaBox.Location = new System.Drawing.Point(660, 47);
            this.VisotaBox.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.VisotaBox.Name = "VisotaBox";
            this.VisotaBox.Size = new System.Drawing.Size(184, 22);
            this.VisotaBox.TabIndex = 3;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(17, 18);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(148, 17);
            this.label1.TabIndex = 4;
            this.label1.Text = "Начальная скорость:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(17, 50);
            this.label2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(229, 17);
            this.label2.TabIndex = 5;
            this.label2.Text = "Угол,под которым брошено тело:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(513, 18);
            this.label3.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(134, 17);
            this.label3.TabIndex = 6;
            this.label3.Text = "Дальность полета:";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(513, 50);
            this.label4.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(108, 17);
            this.label4.TabIndex = 7;
            this.label4.Text = "Высота полета";
            // 
            // Start
            // 
            this.Start.Location = new System.Drawing.Point(885, 15);
            this.Start.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.Start.Name = "Start";
            this.Start.Size = new System.Drawing.Size(161, 43);
            this.Start.TabIndex = 9;
            this.Start.Text = "Start";
            this.Start.UseVisualStyleBackColor = true;
            this.Start.Click += new System.EventHandler(this.Start_Click);
            // 
            // timer1
            // 
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // ImageBox
            // 
            this.ImageBox.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.ImageBox.Image = global::MatModel.Properties.Resources.Planeta;
            this.ImageBox.Location = new System.Drawing.Point(16, 84);
            this.ImageBox.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.ImageBox.Name = "ImageBox";
            this.ImageBox.Size = new System.Drawing.Size(1073, 647);
            this.ImageBox.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.ImageBox.TabIndex = 8;
            this.ImageBox.TabStop = false;
            this.ImageBox.Paint += new System.Windows.Forms.PaintEventHandler(this.ImageBox_Paint);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(885, 54);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(161, 23);
            this.button1.TabIndex = 10;
            this.button1.Text = "Start 2";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1105, 746);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.Start);
            this.Controls.Add(this.ImageBox);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.VisotaBox);
            this.Controls.Add(this.RasstoyanieBox);
            this.Controls.Add(this.YgolBox);
            this.Controls.Add(this.SkorostBox);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Form1";
            this.ShowIcon = false;
            this.Text = "Model";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.ImageBox)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox SkorostBox;
        private System.Windows.Forms.TextBox YgolBox;
        private System.Windows.Forms.TextBox RasstoyanieBox;
        private System.Windows.Forms.TextBox VisotaBox;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button Start;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.PictureBox ImageBox;
        private System.Windows.Forms.Button button1;
    }
}

