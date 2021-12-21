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
        private void initializeGrid(Grid grid_1, double[,] matrix)
        {
            if (grid_1 != null)
            {
                // Reset the grid before doing anything
                grid_1.Children.Clear();
                grid_1.ColumnDefinitions.Clear();
                grid_1.RowDefinitions.Clear();
                // Get the dimensions
                int columns = matrix.GetLength(0);
                int rows = matrix.GetLength(1);
                // Add the correct number of coumns to the grid
                for (int x = 0; x < columns; x++)
                {
                    grid_1.ColumnDefinitions.Add(new ColumnDefinition()
                    {
                        Width = new
                   GridLength(1, GridUnitType.Star),
                    });
                }
                for (int y = 0; y < rows; y++)
                {
                    // GridUnitType.Star - The value is expressed as a weighted proportion of available space
                    grid_1.RowDefinitions.Add(new RowDefinition()
                    {
                        Height = new
                   GridLength(1, GridUnitType.Star),
                    });
                }
         // Fill each cell of the grid with an editable TextBox containing the value from the matrix 
 for (int x = 0; x < columns; x++)
                {
                    for (int y = 0; y < rows; y++)
                    {
                        double cell = (double)matrix[x, y];
                        TextBox t = new TextBox();
                        t.Text = cell.ToString();
                        t.VerticalAlignment = System.Windows.VerticalAlignment.Center;
                        t.HorizontalAlignment = System.Windows.HorizontalAlignment.Center;
                        t.SetValue(Grid.RowProperty, y);
                        t.SetValue(Grid.ColumnProperty, x);
                        grid_1.Children.Add(t);
                    }
                }
            }
        }
        private void getValuesFromGrid(Grid grid, double[,] matrix)
        {
            int columns = grid.ColumnDefinitions.Count;
            int rows = grid.RowDefinitions.Count;
            // Iterate over cells in Grid, copying to matrix array
            for (int c = 0; c < grid.Children.Count; c++)
            {
                TextBox t = (TextBox)grid.Children[c];
                int row = Grid.GetRow(t);
                int column = Grid.GetColumn(t);
                matrix[column, row] = double.Parse(t.Text);
            }
        }
        public MainWindow()
        {
            InitializeComponent();
        }

        private void Addbutton_Click(object sender, RoutedEventArgs e)
        {

        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {

        }
    }
}
