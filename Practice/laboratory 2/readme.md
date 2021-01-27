<p align="center">МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ<br>
Федеральное государственное автономное образовательное учреждение высшего образования<br>
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"<br>
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ<br>
Кафедра компьютерной инженерии и моделирования</p>
<br>
<<<<<<< HEAD
<h3 align="center">Отчёт по лабораторной работе № 2<br> по дисциплине "Программирование"</h3>
<br><br>
<p>студента 1 курса группы ИВТ-б-о-202(2)<br>
Рожнова Александра Вячеславовича<br>
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

<<<<<<< HEAD
<h3 align="left">Постнановка задачи<br><h3>

</h3>
<p align="left">Разработать приложение для написания навыков в Яндекс. Диалогах и перевод результата из Json в Exel формат.  В качестве источника данных для работы с навыком используйте: ngrok.exe, Яндекс. Диалоги. В состав сервиса входит: серверное приложение на языке С++ и клиентское приложение на языке Python.<br>
<p align="left">Серверное приложение (далее Сервер) предназначенное для обработки навыка работы с сервисом "Яндекс.Диалоги". Сервер должен обеспечивать возможность получения данных в формате JSON и обрабоки информации в виде webhooks.<br>
<p align="left">Клиентское приложение должно получать запрос с сервера Яндекс.Диалогов по требованию пользователя.<br>
<h3 align="left">Ход работы</h3>
<h2 align="center">Пункт 1. Регистрация в сервисе Яндекс Диалоги</h2>
<p align="left">По первому заданию была проведена регистрация, в результате которой был создан API ключ для навыка, атакже была проведена регистрация на серверах Webhooks, демонстрируемый далее.</p>
<p>3794cff4253f41c9f6da24d524a9bd0e</p>
<p>92bb6d80-4169-45ea-963d-a1918ba68dbd@email.webhook.site</p>
<p>https://webhook.site/92bb6d80-4169-45ea-963d-a1918ba68dbd</p>
<h2 align="center">Пункт 2. Написание первой части серверного приложения на С++.</h2>
<p align="left">После был использован код для написания первой части программы, используемый в основном тексте лабораторной работы. </p>

