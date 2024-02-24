#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Введите число:" << endl;
	int number, digit, i, newNumber;
	cout << "Введите ваше число" << endl;
	cin >> number;
	i = 0;

	newNumber = 0;
	while (number > 0)
	{
		digit = number % 10;
		if ((digit != 3) && (digit != 6))
		{
			newNumber = newNumber + digit * pow(10, i);
			i++;
		}

		number = number / 10;
	}
	cout << "Твоё новое число: " << newNumber;
	return 0;
}