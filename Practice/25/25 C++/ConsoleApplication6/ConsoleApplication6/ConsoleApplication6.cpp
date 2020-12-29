<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
﻿// ConsoleApplication6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
using namespace std;
bool isSorted(int a[], int n)
{
    while (--n > 1)
        if (a[n] < a[n - 1])
            return false;
    return true;
} 
void shuffle(int a[], int n)
{
    for (int i = 0; i < n; i++)
        swap(a[i], a[rand() % n]);
}
void bogosort(int a[], int n)
{
   
    while (!isSorted(a, n))
        shuffle(a, n);
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
double double_layer_massive (int m, int n)
{
    setlocale(0, "");
    srand(unsigned(time(NULL)));
    int n, m;
    cout << "Введите размер матрицы: ";
    cin >> m >> n;
    int** A = new int* [n];
    for (int i = 0; i < n; i++)
        A[i] = new int[m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            A[i][j] = ((rand() % 10));


    cout << "here is your matrix:" << endl << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << A[i][j] << " ";
               cout << endl;
               return A[i];
    }

    cout << endl;
    for (int i = 0; i < n; i++)
        delete[] A[i];
    delete[] A;
}
int main()
{
    double b, l;
    std::vector <double> a{ 8,9,10,-1,5,12,9,4,6 };
    std::vector <double> double_layer_massive(l);
    int n = sizeof a / sizeof a[0];
    bogosort(a, n);
    printArray(a, n);
    std::cout << "Hello World!\n";
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
=======
﻿// ConsoleApplication6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
using namespace std;
bool isSorted(int a[], int n)
{
    while (--n > 1)
        if (a[n] < a[n - 1])
            return false;
    return true;
} 
void shuffle(int a[], int n)
{
    for (int i = 0; i < n; i++)
        swap(a[i], a[rand() % n]);
}
void bogosort(int a[], int n)
{
   
    while (!isSorted(a, n))
        shuffle(a, n);
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
double double_layer_massive (int m, int n)
{
    setlocale(0, "");
    srand(unsigned(time(NULL)));
    int n, m;
    cout << "Введите размер матрицы: ";
    cin >> m >> n;
    int** A = new int* [n];
    for (int i = 0; i < n; i++)
        A[i] = new int[m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            A[i][j] = ((rand() % 10));


    cout << "here is your matrix:" << endl << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << A[i][j] << " ";
               cout << endl;
               return A[i];
    }

    cout << endl;
    for (int i = 0; i < n; i++)
        delete[] A[i];
    delete[] A;
}
int main()
{
    double b, l;
    std::vector <double> a{ 8,9,10,-1,5,12,9,4,6 };
    std::vector <double> double_layer_massive(l);
    int n = sizeof a / sizeof a[0];
    bogosort(a, n);
    printArray(a, n);
    std::cout << "Hello World!\n";
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
>>>>>>> d92fc76f9dbe538603ac9ce7dbb4c932a85dd9f5
=======
﻿// ConsoleApplication6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
using namespace std;
bool isSorted(int a[], int n)
{
    while (--n > 1)
        if (a[n] < a[n - 1])
            return false;
    return true;
} 
void shuffle(int a[], int n)
{
    for (int i = 0; i < n; i++)
        swap(a[i], a[rand() % n]);
}
void bogosort(int a[], int n)
{
   
    while (!isSorted(a, n))
        shuffle(a, n);
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
double double_layer_massive (int m, int n)
{
    setlocale(0, "");
    srand(unsigned(time(NULL)));
    int n, m;
    cout << "Введите размер матрицы: ";
    cin >> m >> n;
    int** A = new int* [n];
    for (int i = 0; i < n; i++)
        A[i] = new int[m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            A[i][j] = ((rand() % 10));


    cout << "here is your matrix:" << endl << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << A[i][j] << " ";
               cout << endl;
               return A[i];
    }

    cout << endl;
    for (int i = 0; i < n; i++)
        delete[] A[i];
    delete[] A;
}
int main()
{
    double b, l;
    std::vector <double> a{ 8,9,10,-1,5,12,9,4,6 };
    std::vector <double> double_layer_massive(l);
    int n = sizeof a / sizeof a[0];
    bogosort(a, n);
    printArray(a, n);
    std::cout << "Hello World!\n";
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
>>>>>>> d92fc76f9dbe538603ac9ce7dbb4c932a85dd9f5
=======
﻿// ConsoleApplication6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
using namespace std;
bool isSorted(int a[], int n)
{
    while (--n > 1)
        if (a[n] < a[n - 1])
            return false;
    return true;
} 
void shuffle(int a[], int n)
{
    for (int i = 0; i < n; i++)
        swap(a[i], a[rand() % n]);
}
void bogosort(int a[], int n)
{
   
    while (!isSorted(a, n))
        shuffle(a, n);
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
double double_layer_massive (int m, int n)
{
    setlocale(0, "");
    srand(unsigned(time(NULL)));
    int n, m;
    cout << "Введите размер матрицы: ";
    cin >> m >> n;
    int** A = new int* [n];
    for (int i = 0; i < n; i++)
        A[i] = new int[m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            A[i][j] = ((rand() % 10));


    cout << "here is your matrix:" << endl << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << A[i][j] << " ";
               cout << endl;
               return A[i];
    }

    cout << endl;
    for (int i = 0; i < n; i++)
        delete[] A[i];
    delete[] A;
}
int main()
{
    double b, l;
    std::vector <double> a{ 8,9,10,-1,5,12,9,4,6 };
    std::vector <double> double_layer_massive(l);
    int n = sizeof a / sizeof a[0];
    bogosort(a, n);
    printArray(a, n);
    std::cout << "Hello World!\n";
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
>>>>>>> d92fc76f9dbe538603ac9ce7dbb4c932a85dd9f5
