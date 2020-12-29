<<<<<<< HEAD
<<<<<<< HEAD
﻿// 29.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include<windows.h>
using namespace std;
struct Classes
{
    char history;
    char programming;
    char physics;
    char math;
};
struct Student
{
    char name[32];
    int group;
    Classes marking;
    int exams;
    bool loaner;
};
void showData(const Student Obj[], int amount)
{
    system("cls"); 
    cout << "------------------------------------------------------------------------------------------" << endl;
    cout << "Имя |\t" << "Группа |" << " История |" << " Программирование |" << " Физика  |" << " Математика |" << " Должник |" <<endl;
    cout << "------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < amount; i++)
    {   
        cout << Obj[i].name << '\t' << Obj[i].group << '\t' << '\t' << Obj[i].marking.history << '|' << '\t' << '\t'  << Obj[i].marking.programming << '|' << '\t' << '\t' <<  Obj[i].marking.physics << '|' << '\t' << '\t' << Obj[i].marking.math << '|' <<'\t' << Obj[i].loaner << endl;
    }
}
int main()
{
    int l;
    l = 0;
    setlocale(LC_ALL, "rus");
    const int n = 10;
    Student Stud[n] = {};

    for (int i = 0; i < n; i++)
    {

        cout << "Name of student";
        cin.getline(Stud[i].name, 32);
        cout << "Group";
        cin >> Stud[i].group;
        cout << "Mark by history";
        cin >> Stud[i].exams;
        if ((Stud[i].exams >= 2) && (Stud[i].exams <= 5)) {
            cin >> Stud[i].marking.history;
            if (Stud[i].exams == 2) {
                Stud[i].loaner = 1;
                l++;
            }
            else if (Stud[i].exams != 2) {
                Stud[i].loaner = 0;
            }
        }
        cout << "Mark by programming";
         cin >> Stud[i].exams; 
        if ((Stud[i].exams >= 2) && (Stud[i].exams <= 5)) {
            cin >> Stud[i].marking.programming;
            if (Stud[i].exams == 2) {
                Stud[i].loaner = 1;
                l++;
            }
            else if (Stud[i].exams != 2) {
                Stud[i].loaner = 0;
            }
        } 
        cout << "Mark by physics";
        cin >> Stud[i].exams;
        if ((Stud[i].exams >= 2) && (Stud[i].exams <= 5)) {
            cin >> Stud[i].marking.physics;
            if (Stud[i].exams == 2) {
                Stud[i].loaner = 1;
                l++;
            }
            else if (Stud[i].exams != 2) {
                Stud[i].loaner = 0;
            }
        }
        cout << "Mark by math";
        cin >> Stud[i].exams;
        if ((Stud[i].exams >= 2) && (Stud[i].exams <= 5)) {
            cin >> Stud[i].marking.math;
            if (Stud[i].exams == 2) {
                Stud[i].loaner = 1;
                l++;
            }
            else if (Stud[i].exams != 2) {
                Stud[i].loaner = 0;
            }
        }
       // do { Stud[i].loaner = 1; } while((l>=1)&&(l<=4));
            cin.get();
        
        
    }
    showData(Stud, n);
    
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
﻿// 29.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include<windows.h>
using namespace std;
struct Classes
{
    char history;
    char programming;
    char physics;
    char math;
};
struct Student
{
    char name[32];
    int group;
    Classes marking;
    int exams;
    bool loaner;
};
void showData(const Student Obj[], int amount)
{
    system("cls"); 
    cout << "------------------------------------------------------------------------------------------" << endl;
    cout << "Имя |\t" << "Группа |" << " История |" << " Программирование |" << " Физика  |" << " Математика |" << " Должник |" <<endl;
    cout << "------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < amount; i++)
    {   
        cout << Obj[i].name << '\t' << Obj[i].group << '\t' << '\t' << Obj[i].marking.history << '|' << '\t' << '\t'  << Obj[i].marking.programming << '|' << '\t' << '\t' <<  Obj[i].marking.physics << '|' << '\t' << '\t' << Obj[i].marking.math << '|' <<'\t' << Obj[i].loaner << endl;
    }
}
int main()
{
    int l;
    l = 0;
    setlocale(LC_ALL, "rus");
    const int n = 10;
    Student Stud[n] = {};

    for (int i = 0; i < n; i++)
    {

        cout << "Name of student";
        cin.getline(Stud[i].name, 32);
        cout << "Group";
        cin >> Stud[i].group;
        cout << "Mark by history";
        cin >> Stud[i].exams;
        if ((Stud[i].exams >= 2) && (Stud[i].exams <= 5)) {
            cin >> Stud[i].marking.history;
            if (Stud[i].exams == 2) {
                Stud[i].loaner = 1;
                l++;
            }
            else if (Stud[i].exams != 2) {
                Stud[i].loaner = 0;
            }
        }
        cout << "Mark by programming";
         cin >> Stud[i].exams; 
        if ((Stud[i].exams >= 2) && (Stud[i].exams <= 5)) {
            cin >> Stud[i].marking.programming;
            if (Stud[i].exams == 2) {
                Stud[i].loaner = 1;
                l++;
            }
            else if (Stud[i].exams != 2) {
                Stud[i].loaner = 0;
            }
        } 
        cout << "Mark by physics";
        cin >> Stud[i].exams;
        if ((Stud[i].exams >= 2) && (Stud[i].exams <= 5)) {
            cin >> Stud[i].marking.physics;
            if (Stud[i].exams == 2) {
                Stud[i].loaner = 1;
                l++;
            }
            else if (Stud[i].exams != 2) {
                Stud[i].loaner = 0;
            }
        }
        cout << "Mark by math";
        cin >> Stud[i].exams;
        if ((Stud[i].exams >= 2) && (Stud[i].exams <= 5)) {
            cin >> Stud[i].marking.math;
            if (Stud[i].exams == 2) {
                Stud[i].loaner = 1;
                l++;
            }
            else if (Stud[i].exams != 2) {
                Stud[i].loaner = 0;
            }
        }
       // do { Stud[i].loaner = 1; } while((l>=1)&&(l<=4));
            cin.get();
        
        
    }
    showData(Stud, n);
    
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
﻿// 29.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include<windows.h>
using namespace std;
struct Classes
{
    char history;
    char programming;
    char physics;
    char math;
};
struct Student
{
    char name[32];
    int group;
    Classes marking;
    int exams;
    bool loaner;
};
void showData(const Student Obj[], int amount)
{
    system("cls"); 
    cout << "------------------------------------------------------------------------------------------" << endl;
    cout << "Имя |\t" << "Группа |" << " История |" << " Программирование |" << " Физика  |" << " Математика |" << " Должник |" <<endl;
    cout << "------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < amount; i++)
    {   
        cout << Obj[i].name << '\t' << Obj[i].group << '\t' << '\t' << Obj[i].marking.history << '|' << '\t' << '\t'  << Obj[i].marking.programming << '|' << '\t' << '\t' <<  Obj[i].marking.physics << '|' << '\t' << '\t' << Obj[i].marking.math << '|' <<'\t' << Obj[i].loaner << endl;
    }
}
int main()
{
    int l;
    l = 0;
    setlocale(LC_ALL, "rus");
    const int n = 10;
    Student Stud[n] = {};

    for (int i = 0; i < n; i++)
    {

        cout << "Name of student";
        cin.getline(Stud[i].name, 32);
        cout << "Group";
        cin >> Stud[i].group;
        cout << "Mark by history";
        cin >> Stud[i].exams;
        if ((Stud[i].exams >= 2) && (Stud[i].exams <= 5)) {
            cin >> Stud[i].marking.history;
            if (Stud[i].exams == 2) {
                Stud[i].loaner = 1;
                l++;
            }
            else if (Stud[i].exams != 2) {
                Stud[i].loaner = 0;
            }
        }
        cout << "Mark by programming";
         cin >> Stud[i].exams; 
        if ((Stud[i].exams >= 2) && (Stud[i].exams <= 5)) {
            cin >> Stud[i].marking.programming;
            if (Stud[i].exams == 2) {
                Stud[i].loaner = 1;
                l++;
            }
            else if (Stud[i].exams != 2) {
                Stud[i].loaner = 0;
            }
        } 
        cout << "Mark by physics";
        cin >> Stud[i].exams;
        if ((Stud[i].exams >= 2) && (Stud[i].exams <= 5)) {
            cin >> Stud[i].marking.physics;
            if (Stud[i].exams == 2) {
                Stud[i].loaner = 1;
                l++;
            }
            else if (Stud[i].exams != 2) {
                Stud[i].loaner = 0;
            }
        }
        cout << "Mark by math";
        cin >> Stud[i].exams;
        if ((Stud[i].exams >= 2) && (Stud[i].exams <= 5)) {
            cin >> Stud[i].marking.math;
            if (Stud[i].exams == 2) {
                Stud[i].loaner = 1;
                l++;
            }
            else if (Stud[i].exams != 2) {
                Stud[i].loaner = 0;
            }
        }
       // do { Stud[i].loaner = 1; } while((l>=1)&&(l<=4));
            cin.get();
        
        
    }
    showData(Stud, n);
    
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
