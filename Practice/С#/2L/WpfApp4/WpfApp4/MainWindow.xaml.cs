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

namespace WpfApp4
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private int Matrix_1_row;
        private int Matrix_1_column;
        private int Matrix_2_row;
        private int Matrix_2_column;
        private void initializeGrid(Grid grid, double[,] matrix)
        {
            if (grid != null)
            {
                // Reset the grid before doing anything
                grid.Children.Clear();
                grid.ColumnDefinitions.Clear();
                grid.RowDefinitions.Clear();
                // Get the dimensions
                int columns = matrix.GetLength(0);
                int rows = matrix.GetLength(1);
                // Add the correct number of coumns to the grid
                for (int x = 0; x < columns; x++)
                {
                    grid.ColumnDefinitions.Add(new ColumnDefinition()
                    {
                        Width = new
                   GridLength(1, GridUnitType.Star),
                    });
                }
                for (int y = 0; y < rows; y++)
                {
                    // GridUnitType.Star - The value is expressed as a weighted proportion of available space
                    grid.RowDefinitions.Add(new RowDefinition()
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
                        grid.Children.Add(t);
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

        private void zero_click1(object sender, RoutedEventArgs e)
        {
            double[,] matrix = new double[Matrix_1_row, Matrix_1_column];
            for (int i = 0; i < Matrix_1_row; i++)
            {
                for (int j = 0; j < Matrix_1_column; j++){
                        matrix[i, j] = 0;
                                                          
                } // Matrix.initializeGrid(ref Mtr1, matrix);
            }
        }
        private void zero_click2(object sender, RoutedEventArgs e)
        {
            double[,] matrix = new double[Matrix_1_row, Matrix_1_column];
            for (int i = 0; i < Matrix_1_row; i++)
            {
                for (int j = 0; j < Matrix_1_column; j++)
                {
                    matrix[i, j] = 0;

                } // Matrix.initializeGrid(ref Mtr2, matrix);
            }
        }
        private void num_click1(object sender, RoutedEventArgs e)
        {
            double[,] matrix = new double[Matrix_1_row, Matrix_1_column];
            for (int i = 0; i < Matrix_1_row; i++)
            {
                for (int j = 0; j < Matrix_1_column; j++)
                {
                    if (i == j)
                    {
                        matrix[i, j] = 1;
                    }
                    else
                    {
                        matrix[i, j] = 0;
                    }
                } // Matrix.initializeGrid(ref Mtr2, matrix);
            }
        }

        private void num_click2(object sender, RoutedEventArgs e)
        {
            double[,] matrix = new double[Matrix_2_row, Matrix_2_column];
            for (int i = 0; i < Matrix_2_row; i++)
            {
                for (int j = 0; j < Matrix_2_column; j++)
                {
                    if (i == j)
                    {
                        matrix[i, j] = 1;
                    }
                    else
                    {
                        matrix[i, j] = 0;
                    }
                }// Matrix.initializeGrid(ref Mtr2, matrix);
            }
        }
        private void rand_click1(object sender, RoutedEventArgs e)
        {
            var rand = new Random();
            double[,] matrix = new double[Matrix_1_row, Matrix_1_column];

            for (int i=0; i < Matrix_1_row; i++)
            {
                for (int j=0; j< Matrix_1_column; j++)
                {
                    matrix[i, j] = rand.NextDouble();
                }
            }
            //Matrix.initializeGrid(ref Mtr1, matrix);
        }
        private void rand_click2(object sender, RoutedEventArgs e)
        {
            var rand = new Random();
            double[,] matrix = new double[Matrix_2_row, Matrix_2_column];

            for (int i = 0; i < Matrix_1_row; i++)
            {
                for (int j = 0; j < Matrix_1_column; j++)
                {
                    matrix[i, j] = rand.NextDouble();
                }
            }
            //Matrix.initializeGrid(ref Mtr2, matrix);
        }
        public MainWindow()
        {

            InitializeComponent();
        }
    }
}
