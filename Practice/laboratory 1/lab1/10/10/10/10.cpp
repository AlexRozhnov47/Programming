﻿// 10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cpp_httplib/httplib.h>
#include <nlohmann/json.hpp>
using namespace httplib;
std::ostringstream ostr;

std::string idkey = "63bc257ab4a6035adaa6ef29e4653593";

using json = nlohmann::json;
json r;


int time_express_status() {
	Client time("http://api.timezonedb.com");
	std::string timerecive = "/v2.1/get-time-zone?key=LKE7TVR6YRJM&format=json&by=zone&zone=Europe/Simferopol";
	auto res = time.Get(timerecive.c_str());
	if (res) {
		if (res->status == 200) {
			json j = json::parse(res->body);
			int timestamp = j["timestamp"].get<int>();
			return timestamp;
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


int time_syncronising(int timestamp) {

	for (int i = 0; i < r.size(); i++) {
		int cache_time = r[i]["dt"];
		if ((timestamp - cache_time < 3600) && (timestamp - cache_time > 0)) {
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
		    i = time_syncronising(time);
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

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
