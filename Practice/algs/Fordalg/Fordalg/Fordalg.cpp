// Fordalg.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef pair <int, int> Tovar;
double rukzak(vector <Tovar> vec, int W)
{
    vector <double> chena;
    double c = 0, k;
    for (std::size_t j = 0; j < vec.size(); j++) {
        chena.push_back(vec[j].first / vec[j].second);
    }
    for (std::size_t i = 0; i < chena.size(); i++) {
        for (std::size_t j = i + 1; j < chena.size(); j++)
            if (chena[i] < chena[j]) {
                swap(chena[i], chena[j]);
                swap(vec[i], vec[j]);
            }
    }
    while (W > 0) {
        for (std::size_t i = 0; i < chena.size(); i++) {

            if ((W - vec[i].second) >= 0)
                k = 1;
            else k = -((W - vec[i].second) / vec[i].second);
            W -= (abs(k) * vec[i].second);
            if (W < 0)break;
            c += (vec[i].first * k);
        }
    }
    return c;
}

int main() {
    int n, W;
    cin >> n;
    cin >> W;
    vector <Tovar> tovar(n);
    for (int i = 0; i < n; i++) {
        std::cin >> tovar[i].first >> tovar[i].second;
    }
    cout << fixed << rukzak(tovar, W);
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
