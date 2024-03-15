#pragma once
#include "BaseScene.h"
#include "hearthstone.h"
class BattleScene :
    public BaseScene
{
public:
    hearthstone hearthstone;
    QLabel* bg = new QLabel(&hearthstone);
    BattleScene()
    {
        this->setSceneRect(QRect(0, 0, width_, height_));
        bg->setFixedSize(width_, height_);
        bg->setPixmap(QPixmap(":/assert/bg_battle.png"));
        this->addWidget(&hearthstone);
    }
};

