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
#include "qtimer.h"
#include <map>

class BattleScene :
    public BaseScene
{
public:
    Hero* hero_ = new Hero();
    Hero* enemy_ = new Hero();
    QTimer* timer_1;
    QTimer* timer_2;
    QLabel* hero_status = new QLabel;
    QLabel* enemy_status = new QLabel;
    QLabel* notice = new QLabel;
    QString notice_info = "Please move your minions to attack the enemy";
    int num_of_turn_ = 1;
    QLabel ending;
    QPushButton* back = new QPushButton;
    
   
    /*QGraphicsTextItem* enemy_blood = new QGraphicsTextItem;
    QGraphicsTextItem* hero_blood = new QGraphicsTextItem;
    QGraphicsTextItem* notice_ = new QGraphicsTextItem;*/
    
    QPushButton* btn_end_of_turn = new QPushButton;
    QProgressBar* grid_mana_bar = new QProgressBar;

    bool turn = true;
    QVector<BaseCard*>cards_;//³é¿¨¿¨³Ø
    //QVector<BaseCard*>cards_in_battle_;//Õ½¶·¿¨³Ø


    void battle();//Õ½¶·º¯Êý
    void draw_cards(Hero* hero, int num);//³é¿¨º¯Êý
    void paint_cards(Hero* hero);//»­¿¨º¯Êý
    void paint_text(Hero* hero);
    void paint_notice();
    void paint_all();//»­Í¼²Ûº¯Êý
    void turn_change();
    void manage_attack();
    void fake_mouse();//true click false release
    void end(bool e);
    int mouse_ = 0;
    QPointF mouse_pos;
    bool any_drag = false;

   
private:
    bool isDrawing;
    QPointF startPoint;
    QPointF endPoint;

signals:
    void draw();

    BattleScene()
    {           
        this->setSceneRect(QRect(0, 0, width_, height_));

        bg_.setPixmap(QPixmap(":/arch/Assert/bg_battle.png"));  
        bg_.setFixedSize(width_, height_);
        btn_end_of_turn->setText("Your Turn");
        btn_end_of_turn->resize(100, 40);
        btn_end_of_turn->setFont(QFont("timesnewroman", 10, 4, 0));
        btn_end_of_turn->move((width_ - btn_end_of_turn->width()) / 2 + 401, (height_ - btn_end_of_turn->height()) / 2);

        
        

        this->addWidget(&bg_);
        this->addWidget(btn_end_of_turn);
        this->addWidget(hero_status);
        this->addWidget(enemy_status);
        this->addWidget(notice);
        this->addWidget(hero_);
        this->addWidget(enemy_);

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

