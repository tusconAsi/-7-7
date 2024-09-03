#include <iostream>
#include <random>
#include <ostream>
#include <Windows.h>

using namespace std;

void SetRussian()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

void PrintDelimeter()
{
    cout << "------------------" << endl;
}

void Task_1_PrintNumbers(const string homeNumbers[], const string mobileNumbers[], const int size)
{
    cout << "Справочник:" << endl;
    cout << "| Домашний номер |  Мобильный номер  |" << endl;
    for (int counter = 0; counter < size; counter++)
    {
        cout << "|    " << homeNumbers[counter] << "   |  " << mobileNumbers[counter] << " |" << endl;
    }
    cout << "Список завершен." << endl;
}

void Task_1_SortNumbers(string homeNumbers[], string mobileNumbers[], const int size, const bool isSortMobileNumbers)
{
    bool isSwapped = true;

    while (isSwapped)
    {
        isSwapped = false;
        
        for (int counter = 1; counter < size; counter++)
        {
            if (
                (isSortMobileNumbers && mobileNumbers[counter].compare(mobileNumbers[counter - 1]) > 0) ||
                (!isSortMobileNumbers && homeNumbers[counter].compare(homeNumbers[counter - 1]) > 0)
            ){
                swap(mobileNumbers[counter], mobileNumbers[counter - 1]);
                swap(homeNumbers[counter], homeNumbers[counter - 1]);
                isSwapped = true;
            }
        }
    }
}

void Task_1_Menu(string homeNumbers[], string mobileNumbers[], const int size)
{
    cout << "Меню:" << endl;
    cout << "1. Отсортировать по номерам мобильных" << endl;
    cout << "2. Отсортировать по домашним номерам телефонов" << endl;
    cout << "3. Вывести данные" << endl;
    cout << "4. Выход" << endl;
    cout << endl;
    cout << "Введите номер пункта меню: ";
    string selectedMenuItem;
    cin >> selectedMenuItem;

    if (selectedMenuItem == "1")
    {
        Task_1_SortNumbers(homeNumbers, mobileNumbers, 4, true);
        Task_1_Menu(homeNumbers, mobileNumbers, 4);        
    } else if (selectedMenuItem == "2")
    {
        Task_1_SortNumbers(homeNumbers, mobileNumbers, 4, false);
        Task_1_Menu(homeNumbers, mobileNumbers, 4);        
    } else if (selectedMenuItem == "3")
    {
        Task_1_PrintNumbers(homeNumbers, mobileNumbers, 4);
        Task_1_Menu(homeNumbers, mobileNumbers, 4);
    } else if (selectedMenuItem == "4")
    {
        cout << "Выход из задачи 1." << endl;
    }
    else
    {
        cout << "Неверный пункт меню";
        Task_1_Menu(homeNumbers, mobileNumbers, 4);        
    }
}

void Task_1()
{
    PrintDelimeter();
    cout << "Задача 1 - справочник" << endl;
    cout << "Создаю справочник" << endl;
    string homeNumbers[]
    {
        "375-55-68",
        "854-88-99",
        "785-88-22",
        "888-88-88"
    };
    string mobileNumbers[]
    {
        "+7-987-375-55-68",
        "+7-955-854-88-99",
        "+7-700-785-88-22",
        "+7-999-888-88-88"
    };
    Task_1_Menu(homeNumbers, mobileNumbers, 4);
    PrintDelimeter();
}

int Task_2_NumberDegree(const int number, const int degree)
{
    if (degree == 0)
    {
        return 1;
    }

    return number * Task_2_NumberDegree(number, degree - 1);
}

void Task_2()
{
    PrintDelimeter();
    cout << "Задача 2 - степень числа" << endl;
    int number;
    cout << "Введите число: ";
    cin >> number;
    int degree;
    cout << "Введите степень числа: ";
    cin >> degree;

    cout << "Число " << number << " в степени " << degree
            << " равно: " << Task_2_NumberDegree(number, degree) << endl;

    PrintDelimeter();
}

void Task_3_PrintStars(const int starCount)
{
    if (starCount == 0)
    {
        return;
    }

    cout << "*";

    Task_3_PrintStars(starCount - 1);
}

void Task_3()
{
    PrintDelimeter();
    cout << "Задача 3 - звезды" << endl;
    int starCount;
    cout << "Введите число звезд для показа: ";
    cin >> starCount;

    Task_3_PrintStars(starCount);

    cout << endl;
    
    PrintDelimeter();
}

int main(int argc, char* argv[])
{
    SetRussian();
    Task_1();
    Task_2();
    Task_3();
    
    return 0;
}
