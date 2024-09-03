#include <iostream>
#include <random>
#include <ostream>
#include <Windows.h>
#include <malloc.h>

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

int* Task1_Memory_Alloc(int size)
{
    return static_cast<int*>(calloc(size, sizeof(int)));
}

void Task1_Memory_Free(void* ptr)
{
    free(ptr);
}

int* Task1_Array_Initialize(int* array, int size)
{
    random_device randomiser;

    for (int counter = 0; counter < size; counter++)
    {
        array[counter] = randomiser() % 20 - 10;
    }

    return array;
}

void Task1_Print_Array(int* array, int size)
{
    for (int counter = 0; counter < size; counter++)
    {
        cout << array[counter] << " ";
    }

    cout << endl;
}

int* Task_AddToArray(int* array, int size, int newValue)
{
    const int newSize = size + 1;
    int* newArray = Task1_Memory_Alloc(newSize);

    memcpy(newArray, array, sizeof(int) * size);
    newArray[size] = newValue;
    Task1_Memory_Free(array);

    return newArray;
}

int* Task_DeleteLastFromArray(int* array, int size)
{
    const int newSize = size - 1;
    int* newArray = Task1_Memory_Alloc(newSize);

    memcpy(newArray, array, sizeof(int) * newSize);
    Task1_Memory_Free(array);

    return newArray;
}

int* Task_InsertToArrayAt(int* array, int size, int newValue, int index)
{
    const int newSize = size + 1;
    int* newArray = Task1_Memory_Alloc(newSize);

    memcpy(newArray, array, sizeof(int) * index);
    newArray[index] = newValue;
    memcpy(
        newArray + (index + 1),
        array + index,
        sizeof(int) * (size - index));
    Task1_Memory_Free(array);

    return newArray;
}

int* Task_DeleteFromArrayAt(int* array, int size, int index)
{
    const int newSize = size - 1;
    int* newArray = Task1_Memory_Alloc(newSize);

    memcpy(newArray, array, sizeof(int) * index);
    memcpy(
        newArray + index,
        array + (index + 1),
        sizeof(int) * (newSize - index));
    Task1_Memory_Free(array);

    return newArray;
}

void Task1()
{
    PrintDelimeter();
    cout << "Задача 1 - функции" << endl;
    const int ARRAY_SIZE = 10;
    cout << "Выделяю память под массив int размером " << ARRAY_SIZE << " элементов" << endl;
    int* array = Task1_Memory_Alloc(ARRAY_SIZE);
    cout << "Память выделена, ссылка на область памяти: " << array << endl;
    cout << "Неинициализированный массив: " << endl;
    Task1_Print_Array(array, ARRAY_SIZE);
    cout << "Инициализирую массив. " << endl;
    Task1_Array_Initialize(array, ARRAY_SIZE);
    cout << "Инициализированный массив: " << endl;
    Task1_Print_Array(array, ARRAY_SIZE);
    cout << "Добавляю 0 в конец массива." << endl;
    array = Task_AddToArray(array, ARRAY_SIZE, 0);
    cout << "Массив: " << endl;
    Task1_Print_Array(array, ARRAY_SIZE + 1);
    cout << "Удаляю элемент из конца массива." << endl;
    array = Task_DeleteLastFromArray(array, ARRAY_SIZE + 1);
    cout << "Массив: " << endl;
    Task1_Print_Array(array, ARRAY_SIZE);
    cout << "Добавляю 5 по индексу 5 в массив." << endl;
    array = Task_InsertToArrayAt(array, ARRAY_SIZE, 5, 5);
    cout << "Массив: " << endl;
    Task1_Print_Array(array, ARRAY_SIZE + 1);
    cout << "Удаляю элемент по индексу 5 из массива." << endl;
    array = Task_DeleteFromArrayAt(array, ARRAY_SIZE + 1, 5);
    cout << "Массив: " << endl;
    Task1_Print_Array(array, ARRAY_SIZE);
    
    Task1_Memory_Free(array);
    cout << "Память освобождена." << endl;
    
    cout << "Задача 1 - функции - завершена" << endl;
    PrintDelimeter();
}

bool Task2_IsSimpleDigit(int digit)
{
    switch (abs(digit))
    {
    case 1:
    case 2:
    case 3:
    case 5:
    case 7:
        return true;
    default:
        return false;
    }
    
}

int Task2_GetSimpleDigitsCount(int* array, int size)
{
    int simpleDigitsCount = 0;
    for (int counter = 0; counter < size; counter++)
    {
        const int element = array[counter];

        if (Task2_IsSimpleDigit(element))
        {
            simpleDigitsCount++;
        }
    }
    
    return  simpleDigitsCount;
}

int* Task2_RemoveSimpleDigitsFromArray(int* array, int size)
{
    int newArraySize = size - Task2_GetSimpleDigitsCount(array, size);
    int* newArray = Task1_Memory_Alloc(newArraySize);
    int newArrayIndex = 0;

    for (int counter = 0; counter < size; counter++)
    {
        int element = array[counter];

        if (!Task2_IsSimpleDigit(element))
        {
            newArray[newArrayIndex] = element;
            newArrayIndex++;
        }
    }

    Task1_Memory_Free(array);
    
    return newArray;
}

