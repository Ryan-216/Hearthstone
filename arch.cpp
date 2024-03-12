#include "arch.h"
#include<qslider.h>

arch::arch(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    this->show();
    this->setFixedSize(width_, height_);
    game_view.setSceneRect(QRect(0, 0, width_, height_));

    //初始化开始按钮
    
    btn_login->resize(100, 40);
    btn_login->move((width_ - btn_login->width()) / 2, (height_ - btn_login->height()) / 2 + 200);
    QFont font_login("timesnewroman", 20, 8, 0);
    btn_login->setFont(font_login);
    btn_login->setText("Strat");

}

void arch::start()
{
    
    //test->setPixmap(QPixmap(":/arch/Assert/minion.png"));
    //test->setPos(100, 100);
    //login_scene.addItem(test);  
    
    game_view.setScene(&login_scene);

    game_view.setParent(this);
    game_view.show();


    btn_login->setParent(this);
    btn_login->show();

    connect(btn_login, &QPushButton::clicked, this, &arch::battle);
}

void arch::battle()
{
    enter_battle_scene();
    battle_scene->battle_start();
    connect(btn_end_of_turn, &QPushButton::clicked, battle_scene, &BattleScene::end_turn);
    //battle_scene->battle_loop();

//    while (battle_scene->hero_.blood_ > 0 && battle_scene->enemy_.blood_ > 0)
//    {
//        //我方计算法力值
//        battle_scene->calculate_mana(&battle_scene->hero_);
//        //我方抽取一张卡
//        battle_scene->draw_cards(&battle_scene->hero_, 1);
//        //我方操作    
//        while (battle_scene->turn == true)
//        {
//
//            connect(btn_end_of_turn, &QPushButton::clicked, battle_scene, &BattleScene::end_turn);
//
//        }
//        //我方结束
//
//        //敌方计算法力值
//        battle_scene->calculate_mana(&battle_scene->enemy_);
//        //敌方抽取一张卡
//        battle_scene->draw_cards(&battle_scene->enemy_, 1);
//        //敌方操作
//
//        //敌方结束
//    }
//     
}



void arch::enter_battle_scene()
{    
   

    game_view.setScene(battle_scene);
    btn_login->close();    
    btn_end_of_turn->setText("End");
    btn_end_of_turn->resize(100, 40);
    btn_end_of_turn->setFont(QFont("timesnewroman", 20, 8, 0));
    btn_end_of_turn->setParent(this);
    btn_end_of_turn->move((width_ - btn_login->width()) / 2 + 400, (height_ - btn_login->height()) / 2);
    btn_end_of_turn->show();

}
arch::~arch()
{}

void arch::end()
{
    this->close();
}
