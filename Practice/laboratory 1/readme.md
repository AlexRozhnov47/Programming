<p align="center">МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ<br>
Федеральное государственное автономное образовательное учреждение высшего образования<br>
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"<br>
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ<br>
Кафедра компьютерной инженерии и моделирования</p>
<br>
<h3 align="center">Отчёт по лабораторной работе № 1<br> по дисциплине "Программирование"</h3>
<br><br>
<p>студента 1 курса группы ИВТ-б-о-202(2)<br>
Рожнова Александра Вячеславовича<br>
направления подготовки 09.03.01 "Информатика и вычислительная техника"</p>
<br><br>
<table>
<tr><td>Научный руководитель<br> старший преподаватель кафедры<br> компьютерной инженерии и моделирования</td>
<td>(оценка)</td>
<td>Чабанов В.В.</td>
</tr>
</table>
<br><br>
<p align="center">Симферополь, 2020</p>
<hr>

<h3 align="left">Постнановка задачи<br><h3>

</h3>
<p align="left">Разработать сервис предоставляющий данные о погоде в городе Симферополе на момент запроса.  В качестве источника данных о погоде используйте: http://openweathermap.org/. В состав сервиса входит: серверное приложение на языке С++ и клиентское приложение на языке Python.<br>
<p align="left">Серверное приложение (далее Сервер) предназначенное для обслуживания клиентских приложений и минимизации количества запросов к сервису openweathermap.org. Сервер должен обеспечивать возможность получения данных в формате JSON и виде html виджета (для вставки виджета на страницу будет использоваться iframe).<br>
<p align="left">Клиентское приложение должно иметь графический интерфейс отображающий сведения о погоде и возможность обновления данных по требованию пользователя.<br>
<h3 align="left">Ход работы</h3>
<h2 align="center">Пункт 1. Создание API ключа</h2>
<p align="left">По первым заданиям была проведена регистрация, в результате которой был создан API ключ для Симферополя, демонстрируемый далее.</p>
<p>3794cff4253f41c9f6da24d524a9bd0e</p>
<h2 align="center">Пункт 2. Обработка API ключа на Json.</h2>
<p align="left">Далее был выполнен запрос в сервис OpenWeather, который вывел Json ответ. </p>

```json
{"coord":{"lon":34.11,"lat":44.96},"weather":[{"id":803,"main":"Clouds","description":"brok0en clouds","icon":"04d"}],"base":"stations","main":{"temp":276.72,"feels_like":271.5,"temp_min":276.72,"temp_max":276.72,"pressure":1031,"humidity":79,"sea_level":1031,"grnd_level":1001},"visibility":10000,"wind":{"speed":4.68,"deg":71},"clouds":{"all":61},"dt":1605764600,"sys":{"country":"UA","sunrise":1605761214,"sunset":1605795086},"timezone":10800,"id":693805,"name":"Simferopol","cod":200}
```

<h2 align="center">Пункт 3. Написание первой части серверного приложения на С++.</h2>
<p align="left">После был использован код для написания первой части программы, используемый в основном тексте лабораторной работы. </p>

