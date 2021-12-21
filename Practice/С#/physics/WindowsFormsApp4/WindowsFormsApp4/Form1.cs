using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace WindowsFormsApp4
{
    public partial class Form1 : Form
    {
        Point center;//Центр вращения
        RectangleF ellipse = new RectangleF(0, 0, 100, 40);//Эллипс
        float radius = 50f;//Радиус вращения

        public Form1()
        {
            InitializeComponent();
            Paint += Form1_Paint;
            center = new Point(ClientRectangle.Width / 2, ClientRectangle.Height / 2);
            timer1.Start();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            e.Graphics.FillEllipse(Brushes.Yellow, ellipse);
            e.Graphics.DrawEllipse(Pens.Black, ellipse);
            e.Graphics.DrawLine(Pens.Red, center, new PointF(ellipse.X + ellipse.Width / 2, ellipse.Y + ellipse.Height / 2));
        }
        private void button1_Click(object sender, EventArgs e)
        {

        }
        float angle;
        private void timer1_Tick(object sender, EventArgs e)
        {
            ellipse.Location = new PointF(center.X + radius * (float)Math.Cos(angle) - ellipse.Width / 2,
                                            center.Y + radius * (float)Math.Sin(angle) - ellipse.Height / 2);
            Refresh();
            angle += (float)(Math.PI / 10f);
        }
    }
    
}