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
    Q_OBJECT
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
    void enemyremove(fighter* f) ;
    void myadd(fighter* f);
    void myremove(fighter* f) ;
    void enemyrefresh();
    void myrefresh();
    fighter* searchfighter(QPoint *p);//根据战场p找fighter
    QPoint* convert(QPoint* p);//全局坐标转战场坐标
public:
    int w;
    int h;
    QPoint pos;
public slots:
    void onhandcarduseminion(card* c, QPoint pos);//当手牌发出使用随从的信号时 战场需要在相应位置添加一个随从 rhy
    void onhandcardusedirspell(card* c, QPoint pos);//当手牌发出使用指向法术的信号时 战场发生相应变化 
    void onhandcardusenodirspell(card* c);//当手牌发出使用非指向法术的信号时 战场发生相应变化 
    void onhandcarduseability(ability* a, QPoint* pos);//当英雄技能使用时 战场发生相应变化
    void onfighterattack(fighter* attacker, QPoint pos);//处理攻击的信号 attacker攻击pos位置的随从 更新血量 

public:
    //坐标计算函数 根据坐标计算出是哪个目标 难点


public:
    //由于法术效果全部作用于战场 spellptrlib中的函数全部写到fightspace中


};