```C++

#include <iostream>
#include <fstream>
#include <string>
#include <cpp_httplib/httplib.h>
#include <nlohmann/json.hpp>
using namespace httplib;
std::ostringstream s;

std::string idkey = "3794cff4253f41c9f6da24d524a9bd0e";

using json = nlohmann::json;
json r;


int time_express_status() {
	Client time("http://worldtimeapi.org");
	std::string timerecive = "/api/timezone/Europe/Simferopol";
	auto res = time.Get(timerecive.c_str());
	if (res) {
		if (res->status == 200) {
			json j = json::parse(res->body);
			int unixtime = j["unixtime"].get<int>();
			return unixtime;
		}
		else {
			std::cout << "Status code time: " << res->status << std::endl;
		}
	}
	else {
		auto err = res.error();
		std::cout << "Error code: " << err << std::endl;
	}
}

json weather_call() {
	Client cli("http://api.openweathermap.org");
	std::string request = "/data/2.5/onecall?lat=44.957191&lon=34.11079&exclude=minutely,daily&units=metric&lang=ru&appid=" + idkey;
	auto res = cli.Get(request.c_str());
	
	if (res) {
		if (res->status == 200) {
			json j = json::parse(res->body);
			std::cout << "Response is good" << std::endl;
			return j["hourly"];
		}
		else {
			std::cout << "Status code: " << res->status << std::endl;
			return "error";
		}
	}
	else {
		auto err = res.error();
		std::cout << "Error code: " << err << std::endl;
		return "error";
	}
}

void HTMLreplacingmodule(std::string& data, std::string Searcher, std::string stringreplacer) {
	size_t pos = data.find(Searcher);
	while (pos != std::string::npos) {
		data.replace(pos, Searcher.size(), stringreplacer);
		pos = data.find(Searcher, pos + stringreplacer.size());
	}
}


int time_syncronising(int unixtime) {
	
	for (int i = 0; i < r.size(); i++) {
		int cache_time = r[i]["dt"];
		if ((unixtime - cache_time < 3600) && (unixtime - cache_time > 0)) {
			return i;
		}
	}
	return -1;
}

std::string open_file() {

	std::ifstream file("weather.html");
	if (file.is_open()) {
		std::string http_templ;
		std::getline(file, http_templ, '\0');
		file.close();
		return http_templ;
	}
	else
	{
		std::cout << "File opening error" << std::endl;
		return 0;
	}
	
}


void response_rebuild_module(const Request& req, Response& res) {

	std::string http_templ = open_file();

	int time = time_express_status();

	if (r.empty()) {
		r = weather_call();
	}

	int i = time_syncronising(time);

	int check = 1;
	while (check == 1) {
		if (i == -1) {
			r = weather_call();
			int i = time_syncronising(time);
		}
		else {
			double temp_cache = r[i]["temp"];
			int temp = round(temp_cache);

			HTMLreplacingmodule(http_templ, "{hourly[i].weather[0].description}", r[i]["weather"][0]["description"]);
			HTMLreplacingmodule(http_templ, "{hourly[i].weather[0].icon}", r[i]["weather"][0]["icon"]);
			HTMLreplacingmodule(http_templ, "{hourly[i].temp}", std::to_string(temp));

			check = 0;

			res.set_content(http_templ, "text/html");
		}
	}

}

void response_collector(const Request& req, Response& res) {

	int time = time_express_status();

	if (r.empty()) {
		r = weather_call();
	}

	int i = time_syncronising(time);

	bool check = 1;
	while (check == 1) {
		if (i == -1) {
			r = weather_call();
			int i = time_syncronising(time);
		}
		else {
			check = 0;
			double temp_cache = r[i]["temp"];
			int temp = round(temp_cache);

			json j3;
			j3["temp"] = temp;
			j3["description"] = r[0]["weather"][0]["description"];
			res.set_content(j3.dump(), "text/json");
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	Server svr;
	svr.Get("/", response_rebuild_module);
	svr.Get("/raw", response_collector);
	std::cout << "Start server... OK\n";
	svr.listen("localhost", 3000);
}
```

</p>
<h2 align="center">Пункт 4. Написание второй части серверного приложения на python.</h2>
<p align="left">После был использован код для написания второй части программы, используемый в основном тексте лабораторной работы. </p>

```python

print s;
from tkinter import *
import json
import requests


def reload_data():
    answer = requests.get('http://localhost:3000/raw').content.decode("utf8")
    if answer:
        infa = json.loads(answer)
        text3.config(text=str(infa["description"]))
        text2.config(text=str(infa["temp"]) + "°C")
    else:
        print('Error')


root = Tk()
l1 = Frame(root, bg='#0000ff')
l2 = Frame(root, bg='#ffffff')
l3 = Frame(root, bg='#0000ff')

l1.pack(fill=X)
l2.pack(fill=BOTH)
l3.pack(fill=X)

text1 = Label(l1, text="Simferopol",
              font=("Impact",
                    14, "bold"))
text1.config(bd=5, bg='#0000ff')

text2 = Label(l2, text="13",
              font=("Impact",
                    48, "bold"))
text2.config(bd=5, bg='#ffffff')

text3 = Label(l3, text="Sunny",
              font=("Arial", 10, "bold"))
text3.config(bd=5, bg='#0000ff')

text1.pack(pady=0)
text2.pack(expand=True)
text3.pack(pady=0)

reload_data()
mainloop()
```

</p>
<h2 align="center">Пункт 5. Создание макета для приложения на Python.</h2>
<p align="left">После того,как приложение на Python были написаны, был воссоздан  шаблон виджета на основве образца, представленного в тексте лабораторной работы. </p>  

![](./samplle widjet.png)

