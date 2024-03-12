#pragma once
#include "BaseScene.h"

#include "qgraphicsitem.h"
#include "qvector.h"

#include <algorithm>
#include "qalgorithms.h"
#include <qstring.h>

class BattleScene :
    public BaseScene
{
public:
   
    QString s;
    QString debug_;
    QGraphicsTextItem* enemy_blood = new QGraphicsTextItem;
    QGraphicsTextItem* hero_blood = new QGraphicsTextItem;
    QGraphicsTextItem* notice_ = new QGraphicsTextItem;
    bool turn;
    void battle_start();//战斗开始，初始抽卡
    bool battle_loop();//战斗循环，true胜利，false失败


    void mouseMoveEvent(QGraphicsSceneMouseEvent* mouse_event);
    void mousePressEvent(QGraphicsSceneMouseEvent* mouse_event);

public:slots
    void end_turn();
    BattleScene()
    {
       
        
        this->addText(debug_);
        this->setSceneRect(QRect(0, 0, width_, height_));
        bg_.setPixmap(QPixmap(":/arch/Assert/bg_battle.png"));
        this->addItem(&bg_);
    }


    ~BattleScene()
    {

    }

   
};

