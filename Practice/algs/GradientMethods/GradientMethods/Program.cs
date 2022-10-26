using System;
using System.Data;
using System.Linq;

namespace GradientMethods
{
    class Program
    {
        
        public static double function(double [] X)//значение целевой функции в точке
        {
            //double F = 2 * Math.Pow(X[0], 2) + X[0] * X[1] + Math.Pow(X[1], 2);
            //double F = 100 * Math.Pow(X[0], 2) + Math.Pow(X[1], 2);
            //double F = 4 * Math.Pow(X[0] - 5, 2) + Math.Pow(X[1] - 6, 2);
            //double F = Math.Pow(X[0] + 1, 2) + Math.Pow(X[1],2);
            double F= Math.Pow((Math.Pow(X[0], 2) + X[1] - 11), 2) + Math.Pow(X[0] + (Math.Pow(X[1], 2) - 7), 2);
            return F;
        }
        public static double f(Vector1 V)//значение целевой функции (вектор)
        {
            //return 100 * V.X * V.X + V.Y * V.Y;
            return Math.Pow(V.X + 1, 2) + Math.Pow(V.Y, 2);
            //return 2 * V.X * V.X + V.X * V.Y + V.Y * V.Y;
           // return 4 * Math.Pow(V.X - 5, 2) + Math.Pow(V.Y - 6, 2);
        }
        public static double dfunction (double[] X, int a)//градиент в точке 
        {

            double dF = 0;
            switch(a)
            {
                case 1:
                    //dF = 8 * X[0] - 40;
                    //dF = 4 * X[0] + X[1];
                    //dF = 200 * X[0];
                    //dF = 2 * X[0] + 2;
                    dF = 4 * Math.Pow(X[0], 3) - 42 * X[0] + 2 * Math.Pow(X[1], 2) + 4*X[0] * X[1] - 14;
                    break;
                case 2:
                    //dF = 2 * X[1] - 12;
                    //dF = X[0] + 2 * X[1];
                    //dF = 2 * X[1];
                    //dF = 2 * X[1];
                    dF = 2 * Math.Pow(X[0], 2) + 4 * X[0] * X[1] + 4 * Math.Pow(X[1], 3) - 26 * X[1] - 22;
                    break;
            }
            return dF;
        }
        public static double GradF(double [] X)
        {
            return Math.Pow((Math.Pow(dfunction(X, 1), 2) + (Math.Pow(dfunction(X, 2), 2))), 0.5);
            
        }

        public static Vector1 GrF(Vector1 v)
        {
            return new Vector1(2 * v.X + 2, 2 * v.Y);
            //return new Vector1(200* v.X, 2 * v.Y);
            //return new Vector1(4.0 * v.X + v.Y, v.X + 2*v.Y);
            //return new Vector1(8 * v.X - 40, 2 * v.Y - 12);
        }


        public static Vector1 MH(Vector1 v)
        {
            double[] MH1 = { 1.0 / 2.0, 0.0, 0.0, 1.0 / 2.0 };
            //double[] MH1 = { 1.0 / 200.0, 0.0, 0.0, 1.0 / 2.0 };
            //double[] MH1 = { 1.0 / 8.0, 0.0, 0.0, 1.0 / 2.0 };
            //double[] MH1 = { 2.0 / 7.0, -1.0 / 7.0, -1.0 / 7.0, 4.0 / 7.0 };
            return new Vector1(MH1[0] * GrF(v).X + MH1[1] * GrF(v).Y, MH1[2] * GrF(v).X + MH1[3] * GrF(v).Y);
        }
        private static double MPD(Vector1 v, Vector1 s)
        {
            double a = 0, b = 100;
            double eps = 0.005, del = 0.002;
            double alpha, betta;

            double FV(double h) { return 100 * Math.Pow(v.X + h * s.X, 2) + Math.Pow(v.Y + h * s.Y, 2); };
           // double FV(double h) { return 4 * Math.Pow(v.X + h * s.X - 5, 2) + Math.Pow(v.Y + h * s.Y - 6, 2); };
            while ((b - a) > eps) 
            {
                alpha = ((a + b) / 2) - del;
                betta = ((a + b) / 2) + del;

                if (FV(alpha) < FV(betta))
                    b = betta;
                else
                    a = alpha;
            }
            return (a + b) / 2;
        }


