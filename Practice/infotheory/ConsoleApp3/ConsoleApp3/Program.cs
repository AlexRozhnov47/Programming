using System;

namespace ConsoleApp3
{
    class Program
    {
        static void Main(string[] args)
        {
            int k0 = 22;
            double k = Math.Pow(2, k0);
            Console.WriteLine(k);
            int nk = 0;
            int p;
            
            for (nk = 0; k > (Math.Pow(2, nk)) / (nk + 1); nk++)
            {
                Console.WriteLine("Число N");
                Console.WriteLine(nk);
                p = nk - k0;
                Console.WriteLine("Число P");
                Console.WriteLine(p);
            }
            do { nk++; } while (k > ((Math.Pow(2, nk) / (nk + 1))));
            p = nk - k0;
            Console.WriteLine("Итоговое Число P");
            Console.WriteLine(p);
            //if ( k <= (Math.Pow(2, n)) / (n + 1)){p = n - k0; Console.WriteLine(p);}
            int n = k0;
            int m = n;
            byte[,] matr = new byte[n, m];

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (i == j)
                    {
                        matr[i, j] = 1;
                    }
                    else
                    {
                        matr[i, j] = 0;
                    }

                }
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    Console.Write(matr[i, j].ToString() + " ");
                }
                Console.WriteLine();
            }
            
        }
    }
}
