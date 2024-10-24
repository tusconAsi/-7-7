#include <iostream>
#include"Stanok.h"

using namespace std;

class Stanok {
public:
    static Stanok* create_stanok(const string& type) {
        if (type == "Frezerniy") {
            return new Frezerniy();
        }
        else if (type == "pescostruy") {
            return new PescoStruy();
        }
        else if (type == "svarochny") {
            return new Svarochniy();
        }
        else if (type == "bentonny") {
            return new LentoPila();
        }
    }
};

int main()
{
        Stanok* Frezerniy = Stanok::create_stanok("Фрезерный станок");
        Frezerniy->set_attrs("Скорость: 3000 об/мин, Длина заготовки: 2м");
        Frezerniy->query_info();

        Stanok* Svarochniy = FabricaStancov::create_stanok("Сварочный Станок");
        Svarochniy->set_attrs("Ток: 380А");
        Svarochniy->query_info();

        Stanok* PescoStruy = FabricaStancov::create_stanok("Пескоструйный агрегат");
        PescoStruy->set_attrs("Давление: 50 бар");
        PescoStruy->query_info();

        Stanok* LentoPila = FabricaStancov::create_stanok("Ленточно-пильный слесарный станок");
        LentoPila->set_attrs("Диаметр заготовки: 450 мм");
        LentoPila->query_info();

        delete Frezerniy;
        delete Svarochniy;
        delete PescoStruy;
        delete LentoPila;

    return 0;
};

