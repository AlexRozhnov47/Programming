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

namespace WpfApp3
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

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            string si = box1.Text;
            string si2 = box2.Text;
            int i = Convert.ToInt32(si);
            int i2 = Convert.ToInt32(si2);
            int variableMax = 2147483647;
            int i3 = variableMax;
            const int ConstantMax = int.MaxValue;
            unchecked
            {
                i = variableMax + 1;
            }
            i = unchecked(ConstantMax + 1);


            MessageBox.Show("Ошибка. Это Вирус.");
            i2 = variableMax + 1;

            // Again, the sum of 2,147,483,647 and 10 is displayed as -2,147,483,639.
            MessageBox.Show("Ошибка. Это Вирус." + i2);

            // To catch the overflow in the assignment to int2 at run time, put the
            // declaration in a checked block or expression. The following
            // statements compile but raise an overflow exception at run time.
            checked
            {
                //int2 = variableMax + 10;
            }
            //int2 = checked(variableMax + 10);

            // Unchecked sections frequently are used to break out of a checked
            // environment in order to improve performance in a portion of code
            // that is not expected to raise overflow exceptions.
            checked
            {
                // Code that might cause overflow should be executed in a checked
                // environment.
                unchecked
                {
                    // This section is appropriate for code that you are confident
                    // will not result in overflow, and for which performance is
                    // a priority.
                }
                try { char c = checked((char)(i - i2)); }
                catch (OverflowException)
                {
                    MessageBox.Show("Несовпадение преобразования.");
                }
            }
            try { i3 = checked((int)(i + i2)); }
            catch (OverflowException)
            {
                MessageBox.Show("Переполнение  преобразования.");
            }
            
            
            //const int ConstantMax = int.MaxValue;
            
        }
    }
}
