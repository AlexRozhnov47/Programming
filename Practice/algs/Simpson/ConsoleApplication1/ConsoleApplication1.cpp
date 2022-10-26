// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include<iostream>
using namespace std;
//function that is to be integrated
float func_inte(float x) {
    return (exp(x) * x / (1 + x)*(1+x));
}
//calculating the approximations
float func_calculate(float lower_limit, float upper_limit, int
    interval_limit) {
    float value;
    float interval_size = (upper_limit - lower_limit) / interval_limit;
    float sum = func_inte(lower_limit) + func_inte(upper_limit);
    for (int i = 1; i < interval_limit; i++) {
        if (i % 3 == 0)
            sum = sum + 2 * func_inte(lower_limit + i * interval_size);
        else
            sum = sum + 3 * func_inte(lower_limit + i * interval_size);
    }
    return (0.9448305 * interval_size / 8) * sum;
}
int main() {
    int interval_limit = 100000;
    float lower_limit = 0.3;
    float upper_limit = 3.0;
    float integral_res = func_calculate(lower_limit, upper_limit, interval_limit);
    cout << integral_res << endl;
    return 0;
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