<h2 align="center">Пункт 6. Вывод из работы.</h2>
=======
<p align="left">ПОстнановка задачи<br>
<p align="left">Разработать сервис предоставляющий данные о погоде в городе Симферополе на момент запроса.  В качестве источника данных о погоде используйте: http://openweathermap.org/. В состав сервиса входит: серверное приложение на языке С++ и клиентское приложение на языке Python.<br>
<p align="left">Серверное приложение (далее Сервер) предназначенное для обслуживания клиентских приложений и минимизации количества запросов к сервису openweathermap.org. Сервер должен обеспечивать возможность получения данных в формате JSON и виде html виджета (для вставки виджета на страницу будет использоваться iframe).<br>
<p align="left">Клиентское приложение должно иметь графический интерфейс отображающий сведения о погоде и возможность обновления данных по требованию пользователя.<br>
<p align="left">Ход работы</p>
<p align="center">Пункт 1. Создание API ключа</p>
<p align="left">По первым заданиям была проведена регистрация, в результате которой был создан API ключ для Симферополя, демонстрируемый далее.</p>
<p>3794cff4253f41c9f6da24d524a9bd0e</p>
<p align="center">Пункт 2. Обработка API ключа на Json.</p>
<p align="left">Далее был выполнен запрос в сервис OpenWeather, который вывел Json ответ. </p>
<p>{"coord":{"lon":34.11,"lat":44.96},"weather":[{"id":803,"main":"Clouds","description":"brok0en clouds","icon":"04d"}],"base":"stations","main":{"temp":276.72,"feels_like":271.5,"temp_min":276.72,"temp_max":276.72,"pressure":1031,"humidity":79,"sea_level":1031,"grnd_level":1001},"visibility":10000,"wind":{"speed":4.68,"deg":71},"clouds":{"all":61},"dt":1605764600,"sys":{"country":"UA","sunrise":1605761214,"sunset":1605795086},"timezone":10800,"id":693805,"name":"Simferopol","cod":200}</p>
<p align="center">Пункт 3. Написание первой части серверного приложения на С++.</p>
<p align="left">После был использован код для написания первой части программы, используемый в основном тексте лабораторной работы. </p>
<p>#include <iostream>
#include <cpp_httplib/httplib.h>
using namespace httplib;
int main(){
  auto res = cli.Get("/api/timezone/Europe/Simferopol");
  if (res) {
    // Проверяем статус ответа, т.к. может быть 404 и другие
    if (res->status == 200) {
      std::cout << res->body << std::endl;
    }else{
      std::cout << "Status code: " << res->status << std::endl;
    }
  }
  else {
    auto err = res.error();
    std::cout << "Error code: " << err << std::endl;  
  }
} </p>
<p align="center">Пункт 4. Написание второй части серверного приложения на С++.</p>
<p align="left">После был использован код для написания второй части программы, используемый в основном тексте лабораторной работы. </p>
<p>
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
using namespace std;
​
int main()
{
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
  j2["object"].push_back({"PI", pi});
  j2["object"].push_back({"exp", 2.71});
  // Преобразуем в строку и выводим 
  std::cout << j2.dump(4);
  ofstream file(""); 
  string str;                 
  getline(file, str, '\0');   
}
</p>
<p align="center">Пункт 5. Написание третьей части серверного приложения на Python.</p>
<p align="left">После того,как приложения на C++ были написаны, можно приступить к написанию кода на Python.котрый будет основой для виджета. Для его написания пришлось воспльзоваться другим ресурсом. </p>
<p> import requests
s_city = ",RU"
city_id = 693805
appid = "3794cff4253f41c9f6da24d524a9bd0e"
try:
    res = requests.get("http://api.openweathermap.org/data/2.5/find",
                 params={'q': s_city, 'type': 'like', 'units': 'metric', 'APPID': appid})
    data = res.json()
    cities = ["{} ({})".format(d['name'], d['sys']['country'])
              for d in data['list']]
    print("city:", cities)
    city_id = data['list'][0]['id']
    print('city_id=', city_id)
except Exception as e:
    print("Exception (find):", e)
    pass
try:
    res = requests.get("http://api.openweathermap.org/data/2.5/weather",
                 params={'id': city_id, 'units': 'metric', 'lang': 'ru', 'APPID': appid})
    data = res.json()
    print("conditions:", data['weather'][0]['description'])
    print("temp:", data['main']['temp'])
    print("temp_min:", data['main']['temp_min'])
    print("temp_max:", data['main']['temp_max'])
except Exception as e:
    print("Exception (weather):", e)
    pass
  </p>
<p align="center">Пункт 6. Создание макета для приложения на Python.</p>
<p align="left">После того,как приложение на Python были написаны, был воссоздан  шаблон виджета на основве образца, представленного в тексте лабораторной работы. </p>  
<p> "C:\Users\ARdesk\Pictures\sample widjet.png"
   </p>
<p align="center">Пункт 7. Вывод из работы.</p>
<p align="left">За время написания работы была проведена попытка научиться писать простейшие веб-приложения. Были выполнены почти все пункты работы, за исключением последненго ибо не довел свое обучение до рационального предела, и не смог выполнить задание до конца. </p>
<br>