#pragma once
#include "Stanok.h"
using namespace std;

class Frezerniy :public Stanok {
private :
	string status;
	string atributes;
public:
	string get_info() const override {
		return "Фрезерный станок - Статус:" + status + "Аерибуты:" + atributes;
	}
	void set_attrs(const string& attrs) override {
		atributes = attrs;
		status = "Атрибуты установлены:";
	}
	void query_info() override {
		status = "Работа завершена";
		cout << get_info() << endl;
	}
};
