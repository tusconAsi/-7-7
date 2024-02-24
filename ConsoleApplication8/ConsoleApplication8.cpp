#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Число в диапазоне от 100 до 999" << endl;

	int number1, number2, number3, same, resN, temp;
	resN = 0;

	for (int i = 100; i <= 999; i++)
	{
		same = 0;
		number3 = i % 10;
		temp = i / 10;
		number2 = temp % 10;
		number1 = temp / 10;
		if ((number1 != number2) &&
			(number1 != number3) &&
			(number2 != number3))
		{
			resN++;
		}
	}
	cout << "Показать результат:" << endl;
	cout << resN << endl;
	return 0;
}