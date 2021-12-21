using System;

namespace train2
{
    class Program
    {
        static double Pow(double a, int pow)
        {
            double result = 1;
            for (int i = 0; i < pow; i++) result *= a;
            return result;
        }

        static double SqrtN(double n, double A, double eps = 1e-27)
        {
            var x0 = A / n;
            var x1 = (1 / n) * ((n - 1) * x0 + A / Pow(x0, (int)n - 1));

            while (Math.Abs(x1 - x0) > eps)
            {
                x0 = x1;
                x1 = (1 / n) * ((n - 1) * x0 + A / Pow(x0, (int)n - 1));
            }

            return x1;
        }
        static void Main(string[] args)
        {
            string input = Console.ReadLine();
            decimal numberdecimal = decimal.Parse(input);
            double newdec = decimal.ToDouble(numberdecimal);
            Console.WriteLine(SqrtN(2, newdec));
            Console.ReadKey();
        }
    }
    
}
