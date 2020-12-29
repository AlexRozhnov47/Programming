// 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
using namespace std;
<<<<<<< HEAD
=======
​
>>>>>>> d92fc76f9dbe538603ac9ce7dbb4c932a85dd9f5
int main()
{
    // Какой-то JSON в виде строки
    string str =
        R"({
  "pi": 3.141,
  "happy": true,
  "name": "Niels",
  "nothing": null,
  "answer": {
    "everything": 42
  },
  "list": [1, 0, 2],
  "object": {
    "currency": "USD",
    "value": 42.99
  }
})";
    // Парсим строку и получаем объект JSON
    json j = json::parse(str);
    // Достаём значения
    double pi = j["pi"];                 cout << "pi " << pi << endl;
    bool happy = j["happy"];             cout << "happy " << happy << endl;
    string name = j["name"];             cout << "name " << name << endl;
    double value = j["object"]["value"]; cout << "value " << value << endl;
    cout << "every " << to_string(j["answer"]["everything"].get<int>()) << endl;
    // Идём по массиву
    for (int i = 0; i < j["list"].size(); i++)
        cout << "list[" << i << "] = " << j["list"][i] << endl;
    // Пустой JSON
    json j2;
    // Заполняем разными данными
    j2["num"] = 1;
    j2["array"] = json::array();
    j2["array"].push_back(1);
    j2["array"].push_back(2);
    j2["object"] = json::object();
    j2["object"].push_back({ "PI", pi });
    j2["object"].push_back({ "exp", 2.71 });
    // Преобразуем в строку и выводим
    std::cout << j2.dump(4);
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
