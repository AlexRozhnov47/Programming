using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace WpfApp1
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }
        static double Pow(double a, int pow)
        {
            double result = 1;
            for (int i = 0; i < pow; i++) result *= a;
            return result;
        }

        static double SqrtN(double n, double A, double eps = 1e-27)
        {
            int c = 0;
            string output;
            var x0 = A / n;
            var x1 = (1 / n) * ((n - 1) * x0 + A / Pow(x0, (int)n - 1));

            while (Math.Abs(x1 - x0) > eps)
            {
                x0 = x1;
                x1 = (1 / n) * ((n - 1) * x0 + A / Pow(x0, (int)n - 1));
                c++;
                output = Convert.ToString(c);
                MessageBox.Show("Колличество иттераций равно =" + output + "Погрешность на ходе =" + eps);
            }
            while (c == x1)
            {
                c++;
                output = Convert.ToString(c);
                MessageBox.Show("Колличество иттераций равно =" + output + "Погрешность на ходе =" + eps);
            }

            return x1;
           
        }
        
        private void CalcButton_Click(object sender, RoutedEventArgs e)
        {
            string st = InputBox.Text;
            string sd = InputBox.Text;
            int i, count = 0;

            decimal dec;
            bool b = int.TryParse(InputBox.Text, out i);
            //if (!b)
            //{
            //    MessageBox.Show("Вы вставили неправильное значение");
            //    return;
            //}
            if (i < 0)
            {
                MessageBox.Show("Ставьте положительное число или 0");
                return;
            }
            try
            {
                dec = Convert.ToDecimal(InputBox.Text);
                if (dec < Decimal.MaxValue)
                {

                }
                else
                {
                    Console.WriteLine("Значаение не обработается");
                }

            }
            catch (FormatException)
            {
                MessageBox.Show("Введено неправильное значение");
                return;
            }
            catch (OverflowException)
            {
                MessageBox.Show("Переполнение переменной");
                return;
            }
            decimal numberdecimal = decimal.Parse(sd);
            double numberdouble = double.Parse(st);
            
            double newdec = decimal.ToDouble(numberdecimal);

            
            //double doubNewt = SqrtN(2, newdec);
            double doubNewt = SqrtN(2, newdec);
            NewtonLabel.Content = doubNewt.ToString();
            double numdoub = Math.Sqrt(numberdouble);
            while (count == doubNewt)
            {
                count++;

            }
            STLabel.Content = numdoub.ToString();
            Itr.Content = count.ToString();
        }
    }
}
