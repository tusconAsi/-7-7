#include <iostream>
#include <windows.h>
#include <conio.h> 
#include <random>
#define CUBE(X) (X)*(X)*(X)
using namespace std;
int main()
{
	int max_find(int mas[], int ssize);
	cout << max_find << endl << " " << endl;
}

int max_find(int mas[], int ssize) {
	int Max = mas[0];
	for (int i = 0; i < ssize; i++) {
		if (mas[i] > Max)
			Max = mas[i];
		cout << Max << endl << " " << endl;
	}
	return Max;
}

int max_sum(int mas[], int ssize) {
	int s = mas[0], pos;
	for (int i = 0; i < ssize; i++) {


		s = s + mas[i];
		pos = i;
		cout << max_sum << " " << endl;
	}
	return s;
} 
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
