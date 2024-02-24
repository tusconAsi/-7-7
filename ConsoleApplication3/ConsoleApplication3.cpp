#include<iostream>

#include<clocale>

using namespace std;

void setRussian() {
	setlocale(LC_ALL, "Russian");
}
int Vax1() {
	int restart;
	cout << " Перезапуск таблицы если 1 ";

	cout << " Закрытие программы если 2 ";
	cin >> restart;
	return restart;
}

int Vax(int number) {
	int result;
	cout << " Введите число > " << number << ":";
	cin >> result;

	return result;
}

int main() {
	setRussian();
	int Kox1 = Vax(1);
	int Kox2 = Vax(2);
	cout << Kox1 << "*" << Kox2 << "=" << Kox1 * Kox2;

	int restart = Vax1();
	if (restart == 1) {
		main();
	}
	return 1;
}
