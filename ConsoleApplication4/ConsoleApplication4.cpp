
#include <iostream>
#include <clocale>

using namespace std;

void setRussian() {
    setlocale(LC_ALL, "Russian");
}

int getDigit() {
    int result;

    cout << "Введите число для перевода в строку:>";
    cin >> result;

    return result;
}
void ShowUnit(int unit) {
    if (unit == 0) {
        cout << "ноль";
    }
    if (unit == 1) {
        cout << "один";
    }
    if (unit == 2) {
        cout << "два";
    }
    if (unit == 3) {
        cout << "три";
    }
    if (unit == 4) {
        cout << "четыре";
    }
    if (unit == 5) {
        cout << "пять";
    }
    if (unit == 6) {
        cout << "шесть";
    }
    if (unit == 7) {
        cout << "семь";
    }
    if (unit == 8) {
        cout << "восемь";
    }
    if (unit == 9) {
        cout << "девять";
    }
}

void ShowTenUnit(int unit) {
    if (unit == 0) {
        cout << "десять";
    }
    if (unit == 1) {
        cout << "одиннадцать";
    }
    if (unit == 2) {
        cout << "двенадцать";
    }
    if (unit == 3) {
        cout << "тринадцать";
    }
    if (unit == 4) {
        cout << "четырнадцать";
    }
    if (unit == 5) {
        cout << "пятнадцать";
    }
    if (unit == 6) {
        cout << "шестнадцать";
    }
    if (unit == 7) {
        cout << "семнадцать";
    }
    if (unit == 8) {
        cout << "восемнадцать";
    }
    if (unit == 9) {
        cout << "девятнадцать";
    }
}

void ShowTens(int unit) {
    if (unit == 2) {
        cout << "двадцать";
    }
    if (unit == 3) {
        cout << "тридцать";
    }
    if (unit == 4) {
        cout << "сорок";
    }
    if (unit == 5) {
        cout << "пятьдесят";
    }
    if (unit == 6) {
        cout << "шестьдесят";
    }
    if (unit == 7) {
        cout << "семдесят";
    }
    if (unit == 8) {
        cout << "восемдесят";
    }
    if (unit == 9) {
        cout << "девяносто";
    }

}



void DigitToConsole(int inputDigit) {
    int tens = inputDigit / 10;
    int units = inputDigit % 10;

    if (tens == 0) {
        ShowUnit(units);
    }
    else if (tens == 1) {
        ShowTenUnit(units);
    }
    else {
        ShowTens(tens);
        cout << " ";
        ShowUnit(units);
    }
}




int main()
{
    setRussian();
    int digit = getDigit();
    DigitToConsole(digit);
    return 0;
}


int getChislo() {
    int cislo;
    std::cout << "число";
    std::cin >> cislo;
    return cislo;
}
