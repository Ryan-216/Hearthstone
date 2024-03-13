#pragma once
#include <qlabel.h>
#include<qvector.h>
#include <vector>
#include"BaseCard.h"

class Hero :
    public QLabel
{
public:
    int blood_;
    int remain_spell_;
    int max_spell;
    void spell_fresh();
    QVector<BaseCard*> hand_cards;
    Hero()
    {
        blood_ = 30;
        remain_spell_ = 1;
        max_spell = 1;
    }
};

