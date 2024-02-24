#include <iostream> 
#include <random> 
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	random_device rand;

	int const a = 30, b = 100, c = 500;
	int mimi[a];
	int min, max;

	for (int i = 0; i < a; ++i) {
		mimi[i] = b + rand() % (c - b);
		cout << mimi[i] << " " << endl;
	}
	min = mimi[0];
	max = mimi[0];

	for (int i = 1; i < a; i++) {

		if (mimi[i] > max) {
			max = mimi[i];
		}
		if (mimi[i] < min) {
			min = mimi[i];
		}

	}
	cout << min << "Минимальное" << endl << max << "Максимальное" << endl;
	return 0;
}