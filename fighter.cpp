#include"card.h"
#include "fighter.h"
#include<QMouseEvent>
#include<QPainter>
#include"minilabel.h"
#include"fightspace.h"
#include<QPoint>
#include<QFont>

fighter::fighter(int _x, int _y, int _cost, int _atk, int _hp, QString _name, QWidget* parent){
    this->resize(this->w, this->h);//随从大小
    this->setParent(parent);//设置父控件
    this->setFont(QFont("Microsoft YaHei", 18, QFont::Bold));
    this->setAlignment(Qt::AlignCenter);//名字居中显示
    this->name = _name;//名字设置
    this->setText(this->name);//显示名字
    this->atk = _atk;
    this->hp = _hp;

    this->atklabel = new minilabel(_atk,0,100,this);
    this->hplabel = new minilabel(_hp,75,100,this);

    connect(this, SIGNAL(attack(fighter *, QPoint)), parent, SLOT(onfighterattack(fighter *, QPoint)));//将随从的攻击信号和战场的攻击槽函数连接
}

fighter::fighter(int _x, int _y, card* c, QWidget* parent) {
    this->resize(this->w, this->h);//随从大小
    this->setParent(parent);//设置父控件
    this->setFont(QFont("Microsoft YaHei", 18, QFont::Bold));
    this->setAlignment(Qt::AlignCenter);//名字居中显示
    this->name = c->getname();//名字设置
    this->setText(this->name);//显示名字
    this->atk = c->getatk();
    this->hp = c->gethp();

    this->atklabel = new minilabel(c->getatk(), 0, 100, this);
    this->hplabel = new minilabel(c->gethp(),75,100 ,this);

    connect(this, SIGNAL(attack(fighter * , QPoint)), parent, SLOT(onfighterattack(fighter *, QPoint)));//将随从的攻击信号和战场的攻击槽函数连接
}

void fighter::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {

    }

}
void fighter::mouseMoveEvent(QMouseEvent* event) {

        update();
    
}

void fighter::mouseReleaseEvent(QMouseEvent* event) {

    if (event->button() == Qt::LeftButton) {
        if (!this->sleep) emit attack(this, this->mapToParent(event->pos()));////////////////////////////////////////不管有没有怪都会传递信号
        update();
    }
}
void fighter::paintEvent(QPaintEvent* event) {

}

void fighter::wake() {
    if (this->sleep)
        sleep = false;
}

bool fighter::dead() {
    if (this->hp<=0 )
        return true;//血量小于等于0(或者标签血量小于0），死亡函数返回真
    else
        return false;
}

int fighter::getatk() {//获取攻击力
    return this->atk;
}