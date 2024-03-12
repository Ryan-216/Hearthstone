#pragma once
#include "BaseCard.h"
class MinionCard :
    public BaseCard
{
public:
    MinionCard()
    {
        this->setPixmap(QPixmap(":/arch/Assert/minion.png"));
    }
};

