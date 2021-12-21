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

namespace WpfApp2
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
        static string DecimalToBinary(uint decimalNumber)
        {
            var binaryNumber = string.Empty;
            while (decimalNumber > 0)
            {
                binaryNumber = (decimalNumber % 2) + binaryNumber;
                decimalNumber /= 2;
            }

            return binaryNumber;
        }
        private void convertButton_Click(object sender, RoutedEventArgs e)
        {
            int i;
            
            bool b = int.TryParse(inputTextBox.Text, out i);
            if (!b)
            {
                MessageBox.Show("Вы вставили неправильное значение");
                return;
            }
            if (i < 0)
            {
                MessageBox.Show("Ставьте положительное число или 0");
                return;
            }
            
            string vs = inputTextBox.Text;
            int h = Convert.ToInt32(inputTextBox.Text);
            HexLabel.Content = Convert.ToString(i, 16);
            int o = Convert.ToInt32(inputTextBox.Text);
            OctLabel.Content = Convert.ToString(i, 8);
            var v = uint.Parse(vs);
            var binarynum = DecimalToBinary(v);
            binaryLabel.Content = binarynum.ToString();

        }
    }
}