```C++

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cpp_httplib/httplib.h>
#include <nlohmann/json.hpp>
using namespace httplib;
using json = nlohmann::json;

std::vector<std::string> webhooks;
//"url": //"https://example.com/",
std::string hello = u8R"(
    {
      "response": {
        "text": "Здравствуйте! Это мы, хороводоведы.",
        "tts": "Здравствуйте! Это мы, хоров+одо в+еды.",
        "buttons": [
            {
                "title": "Говорить",
                "payload": {},
                "hide": true
            }
        ],
        "end_session": false
      },
      "version": "1.0"
    })";

std::string str = u8R"(
	{
	  "response": {
		"text": "Дада",
		"tts": "Дада",
		"buttons": [
			{
				"title": "Добавить",
				"payload": {},
				"hide": true
			}
		],
		"end_session": false
	  },
	  "version": "1.0"
	})";
std::string str1 = u8R"(
	{
	  "response": {
		"text": "Что добавить?",
		"tts": "Что добавить?",
		"buttons": [
			{
				"title": "Огурцы",
				"payload": {},
				"hide": true
			}
		],
		"end_session": false
	  },
	  "version": "1.0"
	})";
std::string str2 = u8R"(
	{
	  "response": {
		"text": "Тогда для этого важно сфомировать режим корзины.",
		"tts": "Тогда для этого важно сфомировать режим корзины.",
		"buttons": [
			{
				"title": "Запрашиваю режим корзины",
				"payload": {},
				"hide": true
			}
		],
		"end_session": false
	  },
	  "version": "1.0"
	})";
std::string basket = u8R"(
	{
	  "response": {
		"text": "Performing basket mode",
		"tts": "Performing basket mode",
		"buttons": [
			{
				"title": "Предпринимаю очищение корзины",
				"payload": {},
				"hide": true
			}
		],
		"end_session": false
	  },
	  "version": "1.0"
	})";
std::string clebask = u8R"(
	{
	  "response": {
		"text": "Предпринимается создание корзины",
		"tts": "Предпринимается создание корзины",
		"buttons": [
			{
				"title": "Хочу добавить товар",
				"payload": {},
				"hide": true
			}
		],
		"end_session": false
	  },
	  "version": "1.0"
	})";
std::string add = u8R"(
	{
	  "response": {
		"text": "Какой вам товар",
		"tts": "Какой вам товар",
		"buttons1": [
			{
				"title": "Огурцы",
				"payload": {},
				"hide": true
			}
		],
		"end_session": false
      "buttons2": [
			{
				"title": "Картошку",
				"payload": {},
				"hide": true
			}
		],
		"end_session": false
      "buttons3": [
			{
				"title": "Лук",
				"payload": {},
				"hide": true
			}
		],
		"end_session": false
	  },
	  "version": "1.0"
	})";
std::string adquant = u8R"(
	{
	  "response": {
		"text": "Сколько добавить",
		"tts": "Сколько добавить",
		"buttons": [
			{
				"title": "10 штук",
				"payload": {},
				"hide": true
			}
		],
		"end_session": false
	  },
	  "version": "1.0"
	})";
std::string remquest = u8R"(
	{
	  "response": {
		"text": "Хотите ли вы удалить ваш товар",
		"tts": "Хотите ли вы удалить ваш товар",
		"buttons": [
			"buttons1": [
			{
				"title": "Да",
				"payload": {},
				"hide": true
			}
		],
		"end_session": false
      "buttons2": [
			{
				"title": "Нет",
				"payload": {},
				"hide": true
			}
		],
		"end_session": false
	  },
	  "version": "1.0"
	})";
std::string а = u8R"(
	{
	  "response": {
		"text": "Сколько добавить",
		"tts": "Сколько добавить",
		"buttons": [
			{
				"title": "10 штук",
				"payload": {},
				"hide": true
			}
		],
		"end_session": false
	  },
	  "version": "1.0"
	})";
std::string none = u8R"(
	{
	  "response": {
		"text": "Неверно выбрана функция",
		"tts": "Неверно выбрана функция",
		"buttons": [
			{
				"title": "Я поропробую еще",
				"payload": {},
				"hide": true
			}
		],
		"end_session": false
	  },
	  "version": "1.0"
	})";
std::string norest = u8R"(
	{
	  "response": {
		"text": "Обнуляю режим Корзина",
		"tts": "Обнуляю режим Корзина",
		"buttons": [
			{
				"title": "Запрашиваю повтор запуска режима корзины",
				"payload": {},
				"hide": true
			}
		],
		"end_session": false
	  },
	  "version": "1.0"
	})";
void gen_response(const Request& req, Response& res) {
	json yandex = json::parse(req.body);

	if (yandex["session"]["new"])
	{
		res.set_content(hello, "text/json; charset=UTF-8");
	}
	else if (yandex["request"]["nlu"]["tokens"][0] == u8"говорить")
	{
		res.set_content(str, "text/json; charset=UTF-8");

	}
	else if (yandex["request"]["nlu"]["tokens"][0] == u8"добавить")
	{
		res.set_content(str1, "text/json; charset=UTF-8");

	}
	else if (yandex["request"]["nlu"]["tokens"][0] == u8"что добавить")
		{ 
			res.set_content(str2, "text/json; charset=UTF-8");

		}
	else if (yandex["request"]["nlu"]["tokens"][0] == u8"Запрашиваю режим корзины")
	{
		res.set_content(basket, "text/json; charset=UTF-8");
	}
	else if (yandex["request"]["nlu"]["tokens"][0] == u8"")
	{
		res.set_content(none, "text/json; charset=UTF-8");
	}
	else if (yandex["request"]["nlu"]["tokens"][0] == u8"Я поропробую еще")
	{
		res.set_content(norest, "text/json; charset=UTF-8");
	}
	else if (yandex["request"]["nlu"]["tokens"][0] == u8"Запрашиваю повтор запуска режима корзины")
	{
		res.set_content(str2, "text/json; charset=UTF-8");
	}
	else if (yandex["request"]["nlu"]["tokens"][0] == u8"Performing basket mode")
	{
		res.set_content(basket, "text/json; charset=UTF-8");
	}

}





void findAndRepl(std::string& data, std::string toSearch, std::string replStr) {
	size_t pos = data.find(toSearch);
	while (pos != std::string::npos) {
		data.replace(pos, toSearch.size(), replStr);
		pos = data.find(toSearch, pos + replStr.size());
	}
}


void check_conf() {
	std::string webhooks_file_name = "webhook.json";
	std::ifstream webhooks_file(webhooks_file_name);
	std::cout << "Opening attempt file...\n";
	if (webhooks_file.is_open())
	{
		int i = 0;
		std::cout << "Released!\n";
		json j = json::parse(webhooks_file);

		for (int i = 0; i < j["webhooks"].size(); i++) {
			webhooks.push_back(j["webhooks"][i]);
		}
	}
	else
	{
		std::cout << "Failed,tried again...\n";
		std::ofstream webhooks_file(webhooks_file_name);
		std::string config = R"(
			{
			"webhooks":[]
			})";
		webhooks_file << config;
		webhooks_file.close();
		webhooks.clear();
	}
}


/*std::string open_file() {

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
*/

void gen_response_webhooks(const Request& req, Response& res) {

	std::string template_file_name = "Web_temp1.html";
	std::ifstream template_file(template_file_name);
	std::string template_str;

	if (template_file.is_open())
	{
		getline(template_file, template_str, '\0');
		template_file.close();
	}
	else
	{
		std::cout << "Error open file template.html";
	}

	if (webhooks.empty()) {
		findAndRepl(template_str, "{webhooks_list}", "");
	}
	else {
		std::string template_file_name = "Processing_block.html";
		std::ifstream template_file_block(template_file_name);
		std::string template_block;
		std::string temp;

		for (int i = 0; i < webhooks.size(); i++) {
			if (template_file_block.is_open())
			{
				getline(template_file_block, template_block, '\0');
				temp = template_block;
			}
			else {
				std::cout << "Error open file template_block.html";
				break;
			}
			findAndRepl(temp, "{Webhook URL}", webhooks[i]);

			findAndRepl(template_str, "{webhooks_list}", temp);
		}
		template_file_block.close();
		findAndRepl(template_str, "{webhooks_list}", "");
	}
	res.set_content(template_str, "text/html");

}


void gen_response_webhooks_post(const Request& req, Response& res) {
	std::string webhooks_file_name = "webhook.json";
	std::ifstream webhooks_file(webhooks_file_name);
	json j;

	if (webhooks_file.is_open())
	{
		webhooks_file >> j;
		webhooks_file.close();

		if (req.has_param("del")) {
			auto val = req.get_param_value("del");
			webhooks.erase(std::remove(webhooks.begin(), webhooks.end(), val), webhooks.end());
		}
		else if (req.has_param("set")) {
			auto val = req.get_param_value("set");
			webhooks.push_back(val);
		}
		else {
			std::cout << "Post request error";
		}
		json j2;
		j2["webhooks"] = webhooks;
		std::ofstream conf_file(webhooks_file_name);
		conf_file << j2;
		conf_file.close();
	}
	else
	{
		std::cout << "Error open file";
	}
	gen_response_webhooks(req, res);
}

int main() {
	Server svr;
	check_conf();

	svr.Post("/", gen_response);
	svr.Get("/webhooks", gen_response_webhooks);
	svr.Post("/webhooks", gen_response_webhooks_post);
	std::cout << "Start server... OK\n";
	svr.listen("localhost", 1234);
}

<h2 align="center">Пункт 4. Создание макета для приложения на Python.</h2>
<p align="left">После того,как было создано приложение на C++, было разработано приложение и на Python, которое обязуется принимать значения и записывать их в таблицу. </p>  

```python
       from flask import Flask, request
