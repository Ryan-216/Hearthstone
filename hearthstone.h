#pragma once

#include <QtWidgets/QWidget>
#include "ui_hearthstone.h"
#include<QPushButton>
class fighterspace;
class handcard;
class ability;
class hero;
class minionlib;
class spelllib;
class spellptrlib;
class power;

class hearthstone : public QWidget
{
    Q_OBJECT

public:
    hearthstone(QWidget *parent = nullptr);
    ~hearthstone();
private:
    Ui::hearthstoneClass ui;
    fighterspace* space;
    handcard* hand;
    minionlib* minion_lib;
    spelllib* spell_lib;
    spellptrlib* spellptr_lib;
    power* pow;
    QPushButton* turnbutton;
    QPushButton* optionbutton;
    int w;
    int h;
public:
    QPoint startPoint;
    QPoint endPoint;
    bool isDrawing;
public slots:
    void on_card_postohearthstone(QPoint p,bool start);//接收到坐标
protected:
    void paintEvent(QPaintEvent* event);
    
};
