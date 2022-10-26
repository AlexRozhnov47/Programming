// ConsoleAppSIMPS1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
using namespace std;

double f5(double x) {
    return((x) / ((0.5 * sin(x) + 3 * cos(x)) * (0.5 * sin(x) + 3 * cos(x))));
}
double f10(double x) {
    return((1) / ((5 - 4 * sin(x)) + x));
}
double f15(double x) {
    return(cos(log(1/x)) + (1/(x*x*x)));
}
double f16(double x) {
    double eps = 0.001;
    return(x * exp(x)) / ((1 + x) * (1 + x));
}
double f20(double x) {
    return(acos(x/1.2) +1.44/(x*x));
}
double Prav_treug5(double a, double b, int n) {
    double h = (b - a) / n;
    double summarny = 0;
    for (int i = 1; i <= n; i++) { summarny += h * f5(a + i * h); }
    return summarny;
}double Prav_treug10(double a, double b, int n) {
    double h = (b - a) / n;
    double summarny = 0;
    for (int i = 1; i <= n; i++) { summarny += h * f10(a + i * h); }
    return summarny;
}double Prav_treug15(double a, double b, int n) {
    double h = (b - a) / n;
    double summarny = 0;
    for (int i = 1; i <= n; i++) { summarny += h * f15(a + i * h); }
    return summarny;
}
double Prav_treug16(double a, double b, int n) {
    double h = (b - a) / n;
    double summarny = 0;
    for (int i = 1; i <= n; i++) { summarny += h * f16(a + i * h); }
    return summarny;
}
double Prav_treug20(double a, double b, int n) {
    double h = (b - a) / n;
    double summarny = 0;
    for (int i = 1; i <= n; i++) { summarny += h * f20(a + i * h); }
    return summarny;
}
double Simps5(double a, double b, int n) {
    double h = (b - a) / n;
    double sumsim = f5(a)+f5(b);
    int k;
    for (int i = 1; i <= n; i++) {
        k = 2 + 2 *(i % 2);
        sumsim += k * f5(a + i * h); }
    sumsim *= h / 3;
    return sumsim;}
double Simps10(double a, double b, int n) {
    double h = (b - a) / n;
    double sumsim = f10(a) + f10(b);
    int k;
    for (int i = 1; i <= n; i++) {
        k = 2 + 2 * (i % 2);
        sumsim += k * f10(a + i * h); }
    sumsim *= h / 3;
    return sumsim;}
double Simps15(double a, double b, int n) {
    double h = (b - a) / n;
    double sumsim = f15(a) + f15(b);
    int k;
    for (int i = 1; i <= n; i++) {
        k = 2 + 2 * (i % 2);
        sumsim += k * f15(a + i * h); }
    sumsim *= h / 3;
    return sumsim;}
double Simps16(double a, double b, int n) {
    double h = (b - a) / n;
    double sumsim = f16(a) + f16(b);
    int k;
    for (int i = 1; i <= n; i++) {
        k = 2 + 2 * (i % 2);
        sumsim += k * f16(a + i * h);
    }
    sumsim *= h / 3;
    return sumsim;}
double Simps20(double a, double b, int n){
    double h = (b - a) / n;
    double sumsim = f20(a) + f20(b);
    int k;
    for (int i = 1; i <= n; i++) {
        k = 2 + 2 * (i % 2);
        sumsim += k * f20(a + i * h); }
    sumsim *= h / 3;
    return sumsim;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    double a, b;
    int n;
    cout << "Введите нижний предел интегрирования";
    a = 0.3;
    //cin >> a;
    cout << "Введите верхний предел интегрирования";
    b = 1.1;
    //cin >> b;
    cout << "Введите колличество разбиений";
    cin >> n;
    cout << "Методом правых треугольников 5" <<Prav_treug5(a,b,n) << endl;
    cout << "Методом правых треугольников 10" << Prav_treug10(a, b, n) << endl;
    cout << "Методом правых треугольников 15" << Prav_treug15(a, b, n) << endl;
    cout << "Методом правых треугольников 16" << Prav_treug16(a, b, n) << endl;
    cout << "Методом правых треугольников 20" << Prav_treug20(a, b, n) << endl;
    cout << "Методом Симпсона 5" << Simps5(a, b, n) << endl;
    cout << "Методом Симпсона 10" << Simps5(a, b, n) << endl;
    cout << "Методом Симпсона 15" << Simps5(a, b, n) << endl;
    cout << "Методом Симпсона 16" << Simps5(a, b, n) << endl;
    cout << "Методом Симпсона 20" << Simps5(a, b, n) << endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
