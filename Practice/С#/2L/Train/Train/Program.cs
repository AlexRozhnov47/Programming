using System;

namespace Train
{
    class Program
    {
        
        class doubleconvert
        {
            public string input1 = Console.ReadLine();
            public double doub1;

            public doubleconvert(string input1, double doub1)
            {
                try
                {
                    doub1 = Convert.ToDouble(input1);
                    if (doub1 < Double.MaxValue)
                    {
                        Console.WriteLine("The new value is {0}", doub1);
                    }
                    else
                    {
                        Console.WriteLine("numVal cannot be incremented beyond its current value");
                    }

                }
                catch (FormatException)
                {
                    Console.WriteLine("Input string is not a sequence of digits.");
                }
                catch (OverflowException)
                {
                    Console.WriteLine("The number cannot fit in an Int32.");
                }

            }

            // Явное преобразование типа UserInfo к string
            //public static explicit operator string(doubleconvert)
            //{
              //  return Console.WriteLine("The new value is {0}", doub2);
            //}
        }
        public class ConvertString
        {
            static void Main(string[] args)
            {
                int integer = 0;
                decimal dec;
                bool repeat = true;
                float flo;
                double doub;
                long lon;
                byte bit;
                char ch;
                while (repeat)
                {
                    Console.Write("Enter a number");
                    //doubleconvert doub2 = new doubleconvert(doub);
                    //string str = (string)doub2;
                    //Console.WriteLine(str);
                    string input = Console.ReadLine();
                    //double doub1 = int.TryParse(input,doub;
                    //char [] ch1 = input.ToCharArray();
                    //Console.WriteLine("The new value is {0}", ch1);
                    //byte d = byte.Parse(input);
                    //Console.WriteLine("Значение Byte {0}", d);

                    // ToInt32 can throw FormatException or OverflowException.
                    try
                    {
                        integer = Convert.ToInt32(input);
                        if (integer < Int32.MaxValue)
                        {
                            Console.WriteLine("Значение Integer {0}", integer);
                            ch = (char)(integer);
                            Console.WriteLine("Значение  Char (Integer) {0}", ch);
                        }
                        else
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
                    try
                    {
                        dec = Convert.ToDecimal(input);
                        if (dec < Decimal.MaxValue)
                        {
                            Console.WriteLine("Значени Decimal {0}", dec);
                            
                        }
                        else
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
                    try
                    {
                        flo = Convert.ToSingle(input);
                        if (flo < Single.MaxValue)
                        {
                            Console.WriteLine("Новое значение для типа с плавающей точкой равно =  {0}", flo);
                        }
                        else
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
                    try
                    {
                        lon = Convert.ToInt64(input);
                        if (lon < Int64.MaxValue)
                        {
                            Console.WriteLine("Значение  Long{0}", lon);
                            bit = (byte)(lon);
                            Console.WriteLine("Значение Byte (Long)  {0}", bit);
                            //ch = (char)(lon);
                            //Console.WriteLine("The new value is {0}", ch);
                        }
                        else
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
                    Console.Write("Начать заново? Y/N: ");
                    string go = Console.ReadLine();
                    if (go.ToUpper() != "Y")
                    {
                        repeat = false;
                    }
                }
            }
        }
    }
    }

