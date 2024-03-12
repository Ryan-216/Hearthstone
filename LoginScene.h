#pragma once
#include "BaseScene.h"
#include "qpushbutton.h"
#include <qlabel.h>
#include <QFont>
class LoginScene :
    public BaseScene
{
public:
    QPushButton* btn_login = new QPushButton;
    QFont* font_login = new QFont("timesnewroman", 20, 8, 0);

    LoginScene()
    {
        this->setSceneRect(QRect(0, 0, width_, height_));
        bg_.setPixmap(QPixmap(":/arch/Assert/bg_login.png"));
        this->addWidget(&bg_);  
        
        btn_login->resize(100, 40);
        btn_login->move((width_ - btn_login->width()) / 2, (height_ - btn_login->height()) / 2 + 200);

        btn_login->setFont(*font_login);
        btn_login->setText("Strat");

        this->addWidget(btn_login);
    }

};

