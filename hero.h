#pragma once
#include "object.h"
class hero :
    public object
{
public:
   // hero(int _x, int _y, int _hp, QWidget* parent);
    hero(int _x, int _y, int _hp, QString _name, QWidget* parent);

};

