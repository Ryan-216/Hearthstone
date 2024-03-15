#pragma once
#include "BaseScene.h"
#include "hearthstone.h"
class BattleScene :
    public BaseScene
{
public:
    hearthstone hearthstone;
    BattleScene()
    {
        this->setSceneRect(QRect(0, 0, width_, height_));
        bg_.setFixedSize(width_, height_);
        bg_.setPixmap(QPixmap(":/assert/bg_battle.png"));
        this->addWidget(&bg_);
        this->addWidget(&hearthstone);
    }
};

