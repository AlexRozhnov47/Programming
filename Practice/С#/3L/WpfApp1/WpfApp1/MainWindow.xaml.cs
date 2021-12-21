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
        public static int NOD(int m, int n)//метод Евклида
        {
            int nod;
            while (m != n)
            {
                if (m > n)
                {
                    m = m - n;
                }
                else
                {
                    n = n - m;
                }
            }
            nod = n;
            return nod;
        }
        static public int Stein(int u, int v)
        {
            int k;
            // Step 1.
            // gcd(0, v) = v, because everything divides zero, 
            // and v is the largest number that divides v. 
            // Similarly, gcd(u, 0) = u. gcd(0, 0) is not typically 
            // defined, but it is convenient to set gcd(0, 0) = 0.
            if (u == 0 || v == 0)
                return u | v;
            // Step 2.
            // If u and v are both even, then gcd(u, v) = 2•gcd(u/2, v/2), 
            // because 2 is a common divisor. 
            for (k = 0; ((u | v) & 1) == 0; ++k)
            {
                u >>= 1;
                v >>= 1;
            }
            // Step 3.
            // If u is even and v is odd, then gcd(u, v) = gcd(u/2, v), 
            // because 2 is not a common divisor. 
            // Similarly, if u is odd and v is even, 
            // then gcd(u, v) = gcd(u, v/2). 
            while ((u & 1) == 0)
                u >>= 1;
            // Step 4.
            // If u and v are both odd, and u ≥ v, 
            // then gcd(u, v) = gcd((u − v)/2, v). 
            // If both are odd and u < v, then gcd(u, v) = gcd((v − u)/2, u). 
            // These are combinations of one step of the simple 
            // Euclidean algorithm, 
            // which uses subtraction at each step, and an application 
            // of step 3 above. 
            // The division by 2 results in an integer because the 
            // difference of two odd numbers is even.
            do
            {
                while ((v & 1) == 0) // Loop x
                    v >>= 1;
                // Now u and v are both odd, so diff(u, v) is even.
                // Let u = min(u, v), v = diff(u, v)/2. 
                if (u < v)
                {
                    
                v -= u;
                }
                else
                {
                    int diff = u - v;
                    u = v;
                    v = diff;
                }
                v >>= 1;
                // Step 5.
                // Repeat steps 3–4 until u = v, or (one more step) 
                // until u = 0.
                // In either case, the result is (2^k) * v, where k is 
                // the number of common factors of 2 found in step 2. 
            } while (v != 0);
            u <<= k;
            return u;
        }

        public int NOD3(int a, int b, int c) //три числа
        {
            int Nod = Math.Min(a, Math.Min(a, b));
            for (; Nod > 1; Nod--)
            {
                if (a % Nod == 0 && b % Nod == 0 && c % Nod == 0)
                    break;
            }
            return Nod;
        }
        public int NOD4(int a, int b, int c, int d)//4 числа
        {
            int Nod = Math.Min(a, Math.Min(b, c));
            for (; Nod > 1; Nod--)
            {
                if (a % Nod == 0 && b % Nod == 0 && c % Nod == 0)
                    break;
            }
            
            int Nod2 = Math.Min(b, Math.Min(c, d));
            for (; Nod2 > 1; Nod2--)
            {
                if (b % Nod2 == 0 && c % Nod2 == 0 && d % Nod2 == 0)
                    break;
            }
            while (Nod != Nod2) //субреализация эвклида для улучшения точности
            { if (Nod > Nod2) { Nod = Nod - Nod2; }
                else  { Nod2 = Nod2 - Nod; }
            }
            int Nod4 = Nod2;
            return Nod4;
        }

        public int NOD5(int a, int b, int c, int d, int e )//5 чисел
        {
            int Nod = Math.Min(a, Math.Min(b, c));
            for (; Nod > 1; Nod--)
            {
                if (a % Nod == 0 && b % Nod == 0 && c % Nod == 0)
                    break;
            }

            int Nod2 = Math.Min(b, Math.Min(c, d));
            for (; Nod2 > 1; Nod2--)
            {
                if (b % Nod2 == 0 && c % Nod2 == 0 && d % Nod2 == 0)
                    break;
            }

            int Nod3 = Math.Min(a, Math.Min(b, e));
            for (; Nod3 > 1; Nod3--)
            {
                if (a % Nod3 == 0 && b % Nod3 == 0 && e % Nod3 == 0)
                    break;
            }
            int Nod4 = Math.Min(b, Math.Min(c, e));
            for (; Nod4 > 1; Nod4--)
            {
                if (a % Nod4 == 0 && c % Nod4 == 0 && e % Nod4 == 0)
                    break;
            }
            int Nod5 = Math.Min(c, Math.Min(d, e));
            for (; Nod5 > 1; Nod5--)
            {
                if (c % Nod5 == 0 && d % Nod5 == 0 && e % Nod5 == 0)
                    break;
            }
            int Nod6 = Math.Min(d, Math.Min(a, e));
            for (; Nod > 1; Nod--)
            {
                if (d % Nod6 == 0 && a % Nod6 == 0 && e % Nod6 == 0)
                    break;
            }
            while (Nod != Nod2) //субреализация эвклида для улучшения точности
            {
                if (Nod > Nod2) { Nod = Nod - Nod2; }
                else { Nod2 = Nod2 - Nod; }
            }
            int Nod11 = Nod2;

            while (Nod3 != Nod4) //субреализация эвклида для улучшения точности шаг 2
            {
                if (Nod3 > Nod4) { Nod3 = Nod3 - Nod4; }
                else { Nod4 = Nod4 - Nod3; }
            }
            int Nod22 = Nod4;
            while (Nod5 != Nod6) //субреализация эвклида для улучшения точности шаг 3
            {
                if (Nod5 > Nod6) { Nod5 = Nod5 - Nod6; }
                else { Nod6 = Nod6 - Nod5; }
            }
            int Nod33 = Nod6;

            int Nod111 = Math.Min(Nod11, Math.Min(Nod22, Nod33));
            for (; Nod11 > 1; Nod11--)
            {
                if (a % Nod11 == 0 && b % Nod11 == 0 && c % Nod11 == 0)
                    break;
            }
            int Nodlast = Nod111;
            return Nodlast;
        }

        private void CalcClick_Click(object sender, RoutedEventArgs e)
        {
            string sm = FirstBox.Text;
            string sn = SecondBox.Text;
            string st = ThirdBox.Text;
            string sf = FourthBox.Text;
            string sh = FifthBox.Text;
            int m = Convert.ToInt32(sm);
            int n = Convert.ToInt32(sn);
            int t = Convert.ToInt32(st);
            int f = Convert.ToInt32(sf);
            int h = Convert.ToInt32(sh);
            int mm = NOD(m, n);
            int nn = Stein(m, n);
            int tt = NOD3(m, n, t);
            int ff = NOD4(m, n, t, f);
            int hh = NOD5(m, n, t, f, h);
            EuclidLabel.Content = mm.ToString();
            SteinLabel.Content = nn.ToString();
            ThreeLabel.Content = tt.ToString();
            FourLabel.Content = ff.ToString();
            FiveLabel.Content = hh.ToString();
        }

    }
}
