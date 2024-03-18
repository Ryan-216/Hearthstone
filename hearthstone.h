#pragma once

#include <QtWidgets/QWidget>
#include<QPushButton>
class fightspace;
class handcard;
class ability;
class hero;
class minionlib;
class spelllib;
class spellptrlib;
class power;
class cardlib;
class hearthstone : public QWidget
{
    Q_OBJECT
public:
    hearthstone(QWidget *parent = nullptr);
    ~hearthstone();

public:
    void enenmyact();//敌方行动
private:
    fightspace* space;
    handcard* hand;
    cardlib* lib;
    power* pow;
    QPushButton* turnbutton;
    QPushButton* optionbutton;
    int w;
    int h;
    bool myturn;//是否是我的回合
    int turns;//第几回合
public:
    QPoint start;
    QPoint end;
    bool isdrawing;
    void start_battle();
public slots:
    void oncardpostohearthstone(QPoint p, bool start) {};//接收到坐标

public slots:
    void switchturn();//点击回合结束按钮后
    void openoption();//点击设置按钮后
    void onsend2main(QPoint p, bool start);

protected:
    void paintEvent(QPaintEvent* event);
    

    

};
