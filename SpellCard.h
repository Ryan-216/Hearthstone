#pragma once
#include "BaseCard.h"
class SpellCard :
    public BaseCard
{
public:
    SpellCard()
    {
        this->setPixmap(QPixmap(":/arch/Assert/spell.png"));
    }
};

