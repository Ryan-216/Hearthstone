#pragma once
#include <qwidget.h>
class fighter;
class hero;
class ability;
class object;
class card;
class fightspace :
    public QWidget
{
public:
    fightspace(QWidget* parent);
private:
    std::vector<fighter*>enemyspace;//敌方随从容器 至多7
    std::vector<fighter*>myspace;//我方随从容器 至多7
    int enemynum;//敌方随从数量
    int mynum;//我方随从数量
    hero* enemyhero;
    hero* myhero;
    ability* enemyability;
    ability* myability;
public:
    void enemyadd(fighter*f);
    void enemyremove(fighter* f);
    void myadd(fighter* f);
    void myremove(fighter* f);
    void enemyrefresh();
    void myrefresh();
public:
    int w;
    int h;
    QPoint pos;
public slots:
    void on_handcard_useminion(card* c, QPoint pos);
    void on_handcard_usedirspell(card* c, QPoint pos);
    void on_handcard_usenodirspell(card* c);
    void on_handcard_useability(ability* a, QPoint* pos);
    void on_fighter_attack(fighter* attacker, QPoint pos);//根据pos计算攻击的是谁 也许是英雄 也许是无效攻击
    void on_fighter_die(fighter*f);//处理死亡信号

public:
    //坐标计算函数 根据坐标计算出是哪个目标 难点


public:
    //由于法术效果全部作用于战场 spellptrlib中的函数全部写到fightspace中


};

