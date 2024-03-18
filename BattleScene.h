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
        this->addWidget(&hearthstone);
    }
};

