#pragma once
#include<iostream>
#include"Frezerniy.h"
#include"Svarochniy.h"
#include"LentoPila.h"
#include"Pescostruy.h"

class Stanok {
public:

    virtual ~Stanok() {}
    virtual string get_info() const = 0;
    virtual void set_attrs(const string& attrs);
    virtual void query_info() = 0;
};