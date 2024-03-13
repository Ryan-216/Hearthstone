#include "arch.h"
#include<qslider.h>

arch::arch(QWidget *parent)
    : QWidget(parent)
{
    setMouseTracking(true);
    ui.setupUi(this);
    this->installEventFilter(this);
    this->show();
    this->setFixedSize(width_, height_);
    game_view.setFixedSize(width_, height_);
    game_view.setSceneRect(QRect(0, 0, width_, height_));
    game_view.setParent(this);
    game_view.show();
}

void arch::start()
{
    game_view.setScene(login_scene);   
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