import json
import openpyxl

app = Flask(__name__)

def reload_data():
    answer = requests.get('http://localhost:5000/raw').content.decode("utf8")
    if answer:
        info = json.loads(answer)
    else:
        print('Error')

@app.route('/', methods=['POST', 'GET'])
def index():
    if request.method == 'POST':
        return "Это POST запрос"
    if request.method == 'GET':
        return "Это GET запрос"
 
if __name__ == "__main__":
    app.run()

    with open ('webhook.json') as file:
        data = json.load(file)
        for webhook in data ['webhook']:
            ID = webhook['ID']
            UserID = webhook['User ID']
            Datetime = webhook['Datetime']
            Item = webhook['Item']
            Price = webhook['Price']
    print (data['webhook reciecve'])
book = openyxl.Workbook()
sheet = book.active
sheet['A2'] = 'ID'
sheet['B2'] = 'User ID'
sheet['C2'] = 'Datetime'
sheet['D2'] = 'Item'
sheet['E2'] = 'Price'

row = 2 
for movie in data['webhook']:
    sheet[row][0] = webhook['ID']
    sheet[row][1] = webhook['User ID']
    sheet[row][2] = webhook['Datetime']
    sheet[row][3] = webhook['Item']
    sheet[row][4] = webhook['Price']
    row += 1

book.save("list.xlsx")
book.close()
```

![]("./dialog.png")

<h2 align="center">Пункт 5. Вывод из работы.</h2>
<p align="left">За время написания работы была проведена попытка научиться писать алгоритмы для сервиса Яндекс.Диалоги. Были выполнены почти все пункты работы, однако при написании каждого пункта не довел задание до конца . </p>
<br>