using System;
using System.IO;

namespace HelloApp
{
    class Program
    {
        static void Main(string[] args)
        {
            
            string writePath = @"C:\Users\ARDesk\Desktop\Programming\Practice\С#\Exam\ConsoleApp1\ConsoleApp1\bin\Debug\net5.0\simple.txt";

            string text = "Adictive Invention";
            string tex1 = Console.ReadLine();
            try
            {
                using (StreamWriter sw = new StreamWriter(writePath, false, System.Text.Encoding.Default))
                {
                    sw.WriteLine(text);
                    sw.WriteLine(tex1);
                }

                using (StreamWriter sw = new StreamWriter(writePath, true, System.Text.Encoding.Default))
                {
                    sw.WriteLine("Uprwite");
                }
                Console.WriteLine("Record added to the new line to the text file");
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }

            try
            {
                using (StreamReader sr = new StreamReader("simple.txt"))
                {
                   string line;
                    while ((line = sr.ReadLine()) != null)
                    {
                       Console.WriteLine(line);
                    }
                }
            }
           catch (Exception e)
            {
                 
                Console.WriteLine("The file could not be read:");
                Console.WriteLine(e.Message);
            }
        }   
    }
}
