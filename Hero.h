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
    int width_ = 50, height_ = 50;
    QVector<BaseCard*> hand_cards;
    int cards_num[3] = { 0 };
    Hero()
    {
        this->setPixmap(QPixmap(":/arch/Assert/hero.png"));
        blood_ = 30;
        remain_spell_ = 1;
        max_spell = 1;
    }
};

