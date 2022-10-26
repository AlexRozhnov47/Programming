using System;
using System.Collections.Generic;
using System.Text;

namespace GradientMethods
{
    class Vector1
    {
        public double X, Y; // Две компоненты
        public Vector1(double x, double y)
        {
            X = x;
            Y = y;
        }
        public double getDim(int n) // Получить значение компоненты по индексу
        {
            if (n == 0) return X;
            if (n == 1) return Y;
            throw new Exception("Vector2.getDim");
        }
        public double Norm() // Получить норму
        {
            return Math.Sqrt(X * X + Y * Y);
        }
        public static Vector1 operator +(Vector1 v1, Vector1 v2)
        {
            return new Vector1(v1.X + v2.X, v1.Y + v2.Y);
        }
        public static Vector1 operator -(Vector1 v1, Vector1 v2)
        {
            return new Vector1(v1.X - v2.X, v1.Y - v2.Y);
        }
        public static double operator *(Vector1 v1, Vector1 v2)
        {
            return v1.X * v2.X + v1.Y * v2.Y;
        }
        public static Vector1 operator *(double n, Vector1 v)
        {
            return new Vector1(n*v.X, n*v.Y);
        }
    }
}
