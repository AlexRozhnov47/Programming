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
	else if (yandex["request"]["nlu"]["tokens"][0] == u8"огурцы")
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
	std::cout << "Попытка открыть файл...\n";
	if (webhooks_file.is_open())
	{
		int i = 0;
		std::cout << "Открыл!\n";
		json j = json::parse(webhooks_file);

		for (int i = 0; i < j["webhooks"].size(); i++) {
			webhooks.push_back(j["webhooks"][i]);
		}
	}
	else
	{
		std::cout << "Не получилось, создаю новый...\n";
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
