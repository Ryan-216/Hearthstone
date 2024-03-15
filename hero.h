#pragma once
#include "object.h"
class hero :
    public object
{
public:
    hero(int _x, int _y, int _hp, QWidget* parent);
    hero(int _x, int _y, int _hp, std::string _name, QWidget* parent);

};

