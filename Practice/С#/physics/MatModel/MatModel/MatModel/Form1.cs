using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Drawing.Imaging;

namespace MatModel
{
    public partial class Form1 : Form
    {
        double pi = Math.PI;
        double Vx, Vy;
        double g = 9.8;
        double V, a, MaxX, MaxY,dt;
        int xx;
        int yy;
        const int maxHeighWindow = 502;
        double L, S;
        double R = 0;
        //Правки
        DateTime startTime = DateTime.Now;
        //end

        public Form1()
        {
            InitializeComponent();
            SetStyle(ControlStyles.AllPaintingInWmPaint | ControlStyles.OptimizedDoubleBuffer | ControlStyles.UserPaint, true);
          
        }

        public void drawBall1(PaintEventArgs gi)
        {
            Graphics rg = gi.Graphics;
            SolidBrush mySolidBrush = new SolidBrush(Color.Gray);
            rg.FillEllipse(mySolidBrush, xx, yy, 20, 20);
        }

        public void drawBall(PaintEventArgs e)
        {
            Graphics rg = e.Graphics;
            SolidBrush mySolidBrush = new SolidBrush(Color.White);
            rg.FillEllipse(mySolidBrush, xx, yy, 20, 20);
        }
        public void beginBall()
        {
            if (yy <= maxHeighWindow)
            {
                dt = (DateTime.Now - startTime).TotalSeconds;
                xx = Convert.ToInt32(Vx * dt);
                yy = maxHeighWindow - Convert.ToInt32(Vy * dt - dt * dt * g / 2);
            }
        }

        private void Reshenie()
        {
            RasstoyanieBox.Text = "";
            VisotaBox.Text = "";
            V = Convert.ToDouble(SkorostBox.Text);
            a = Convert.ToDouble(YgolBox.Text);
            MaxX = V * V * Math.Sin(2 * pi * a / 180) / g;
            MaxY = V * V * Math.Sin(pi * a / 180) * Math.Sin(pi * a / 180) / (2 * g);
            RasstoyanieBox.Text = MaxX.ToString();
            VisotaBox.Text = MaxY.ToString();
            Vx = V * Math.Cos(pi * a / 180);
            Vy = V * Math.Sin(pi * a / 180);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                
                R = Convert.ToDouble(tbRadius.Text);
                L = 2 * 3.13 * R;
                S = 3.14 * Math.Pow(R, 2);
                tbCircleLen.Text = L.ToString();
                tbCircleArea.Text = S.ToString();
                Graphics g = pbLine.CreateGraphics();
                SolidBrush fill = new SolidBrush(Form1.DefaultBackColor);
                g.FillRectangle(fill, 0, 0, this.Width, this.Height);
                Pen pen = new Pen(Color.Black, 2);
                g.DrawEllipse(pen, 0, 0, Convert.ToInt32(R), Convert.ToInt32(R));
            }
            catch
            {
                MessageBox.Show("Введите значение!", "Error");
            }
        }

        PointF VirtualToAbsolute(double x, double y)
        {
            return new PointF((float)x * Width / 2, -(float)y * Height / 2);
        }
        private void Start_Click(object sender, EventArgs e)
        {
            if (SkorostBox.Text != "" && YgolBox.Text != "")
            {
                a = Convert.ToDouble(YgolBox.Text);
                if (a <= 90)
                {
     
                    var alpha = pi * a / 180;
                    startTime = DateTime.Now;
                    V = Convert.ToDouble(SkorostBox.Text);
                    Vx = V * Math.Cos(alpha);
                    Vy = V * Math.Sin(alpha);
                    var t = Vy / g;
                    MaxY = t * t / (g * 2);
                    MaxX = 2 * t * Vx;
                    xx = 0;
                    yy = maxHeighWindow;
                    timer1.Enabled = true;
                    timer1.Interval = 10;
                    Reshenie();
                }
                else
                {
                    MessageBox.Show("Угол не должен быть больше 90 градусов!");
                }
            }
            else
            {
                MessageBox.Show("Введите данные!");
            }
        }
        private void timer1_Tick(object sender, EventArgs e)
        {
            beginBall();
            ImageBox.Invalidate();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
          //  ImageBox.Image = new Bitmap(@"Planeta.jpg");
        }

        private void ImageBox_Paint(object sender, PaintEventArgs e)
        {
            drawBall(e);
            drawBall1(gi);
        }
    }
}