        #region Метод половинного деления
        public static double MPD(double[] x, double[] s)
        {
            double a = 0, b = 100;
            double eps = 0.0005, del = 0.0001;
            double alpha, betta;

            //double F(double h) { return 4 * (Math.Pow((x[0] + h * s[0] - 5), 2)) + Math.Pow((x[1] + h * s[1] - 6), 2); };
            //double F(double h) { return 2 * (Math.Pow((x[0] + h * s[0]), 2)) + (x[0] + h * s[0]) * (x[1] + h * s[1]) + (x[1] + Math.Pow((h * s[1]), 2)); };
            //double F(double h) { return 100 * Math.Pow(x[0]+h*s[0], 2) + Math.Pow(x[1]+h*s[1], 2); };
            //double F(double h) { return Math.Pow(x[0] + h * s[0] + 1, 2) + Math.Pow(x[1] + h * s[1], 2); };
            double F(double h) { return Math.Pow(Math.Pow(x[0] + h * s[0], 2) + (x[1] + h * s[1]) - 11, 2) + Math.Pow((x[0] + h * s[0]) + Math.Pow(x[1] + h * s[1], 2) - 7, 2); };
            {
                while ((b - a) > eps)
                {
                    //Шаг1
                    alpha = ((a + b) / 2) - del;
                    betta = ((a + b) / 2) + del;

                    //Шаг2
                    if (F(alpha) < F(betta))
                        b = betta;
                    else
                        a = alpha;
                }
            }
            return (a + b) / 2;
            //Console.WriteLine("Половинного деления \t{0:0.00} \t{1:0.00} \t{2}", (a + b) / 2, F((a + b) / 2), k);
        }

        #endregion

        #region Метод наискорейшего спуска
        public static void QuickDown(double[] X, double epsilon)
        {
            double lambda = 0;
            int k = 1;
            double[] S = new double[2] { 0, 0 };
            while(GradF(X)>=epsilon)
            {
                S[0] = -dfunction(X, 1); 
                S[1] = -dfunction(X, 2);
                lambda = MPD(X, S);
                X[0] = X[0] + lambda * S[0];
                X[1] = X[1] + lambda * S[1];
                k++;
            }
            Console.WriteLine($"Метод наискорейшего спуска        x1={X[0]:0.0} x2={X[1]:0.0} f={function(X):0.00} k={k}");
        }
        #endregion

       /* private static void soprGRAD(Vector1 X, double epsilon)
        {
            double lambda = 0;
            double betta = 0;
            int k = 1, n = 2;
            int[] I = new int[5000];
            I[0] = 0;
            I[1] = n;
            for (int i = 2; i < 5000; i++)
                I[i] = I[1] * i;

            Vector1 X1;
            Vector1 S = -1 * GrF(X);
            while (true)
            {
                lambda = MPD(X, S);

                X1 = new Vector1(X.X + lambda * S.X, X.Y + lambda * S.Y);

                if(GrF(X).Norm() >= epsilon)
                {
                    Console.WriteLine($"Метод сопряженных градиентов  x1={X.X:0.000000} x2={X.Y:0.000000} f={f(X):0.000000} k={k}");
                    break;
                }
                if(I.Contains(k+1))
                {
                    betta = 0;
                }
                else
                {
                    betta = (GrF(X1) * (GrF(X1) - GrF(X))) / (GrF(X) * GrF(X));
                }
                S=new Vector1(-GrF(X))
            }
        }*/
        #region Метод сопряженных градиентов
        private static void SoprGrad(double[] X, double epsilon)
        {
            double lambda = 0;
            double[] S = new double[2];
            int k = 1, n = 2;
            int[] I = new int[5000];
            I[0] = 0;
            I[1] = n;
            for (int i = 2; i < 5000; i++)
                I[i] = I[1] * i;

            double betta = 0;
            double[] X1 = new double[2];
            S[0] = -dfunction(X, 1);
            S[1] = -dfunction(X, 2);
            while (true)
            {
                
                lambda = MPD(X, S);
               
                X1[0] = X[0] + lambda * S[0];
                X1[1] = X[1] + lambda * S[1];

                if (GradF(X1) < epsilon)
                {
                    Console.WriteLine($"Метод сопряженных градиентов      x1={X1[0]:0.00} x2={X1[1]:0.00} f={function(X1):0.00} k={k}");
                    break;
                }

                if (I.Contains(k + 1))
                {
                   // Console.Write("1");
                    betta = 0;
                }
                else
                {
                   // Console.Write("1");
                    betta = ((dfunction(X1, 1) * dfunction(X1, 1) + dfunction(X1, 2) * dfunction(X1, 2)) - (dfunction(X1, 1) * dfunction(X, 1) + dfunction(X1, 2) * dfunction(X, 2))) / (Math.Pow(dfunction(X, 1), 2) + Math.Pow(dfunction(X, 2), 2));
                        //(dfunction(X1, 1) * (dfunction(X1, 1) - dfunction(X, 1)) + dfunction(X1, 2) * (dfunction(X1, 2) - dfunction(X, 2))) / (Math.Pow(dfunction(X, 1), 2) + Math.Pow(dfunction(X, 2), 2));
                }

                S[0] = -dfunction(X1, 1) + betta * S[0];
                S[1] = -dfunction(X1, 2) + betta * S[1];

                X[0] = X1[0];
                X[1] = X1[1];
                k++;
            }
        }

