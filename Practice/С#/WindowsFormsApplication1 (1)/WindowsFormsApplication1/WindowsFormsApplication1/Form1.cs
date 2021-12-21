using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            
        }
        Point pnt = new Point();
        
    private void panel1_Paint(object sender, PaintEventArgs e)
        {
            
            Pen p = new Pen(Color.Orange, 1);
            e.Graphics.FillEllipse(new SolidBrush(Color.Red), pnt.X, pnt.Y, 10, 10);
            e.Graphics.FillEllipse(new SolidBrush(Color.Blue), 275, 290, 40, 40);
            //e.Graphics.DrawLine(p, pnt.X, pnt.Y, 40, 40);
        }

        private void panel1_MouseDown(object sender, MouseEventArgs e)
        {
            
            
            
        }

        private void panel1_MouseUp(object sender, MouseEventArgs e)
        {
             
        }
        double t = 0;
        private void panel1_MouseMove(object sender, MouseEventArgs e)
        {
           
        }

        private void timer1_Tick(object sender, EventArgs e)
        {

            int a = Convert.ToInt32(textBox1.Text);
            int x = (int)(a * Math.Cos(t*a) + (this.ClientRectangle.Width / 2));
            int y = (int)(a * Math.Sin(t*a) + (this.ClientRectangle.Height / 2));
            pnt = new Point(x, y);
            panel1.Invalidate();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            timer1.Start();
            t += 0.1;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            timer1.Stop();
        }
    }
}
