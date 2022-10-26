using System;

namespace ConsoleApp2
{
    class Program
    {
        static double Rand(double b)
        {
            Random rnd = new Random();
            double value = rnd.NextDouble() * (b);
            return value;
        }

        static void Main(string[] args)
        { 
            Console.WriteLine("Hello World!");
        }
    }
}