        #endregion

        #region Метод покоординатного спуска
        public static void CoordinateDown(Vector1 X, double epsilon)
        {
            int n = 2;
            Vector1[] e = { new Vector1(1.0, 0.0), new Vector1(0.0, 1.0) };
            double lambda = 1;
            double alfa = 1;
            Vector1 Xtmp;
            Vector1 Y1 = X;
            int k = 1, j = 0;
            while(true)
            {
                if(f(Y1+lambda*e[j])<f(Y1))
                {
                    Y1 = Y1 + lambda * e[j];
                }
                else if(f(Y1-lambda*e[j])<f(Y1))
                {
                    Y1 = Y1 - lambda * e[j];
                }

                //шаг2
                if(j<n-1)
                {
                    j++;
                    continue;
                }
                if(f(Y1)<f(X))//шаг3
                {
                    Xtmp = X;
                    X = Y1;
                    Y1 = X + alfa*(X - Xtmp);
                    k++;
                    j = 0;
                    continue;
                }
                else//шаг4
                {
                    if(lambda<=epsilon)
                    {
                        Console.WriteLine($"Метод покоординатного спуска      x1={X.X:0.00} x2={X.Y:0.00} f={f(X):0.00} k={k}");
                        break;
                    }
                    else
                    {
                        lambda = lambda / 2;
                        Y1 = X;
                        k++;
                        j = 0;
                        continue;
                    }
                }

                
            }

        }
        #endregion

        #region Метод Ньютона
        public static void Newton(Vector1 X, double epsilon)
        {
            int k = 1;
            int M = 20;
            Vector1 Xtmp;
                int step = 0;
            while (GrF(X).Norm() > epsilon)
            {
                if (k >= M)
                    break;
                //положительная определенность
                Xtmp = X;
                X = X - MH(X);
                if((X-Xtmp).Norm()<epsilon && Math.Abs(f(X)-f(Xtmp))<epsilon)
                {
                    step++;
                    if (step == 2)
                        break;
                }
                else
                    step = 0;
                k++;
                
            }
            Console.WriteLine($"Метод Ньютона                     x1={X.X:0.00} x2={X.Y:0.00} f={f(X):0.00} k={k}");
        }
        #endregion
        static void Main(string[] args)
        {
            Console.WriteLine("Введите эпсилон и координаты начальной точки x1:");
            string str = Console.ReadLine();
            string[] mas = str.Split(' ');
            double epsilon = Convert.ToDouble(mas[0]);
            double[] X = new double[2] { Convert.ToDouble(mas[1]), Convert.ToDouble(mas[2]) };
            QuickDown(X, epsilon);
            X = new double[2] { Convert.ToDouble(mas[1]), Convert.ToDouble(mas[2]) };
            Vector1 X1 = new Vector1(Convert.ToDouble(mas[1]), Convert.ToDouble(mas[2]));
            SoprGrad(X, epsilon);
           // CoordinateDown(X1, epsilon);
            Vector1 X2 = new Vector1(Convert.ToDouble(mas[1]), Convert.ToDouble(mas[2]));
            //Newton(X2, epsilon);
        }
    }
}
