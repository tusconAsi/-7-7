﻿// Неделя 7 дз 7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <windows.h>
#include <conio.h> 
#include <random>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	cout << "Займемся Арифметикой,раб Компьютера и Технологий!!!!"<<endl;
	int chislo, cifra, tvojVibor, sumChisel, sumNol;
	float sum, znachenie;
	sum = 0;
	sumChisel = 0;
	sumNol = 0;
	cout << "Введи свой выбор,кусок биомассы:"<<endl;
	cin >> chislo;
	do {
		cout << "Твой выбор,Мясо"<<endl;

		cout << "1 - Сколько цифр,Биомусор"<<endl;

		cout << "2 - Посчитай сумму цифр,Двуногое"<<endl;

		cout << "3 - Среднее значение,Мякоть"<<endl;

		cout << "4 - Количество нолей ,Хомо"<<endl;

		cout << "5 - Выход(Посмертно(Раздается механический смех))"<<endl;

		cin >> tvojVibor;

		while (chislo > 0)
		{
			cifra = chislo % 10;
			sum += cifra;
			sumChisel++;

			if (cifra == 0)
				
			{
				sumNol++;
			}
			chislo = chislo / 10;

		}
		znachenie = sum / sumChisel;
		switch (tvojVibor) {
		case 1:
		{
		cout << "Посчитай сколько чисел,Мягкотелый!"<<endl;
		cout << sumChisel << endl;
		break;
		}
		case 2:
		{
		cout << "Посчитай сумму цифр,Пища!"<<endl;
		cout << sum << endl;
		break;
		}
		case 3:
		{
		cout << "Посчитай среднее значение!Мягкий!"<<endl;
		cout << znachenie << endl;
		break;
		}
		case 4:
		{
		cout << "Сумма нолей,Мякоть"<<endl;
		cout << sumNol << endl;
		break;
			
		}
		case 5:
		{
		cout<<"Увидимся на уровне переработки биомассы,Мясо!"<<endl;
		
		break;
		}
		default:
	    cout << "Пункт меню!";
		}
	} while (tvojVibor != 5);
	return 0;
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
