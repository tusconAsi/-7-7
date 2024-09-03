#include <iostream>
#include <windows.h>
#include <conio.h> 
#include <random>

using namespace std;
void print(int arr[], int size);
void sortingBubble(int arr[], int size);


void sortInsertion(int array[], const int startIndex, const int stopIndex, const bool isLowerToGrater) {
	for (int sortedCounter = startIndex; sortedCounter < stopIndex; sortedCounter++)
	{
		for (int arrayCounter = sortedCounter; arrayCounter >= startIndex; arrayCounter--)
		{
			if (isLowerToGrater && array[arrayCounter] > array[arrayCounter + 1]) {
				swap(array[arrayCounter], array[arrayCounter + 1]);
				continue;
			}
			if (!isLowerToGrater && array[arrayCounter] < array[arrayCounter + 1]) {
				swap(array[arrayCounter], array[arrayCounter + 1]);
				continue;
			}
			break;
		}
	}
}

int GetFirstNegativeValueIndex(int array[], const int size, const bool isSearchFromBegining)
{
	int startIndex = isSearchFromBegining ? 0 : size - 1;
	int stopIndex = isSearchFromBegining ? size - 1 : 0;

	for (
		int counter = isSearchFromBegining ? 0 : size - 1;
		isSearchFromBegining ? counter < size : counter >= 0;
		isSearchFromBegining ? counter++ : counter--
		)
	{
		if (array[counter] < 0)
		{
			return counter;
		}
	}
}

int main() {
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	random_device Rand;
	int Mas[15] = { 1,10,2,63,44,5,6,32,-3 ,11,22,44,55};
    const int S1 = 15;

	for (int counter = 0; counter < S1; counter++)
	{
		Mas[counter] = Rand() % 40 - 20;
	}
	
    print(Mas, 15);
	sortingBubble(Mas, S1);
	cout << "Сортировка пузырьком" << endl;
	print(Mas, S1);


	cout << "Сортировка вставками" << endl;
	sortInsertion(Mas, 0, 7, false);
	sortInsertion(Mas, 8, 14, true);
	print(Mas, S1);

	cout << "Сортировка между отрицательными числами" << endl;
	int firstIndex = GetFirstNegativeValueIndex(Mas, S1, true);
	int lastIndex = GetFirstNegativeValueIndex(Mas, S1, false);
	sortInsertion(Mas, firstIndex, lastIndex, true);
	print(Mas, S1);
}



void loadValue(char arr[], int size) {
	random_device Rand;

	for (int i = 0; i < size; ++i) {
		arr[i] = Rand() % 40 - 20;
	}
}

void print(int arr[], int size) {
	for (int i = 0; i < size; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
		
void sortingBubble(int arr[], int size) {

	for (int i = 0; i < size; ++i) {
		int Zaehler = 0;
		for (int i = 0; i <= size - 1; i++) {
			if (arr[i] < arr[i + 1]) {
				Zaehler++;
			}
		
		}

		cout << Zaehler << " " << endl;
		if (Zaehler == 0) {
			break;
		}
		for (int j = 0; j < size - 1 - i; ++j) {
			if (arr[j] < arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;

			}
		}
		
	}	
}

