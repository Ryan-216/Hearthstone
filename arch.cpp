#include "arch.h"
#include<qslider.h>
#include<stdlib.h>

arch::arch(QWidget *parent)
    : QWidget(parent)
{
    setMouseTracking(true);
    ui.setupUi(this);
    this->installEventFilter(this);
    this->show();
    this->setFixedSize(width_, height_);
    game_view.setFixedSize(width_ + 2, height_ + 2);
    game_view.setSceneRect(0, 0, width_, height_);
    game_view.setParent(this);
    game_view.show();
    connect(battle_scene->back, &QPushButton::clicked, this, &arch::start);
    connect(login_scene->btn_leave, &QPushButton::clicked, []() {exit(0); });
}

void arch::start()
{
    game_view.setScene(login_scene);   
    qDebug() << game_view.height();
    qDebug() << login_scene->height_;
    qDebug() << login_scene->bg_.height();
    connect(login_scene->btn_login, &QPushButton::clicked, this, &arch::battle);
}

void arch::battle()
{
    game_view.setScene(battle_scene);    
    battle_scene->battle();      
}

//bool arch::eventFilter(BaseCard* card, QEvent* event)
//{
//    /*if (card->status_ == 0 && card->allow_click_)
//    {
//        return true;
//    }*/
//    return true;
//}

arch::~arch()
{}

void arch::end()
{
    this->close();
}
