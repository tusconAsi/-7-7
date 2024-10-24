#pragma once
#include"Stanok.h"
using namespace std;

class Svarochniy : public Stanok {
private:
	string status;
	string atributes;
public:
	string get_info() const override {
		return "Полуавтомат станок - Статус:" + status + "Аерибуты:" + atributes;
	}
	void set_attrs(const string& attrs) override {
		atributes = attrs;
		status = "Атрибуты установлены:";
	}
	void query_info(void) override {
		status = "Работа завершена";
		cout << get_info() << endl;
	}
};