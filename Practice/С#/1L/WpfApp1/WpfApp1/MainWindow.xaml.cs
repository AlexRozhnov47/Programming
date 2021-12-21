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
    /// WPF application to read and format data
    /// Constructor for MainWindow
    /// </summary>
    public partial class MainWindow : Window
    {

        public MainWindow()
        {
            InitializeComponent();
        }
        /// <summary>
        /// Read a line of data entered by the user.
        /// Format the data and display the results in the 
        /// formattedText TextBlock control.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            string line = testInput.Text;
            line = line.Replace(",", " y:");
            line = "x:" + line;
            formattedTEXT.Text = line;
        }
        /// <summary>
        /// After the Window has loaded, read data from the standard input. 
        /// Format each line and display the results in the
        /// formattedText TextBlock control.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            // Buffer to hold a line read from the file on standard input
            string line;
            // Loop until the end of the file
            while ((line = Console.ReadLine()) != null)
            {
                // Format the data in the buffer
                line = line.Replace(",", " y:");
                line = "x:" + line + "\n";
                // Put the results into the TextBlock
                formattedTEXT.Text += line;
            }
        }

    }
}