void Task2()
{
    PrintDelimeter();
    cout << "Задача 2 - проостые числа в массиве." << endl;
    const int ARRAY_SIZE = 10;
    cout << "Выделяю память под массив int размером " << ARRAY_SIZE << " элементов" << endl;
    int* array = Task1_Memory_Alloc(ARRAY_SIZE);
    cout << "Память выделена, ссылка на область памяти: " << array << endl;
    cout << "Неинициализированный массив: " << endl;
    Task1_Print_Array(array, ARRAY_SIZE);
    cout << "Инициализирую массив. " << endl;
    Task1_Array_Initialize(array, ARRAY_SIZE);
    cout << "Инициализированный массив: " << endl;
    Task1_Print_Array(array, ARRAY_SIZE);

    cout << "Удаляю простые числа из массива. " << endl;
    int newArraySize = ARRAY_SIZE - Task2_GetSimpleDigitsCount(array, ARRAY_SIZE);
    array = Task2_RemoveSimpleDigitsFromArray(array, ARRAY_SIZE);
    cout << "Отфильтрованный массив: " << endl;
    Task1_Print_Array(array, newArraySize);
    
    Task1_Memory_Free(array);
    cout << "Память освобождена." << endl;

    cout << "Задача 2 - проостые числа в массиве - завершена." << endl;
    PrintDelimeter();
}

bool Task3_IsZero(int number)
{
    return number == 0;
}

bool Task3_IsPositive(int number)
{
    return number > 0;
}

bool Task3_IsNegative(int number)
{
    return number < 0;
}

int Task3_GetZeroNumbersCount(int array[], int size)
{
    int zeroNumbersCount = 0;
    for (int counter = 0; counter < size; counter++)
    {
        const int element = array[counter];

        if (Task3_IsZero(element))
        {
            zeroNumbersCount++;
        }
    }
    
    return  zeroNumbersCount;
}

int Task3_GetPositiveNumbersCount(int array[], int size)
{
    int positiveNumbersCount = 0;
    for (int counter = 0; counter < size; counter++)
    {
        const int element = array[counter];

        if (Task3_IsPositive(element))
        {
            positiveNumbersCount++;
        }
    }
    
    return  positiveNumbersCount;
}

int Task3_GetNegativeNumbersCount(int array[], int size)
{
    int negativeNumbersCount = 0;
    for (int counter = 0; counter < size; counter++)
    {
        const int element = array[counter];

        if (Task3_IsNegative(element))
        {
            negativeNumbersCount++;
        }
    }
    
    return  negativeNumbersCount;
}

int** Task3_SplitArray(int array[], int size)
{
    int** splitedArray = new int*[3];
    splitedArray[0] = new int[Task3_GetZeroNumbersCount(array, size)];
    splitedArray[1] = new int[Task3_GetPositiveNumbersCount(array, size)];
    splitedArray[2] = new int[Task3_GetNegativeNumbersCount(array, size)];
    int zeroArrayIndex = 0;
    int positiveArrayIndex = 0;
    int negativeArrayIndex = 0;

    for (int count = 0; count < size; count++)
    {
        int element = array[count];

        if (Task3_IsZero(element))
        {
            splitedArray[0][zeroArrayIndex++] = element;
        }
        if (Task3_IsPositive(element))
        {
            splitedArray[1][positiveArrayIndex++] = element;
        }
        if (Task3_IsNegative(element))
        {
            splitedArray[2][negativeArrayIndex++] = element;
        }
    }
    
    return splitedArray;
}

void Task3()
{
    PrintDelimeter();
    cout << "Задача 3 - разделение массива." << endl;

    const int ARRAY_SIZE = 10;
    cout << "Выделяю память под статический массив int размером " << ARRAY_SIZE << " элементов" << endl;
    int array[ARRAY_SIZE];
    cout << "Память выделена, ссылка на область памяти: " << array << endl;
    cout << "Неинициализированный массив: " << endl;
    Task1_Print_Array(array, ARRAY_SIZE);
    cout << "Инициализирую массив. " << endl;
    Task1_Array_Initialize(array, ARRAY_SIZE);
    cout << "Инициализированный массив: " << endl;
    Task1_Print_Array(array, ARRAY_SIZE);

    cout << "Разделяю массив: " << endl;
    int zeroSize = Task3_GetZeroNumbersCount(array, ARRAY_SIZE);
    int positiveSize = Task3_GetPositiveNumbersCount(array, ARRAY_SIZE);
    int negativeSize = Task3_GetNegativeNumbersCount(array, ARRAY_SIZE);
    int** splitedArray = Task3_SplitArray(array, ARRAY_SIZE);
    cout << "Массив нулей: " << endl;
    Task1_Print_Array(splitedArray[0], zeroSize);
    cout << "Массив положительных чисел: " << endl;
    Task1_Print_Array(splitedArray[1], positiveSize);
    cout << "Массив отрицательных чисел: " << endl;
    Task1_Print_Array(splitedArray[2], negativeSize);


    delete [] splitedArray[0];
    delete [] splitedArray[1];
    delete [] splitedArray[2];
    delete [] splitedArray;
    cout << "Память освобождена." << endl;

    cout << "Задача 3 - разделение массива - завершена." << endl;
    PrintDelimeter();
}

int main(int argc, char* argv[])
{
    SetRussian();
    Task1();
    Task2();
    Task3();
    return 0;
}
