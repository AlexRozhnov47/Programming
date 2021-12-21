using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication17
{
    public partial class Form1 : Form
    {
        private int a1 = 40, b1 = 100, a2 = 60, b2 = 150, a3 = 80, b3 = 200, a4 = 100, b4 = 250,
                    a5 = 170, b5 = 400, a6 = 210, b6 = 480, a7 = 250, b7 = 560, a8 = 290, b8 = 640,
                    a9 = 330, b9 = 720, a0 = 0, b0 = 0, a10 = 50; //Большие и малые полуоси эллипсов
        private Point center; //Центр эллипса
        double angle1 = 0, angle2 = 0, angle0 = 0, angle3 = 0, angle4 = 0, angle5 = 0, angle6 = 0, angle7 = 0, angle8 = 0, angle9 = 0, angle10 = 0;
        public Form1()
        {
            this.SetStyle(ControlStyles.AllPaintingInWmPaint |
                         ControlStyles.UserPaint |
                         ControlStyles.OptimizedDoubleBuffer |
                         ControlStyles.ResizeRedraw, true);
                         InitializeComponent();
            this.Size = new Size(1600, 900);
            center = new Point(ClientSize.Width / 2, ClientSize.Height / 2);
            this.Paint += new PaintEventHandler(Program_Paint);
        }
        void Program_Paint(object sender, PaintEventArgs e)
        {
            Graphics gr; // Создаём переменную gr типа Graphics (холст для рисования)
            gr = this.CreateGraphics(); // Инициализируем созданную переменную
            Pen MyPen; // Создаем карандш MyPen типа Pen
            MyPen = new Pen(Color.Green); // Нашему карандашу присваиваем зеленый цвет
            gr.DrawEllipse(MyPen, Rectangle.FromLTRB(center.X - b1, center.Y - a1, center.X + b1, center.Y + a1)); //Рисует эллипс
            gr.DrawEllipse(MyPen, Rectangle.FromLTRB(center.X - b2, center.Y - a2, center.X + b2, center.Y + a2)); //Рисует эллипс
            gr.DrawEllipse(MyPen, Rectangle.FromLTRB(center.X - b3, center.Y - a3, center.X + b3, center.Y + a3)); //Рисует эллипс
            gr.DrawEllipse(MyPen, Rectangle.FromLTRB(center.X - b4, center.Y - a4, center.X + b4, center.Y + a4)); //Рисует эллипс
            gr.DrawEllipse(MyPen, Rectangle.FromLTRB(center.X - b5, center.Y - a5, center.X + b5, center.Y + a5)); //Рисует эллипс
            gr.DrawEllipse(MyPen, Rectangle.FromLTRB(center.X - b6, center.Y - a6, center.X + b6, center.Y + a6)); //Рисует эллипс
            gr.DrawEllipse(MyPen, Rectangle.FromLTRB(center.X - b7, center.Y - a7, center.X + b7, center.Y + a7)); //Рисует эллипс
            gr.DrawEllipse(MyPen, Rectangle.FromLTRB(center.X - b8, center.Y - a8, center.X + b8, center.Y + a8)); //Рисует эллипс
            gr.DrawEllipse(MyPen, Rectangle.FromLTRB(center.X - b9, center.Y - a9, center.X + b9, center.Y + a9)); //Рисует эллипс
            gr.Dispose();
        }
        private void timer1_Tick(object sender, EventArgs e)
        {
            int x, y;
            //////////////////////////////////
            x = (int)(b1 * Math.Cos(angle1));
            y = (int)(a1 * Math.Sin(angle1));
            Point loc = new Point(x, y);
            //Перенос к центру вращения
            loc.Offset(center.X, center.Y);
            //Перенос к центру pictureBox
            loc.Offset(-pictureBox1.Width / 2, -pictureBox1.Height / 2);
            pictureBox1.Location = loc;
            //////////////////////////////////
            x = (int)(b0 * Math.Cos(angle0));
            y = (int)(a0 * Math.Sin(angle0));
            Point lac = new Point(x, y);
            //Перенос к центру вращения
            lac.Offset(center.X, center.Y);
            //Перенос к центру pictureBox
            lac.Offset(-pictureBox4.Width / 2, -pictureBox4.Height / 2);
            pictureBox4.Location = lac;
            /////////////////////////////////
            x = (int)(b2 * Math.Cos(angle2));
            y = (int)(a2 * Math.Sin(angle2));
            loc = new Point(x, y);
            //Перенос к центру вращения
            loc.Offset(center.X, center.Y);
            //Перенос к центру pictureBox
            loc.Offset(-pictureBox2.Width / 2, -pictureBox2.Height / 2);
            pictureBox2.Location = loc;
            x = (int)(b3 * Math.Cos(angle3));
            y = (int)(a3 * Math.Sin(angle3));
            loc = new Point(x, y);
            //Перенос к центру вращения
            loc.Offset(center.X, center.Y);
            //Перенос к центру pictureBox
            loc.Offset(-pictureBox5.Width / 2, -pictureBox5.Height / 2);
            pictureBox5.Location = loc;
            ///////////////////////////////
            x = (int)(b4 * Math.Cos(angle4));
            y = (int)(a4 * Math.Sin(angle4));
            loc = new Point(x, y);
            //Перенос к центру вращения
            loc.Offset(center.X, center.Y);
            //Перенос к центру pictureBox
            loc.Offset(-pictureBox6.Width / 2, -pictureBox6.Height / 2);
            pictureBox6.Location = loc;
            //////////////////////////////
            x = (int)(b5 * Math.Cos(angle5));
            y = (int)(a5 * Math.Sin(angle5));
            loc = new Point(x, y);
            //Перенос к центру вращения
            loc.Offset(center.X, center.Y);
            //Перенос к центру pictureBox
            loc.Offset(-pictureBox3.Width / 2, -pictureBox3.Height / 2);
            pictureBox3.Location = loc;
            //////////////////////////////
            x = (int)(b6 * Math.Cos(angle6));
            y = (int)(a6 * Math.Sin(angle6));
            loc = new Point(x, y);
            //Перенос к центру вращения
            loc.Offset(center.X, center.Y);
            //Перенос к центру pictureBox
            loc.Offset(-pictureBox7.Width / 2, -pictureBox7.Height / 2);
            pictureBox7.Location = loc;
            //////////////////////////////
            x = (int)(b7 * Math.Cos(angle7));
            y = (int)(a7 * Math.Sin(angle7));
            loc = new Point(x, y);
            //Перенос к центру вращения
            loc.Offset(center.X, center.Y);
            //Перенос к центру pictureBox
            loc.Offset(-pictureBox8.Width / 2, -pictureBox8.Height / 2);
            pictureBox8.Location = loc;
            //////////////////////////////
            x = (int)(b8 * Math.Cos(angle8));
            y = (int)(a8 * Math.Sin(angle8));
            loc = new Point(x, y);
            //Перенос к центру вращения
            loc.Offset(center.X, center.Y);
            //Перенос к центру pictureBox
            loc.Offset(-pictureBox9.Width / 2, -pictureBox9.Height / 2);
            pictureBox9.Location = loc;
            //////////////////////////////
            x = (int)(b9 * Math.Cos(angle9));
            y = (int)(a9 * Math.Sin(angle9));
            loc = new Point(x, y);
            //Перенос к центру вращения
            loc.Offset(center.X, center.Y);
            //Перенос к центру pictureBox
            loc.Offset(-pictureBox10.Width / 2, -pictureBox10.Height / 2);
            pictureBox10.Location = loc;
            /////////////////////////////
            ////////////////////////////////////////////////////////////////////////скорость  в радианах(угловая скорость)
            //angle1 -= 0.0826; Task.Delay(1); angle2 -= 0.0323; Task.Delay(1); angle3 -= 0.0185; angle4 -= 0.0105; angle5 -= 0.00167; angle6 -= 0.000675; angle7 -= 0.000318; angle8 -= 0.000120; angle9 -= 0.0000710;
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            Timer x = new Timer();
            x.Interval = 1;
            x.Start();
            x.Tick += new EventHandler(timer1_Tick);
        }
    }
}