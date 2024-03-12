#pragma once
#include "BaseScene.h"
#include "qpushbutton.h"
#include <qlabel.h>
class LoginScene :
    public BaseScene
{
public:
    
    LoginScene()
    {
        this->setSceneRect(QRect(0, 0, width_, height_));
        bg_.setPixmap(QPixmap(":/arch/Assert/bg_login.png"));
        this->addItem(&bg_);     
        QLabel label;     
        this->addWidget(&label);
        //this->addItem(label);
    }

};

