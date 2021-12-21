using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        static int GetRandom()
        {
            //Создание объекта для генерации чисел (с указанием начального значения)
            Random rnd = new Random();

            //Получить случайное число 
            int value = rnd.Next(0);
            int value1 = rnd.Next(999);
            if (value > value1)
            {
                value = value - value1;
            }
            else
            {
                value = value1 - value;
            }
            //Вернуть полученное значение
            return value;
        }

        
        int rand = GetRandom();
        int rand1 = GetRandom();
        private void button1_Click(object sender, EventArgs e)
        {
            int a = int.Parse(textBox1.Text);
            int b = int.Parse(textBox2.Text);
            for (int i = 0; i < b; i++)
            {
                dataGridView1.Columns.Add("", "");
            }
            for (int j = 0; j < a; j++)
            {
                dataGridView1.Rows.Add();
            }
        }
        private void button2_Click(object sender, EventArgs e)
        {
            int a = int.Parse(textBox3.Text);
            int b = int.Parse(textBox4.Text);
            for (int i = 0; i < b; i++)
            {
                dataGridView2.Columns.Add("", "");
            }
            for (int j = 0; j < a; j++)
            {
                dataGridView2.Rows.Add();
            }
        }
        private void button3_Click(object sender, EventArgs e)
        {
            int t = int.Parse(textBox1.Text);
            int y = int.Parse(textBox2.Text);
            for (int i = 0; i < y; i++)
            {
                dataGridView3.Columns.Add("", "");
            }
            for (int j = 0; j < t; j++)
            {
                dataGridView3.Rows.Add();
            }
            int n = dataGridView1.ColumnCount;
            int m = dataGridView1.RowCount;
            int q = dataGridView2.ColumnCount;
            int r = dataGridView2.RowCount;
            int[,] a = new int[n, m];
            int[,] b = new int[n, m];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    a[i, j] = Convert.ToInt32(dataGridView1[i, j].Value);
            for (int i = 0; i < q; i++)
                for (int j = 0; j < r; j++)
                    b[i, j] = Convert.ToInt32(dataGridView2[i, j].Value);
            for (int i = 0; i < dataGridView3.Rows.Count; i++)
                for (int j = 0; j < dataGridView3.Columns.Count; j++)
                    try
                    {

                        if (dataGridView3.Rows.Count >= j)
                        {
                            dataGridView3[i, j].Value = a[i, j] + b[i, j];
                        }
                        else
                        {
                            Console.WriteLine("Значаение не обработается");
                        }

                    }
                    catch (FormatException)
                    {
                        Console.WriteLine("Допущена сложная ошибка.");
                    }
                    catch (OverflowException)
                    {
                        Console.WriteLine("Переполнение значения.");
                    }
            
        }
        private void button4_Click(object sender, EventArgs e)
        {
            dataGridView3.Rows.Clear();
            dataGridView3.Columns.Clear();
            int[,] A = new int[dataGridView1.RowCount, dataGridView1.ColumnCount];
            int[,] B = new int[dataGridView2.RowCount, dataGridView2.ColumnCount];
            for (int i = 0; i < dataGridView1.ColumnCount; i++)
                for (int j = 0; j < dataGridView1.RowCount; j++)
                    A[j, i] = Convert.ToInt32(dataGridView1[i, j].Value);
            for (int i = 0; i < dataGridView2.ColumnCount; i++)
                for (int j = 0; j < dataGridView2.RowCount; j++)
                    B[j, i] = Convert.ToInt32(dataGridView2[i, j].Value);

            for (int i = 0; i < dataGridView2.ColumnCount; i++)
            {
                dataGridView3.Columns.Add("", "");
            }
            for (int j = 0; j < dataGridView1.RowCount; j++)
            {
                dataGridView3.Rows.Add();
            }

            for (int i = 0; i < dataGridView1.RowCount; i++)
            {
                for (int j = 0; j < dataGridView2.ColumnCount; j++)
                {
                    int s = 0;
                    for (int k = 0; k < dataGridView2.RowCount; k++)
                        try
                        {   if (k > dataGridView2.RowCount)
                            {
                                s += A[i, k] * B[k, j];
                            }
                            
                        }
                        catch (FormatException)
                        {
                            MessageBox.Show("Введено неправильное значение.");
                        }
                        catch (OverflowException)
                        {
                            MessageBox.Show("Переполнение значения.");
                        }
                    dataGridView3[j, i].Value = s;
                }
            }
        }
        public int MultyMatrix(int A, int B)
        {
          int C;
          C = A * B;
          return C;
        }
        private void button5_Click(object sender, EventArgs e)
        {
            dataGridView3.Rows.Clear();
            dataGridView3.Columns.Clear();

            int t = int.Parse(textBox1.Text);
            int y = int.Parse(textBox2.Text);

            for (int i = 0; i < t; i++)
            {
                dataGridView3.Columns.Add("", "");
            }
            for (int j = 0; j < y; j++)
            {
                dataGridView3.Rows.Add();
            }

            int[,] a = new int[dataGridView1.RowCount, dataGridView1.ColumnCount];

            for (int i = 0; i < dataGridView1.ColumnCount; i++)
                for (int j = 0; j < dataGridView1.RowCount; j++)
                    a[j, i] = Convert.ToInt32(dataGridView1[i, j].Value);

            for (int i = 0; i < dataGridView1.ColumnCount; i++)
                for (int j = 0; j < dataGridView1.RowCount; j++)
                    dataGridView3[j, i].Value = a[j, i];
        }
        private void button6_Click(object sender, EventArgs e)
        {
            dataGridView3.Rows.Clear();
            dataGridView3.Columns.Clear();

            int t = int.Parse(textBox1.Text);
            int y = int.Parse(textBox2.Text);

            for (int i = 0; i < t; i++)
            {
                dataGridView3.Columns.Add("", "");
            }
            for (int j = 0; j < y; j++)
            {
                dataGridView3.Rows.Add();
            }

            int[,] a = new int[dataGridView1.RowCount, dataGridView1.ColumnCount];

            for (int i = 0; i < dataGridView2.ColumnCount; i++)
                for (int j = 0; j < dataGridView2.RowCount; j++)
                    a[j, i] = Convert.ToInt32(dataGridView2[i, j].Value);

            for (int i = 0; i < dataGridView2.ColumnCount; i++)
                for (int j = 0; j < dataGridView2.RowCount; j++)
                    dataGridView3[j, i].Value = a[j, i];
        }
        private void button7_Click(object sender, EventArgs e)
        {
            int t = int.Parse(textBox1.Text);
            int y = int.Parse(textBox2.Text);
            for (int i = 0; i < y; i++)
            {
                dataGridView3.Columns.Add("", "");
            }
            for (int j = 0; j < t; j++)
            {
                dataGridView3.Rows.Add();
            }
            int n = dataGridView1.ColumnCount;
            int m = dataGridView1.RowCount;
            int w = int.Parse(textBox5.Text);
            int[,] a = new int[n, m];
            int[,] b = new int[n, m];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    a[i, j] = Convert.ToInt32(dataGridView1[i, j].Value);
            for (int i = 0; i < dataGridView1.Rows.Count; i++)
                for (int j = 0; j < dataGridView1.Columns.Count; j++)
                    dataGridView1[i, j].Value = a[i, j] * w;
        }
        private void button8_Click(object sender, EventArgs e)
        {
            int t = int.Parse(textBox3.Text);
            int y = int.Parse(textBox4.Text);
            for (int i = 0; i < y; i++)
            {
                dataGridView3.Columns.Add("", "");
            }
            for (int j = 0; j < t; j++)
            {
                dataGridView3.Rows.Add();
            }
            int n = dataGridView2.ColumnCount;
            int m = dataGridView2.RowCount;
            int w = int.Parse(textBox6.Text);
            int[,] a = new int[n, m];
            int[,] b = new int[n, m];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    a[i, j] = Convert.ToInt32(dataGridView2[i, j].Value);
            for (int i = 0; i < dataGridView2.Rows.Count; i++)
                for (int j = 0; j < dataGridView2.Columns.Count; j++)
                    dataGridView2[i, j].Value = a[i, j] * w;
        }

        private void button9_Click(object sender, EventArgs e)
        {
            dataGridView1.Rows.Clear();
            dataGridView2.Rows.Clear();
            dataGridView3.Rows.Clear();
        }

        public void button12_Click(object sender, EventArgs e)
        {
            
            try
            {
                
                int t = int.Parse(textBox1.Text);
                int y = int.Parse(textBox2.Text);
                for (int i = 0; i < y; i++)
                {
                    dataGridView3.Columns.Add("", "");
                }
                for (int j = 0; j < t; j++)
                {
                    dataGridView3.Rows.Add();
                }
                int n = dataGridView1.ColumnCount;
                int m = dataGridView1.RowCount;

                int[,] a = new int[n, m];
                int[,] b = new int[n, m];
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < m; j++)
                        if (i == j)
                        {
                            a[i, j] = 1;
                        }
                for (int i = 0; i < dataGridView1.Rows.Count; i++)
                    for (int j = 0; j < dataGridView1.Columns.Count; j++)
                     dataGridView1[i, j].Value = a[i, j];
                
                //if ()
                //{


                //}
                //else
                {
                    Console.WriteLine("Значаение не обработается");
                }
            }

              catch (FormatException)
              {
                Console.WriteLine("Введено неправильное значение.");
               }
               catch (OverflowException)
               {
                Console.WriteLine("Переполнение значения.");
               }
        }

    
            
        private void button13_Click(object sender, EventArgs e)
        {
            int t = int.Parse(textBox3.Text);
            int y = int.Parse(textBox4.Text);
            for (int i = 0; i < y; i++)
            {
                dataGridView3.Columns.Add("", "");
            }
            for (int j = 0; j < t; j++)
            {
                dataGridView3.Rows.Add();
            }
            int n = dataGridView2.ColumnCount;
            int m = dataGridView2.RowCount;

            int[,] a = new int[n, m];
            int[,] b = new int[n, m];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    if (i == j)
                    {
                        a[i, j] = 1;
                    }
            for (int i = 0; i < dataGridView2.Rows.Count; i++)
                for (int j = 0; j < dataGridView2.Columns.Count; j++)
                    dataGridView2[i, j].Value = a[i, j];
        }

        private void button14_Click(object sender, EventArgs e)
        {
            int t = int.Parse(textBox1.Text);
            int y = int.Parse(textBox2.Text);
            for (int i = 0; i < y; i++)
            {
                dataGridView3.Columns.Add("", "");
            }
            for (int j = 0; j < t; j++)
            {
                dataGridView3.Rows.Add();
            }
            int n = dataGridView1.ColumnCount;
            int m = dataGridView1.RowCount;

            int[,] a = new int[n, m];
            int[,] b = new int[n, m];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                     a[i, j] = rand1;
            for (int i = 0; i < dataGridView1.Rows.Count; i++)
                for (int j = 0; j < dataGridView1.Columns.Count; j++)
                    dataGridView1[i, j].Value = a[i, j];
        }
        private void button15_Click(object sender, EventArgs e)
        {
            int t = int.Parse(textBox3.Text);
            int y = int.Parse(textBox4.Text);
            for (int i = 0; i < y; i++)
            {
                dataGridView3.Columns.Add("", "");
            }
            for (int j = 0; j < t; j++)
            {
                dataGridView3.Rows.Add();
            }
            int n = dataGridView2.ColumnCount;
            int m = dataGridView2.RowCount;

            int[,] a = new int[n, m];
            int[,] b = new int[n, m];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    if (i != j) { a[i, j] = rand; }
                    else { a[i, j] = rand; }


            for (int i = 0; i < dataGridView2.Rows.Count; i++)
                for (int j = 0; j < dataGridView2.Columns.Count; j++)
                    dataGridView2[i, j].Value = a[i, j];
        }
    }
}
