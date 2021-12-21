using System;

namespace train
{
    class Program
    {
        static void Main(string[] args)
        {
            int m, n, nod;
            m = Convert.ToInt32(Console.ReadLine());
            n = Convert.ToInt32(Console.ReadLine());

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
            Console.WriteLine("НОД: " + nod);

            Console.ReadKey();
        }
    }
}
