#pragma once
#include "Stanok.h"
using namespace std;

class Frezerniy :public Stanok {
private :
	string status;
	string atributes;
public:
	string get_info() const override {
		return "��������� ������ - ������:" + status + "��������:" + atributes;
	}
	void set_attrs(const string& attrs) override {
		atributes = attrs;
		status = "�������� �����������:";
	}
	void query_info() override {
		status = "������ ���������";
		cout << get_info() << endl;
	}
};
