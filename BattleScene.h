#pragma once
#include "BaseScene.h"
#include "qgraphicsitem.h"
#include "qvector.h"
#include <algorithm>
#include <random>
#include <qdebug.h>
#include <QGraphicsSceneMouseEvent>
#include <algorithm>
#include "qalgorithms.h"
#include <qstring.h>
#include <qpushbutton.h>
#include <qprogressbar.h>
#include "Hero.h"
#include "MinionCard.h"
#include "SpellCard.h"


class BattleScene :
    public BaseScene
{
public:
    Hero* hero_ = new Hero();
    Hero* enemy_ = new Hero();
   
    /*QGraphicsTextItem* enemy_blood = new QGraphicsTextItem;
    QGraphicsTextItem* hero_blood = new QGraphicsTextItem;
    QGraphicsTextItem* notice_ = new QGraphicsTextItem;*/
    
    QPushButton* btn_end_of_turn = new QPushButton;
    QProgressBar* grid_mana_bar = new QProgressBar;

    bool turn = true;
    QVector<BaseCard*>cards_;//³é¿¨¿¨³Ø
    QVector<BaseCard*>cards_in_battle_;//Õ½¶·¿¨³Ø


    void battle();//Õ½¶·º¯Êý
    void draw_cards(Hero* hero, int num);//³é¿¨º¯Êý
    void paint_cards(Hero* hero);//»­¿¨º¯Êý
signals:
    void draw();
    //void mouseReleaseEvent(QGraphicsSceneMouseEvent* mouse_event);

    //void mouseMoveEvent(QGraphicsSceneMouseEvent* mouse_event);
    //void mousePressEvent(QGraphicsSceneMouseEvent* mouse_event);
    

    BattleScene()
    {           
        
        this->setSceneRect(QRect(0, 0, width_, height_));

        bg_.setPixmap(QPixmap(":/arch/Assert/bg_battle.png"));    
        btn_end_of_turn->setText("End");
        btn_end_of_turn->resize(100, 40);
        btn_end_of_turn->setFont(QFont("timesnewroman", 20, 8, 0));
        btn_end_of_turn->move((width_ - btn_end_of_turn->width()) / 2 + 400, (height_ - btn_end_of_turn->height()) / 2);

        this->addWidget(&bg_);
        this->addWidget(btn_end_of_turn);

        for (int i = 0; i < 20; i++)
        {
            if (i < 10)
            {
                MinionCard* card = new MinionCard;
                cards_.push_back(card);
            }
            else
            {
                SpellCard* card = new SpellCard;
                cards_.push_back(card);
            }
        }
    }


    

    ~BattleScene()
    {
        for (BaseCard* card : cards_)
        {
            delete(card);
        }
    }

   
};

