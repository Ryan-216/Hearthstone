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

    this->atklabel = new minilabel(_atk,0,0,this);
    this->hplabel = new minilabel(_hp,this);

    connect(this, SIGNAL(fighter::attack(fighter * attacker, QPoint pos)), parent, SLOT(fightspace::on_fighter_attack(fighter * attacker, QPoint pos)));//将随从的攻击信号和战场的攻击槽函数连接
    connect(this, SIGNAL(fighter::die(fighter * me)), parent, SLOT(fightspace::on_fighter_die(fighter * f)));
}
//int card::gethp() {
//    return this->hp;
//
//}
//int card::getatk() {
//    return this->atk;
//}
//fighter::fighter(int _x, int _y, card* c, QWidget* parent) {
//    //card* car = new card(c);
//    this->atk = c->getatk();
//    this->hp = c->gethp();
//    this->atklabel = new minilabel(c->getatk(), 0, 0, this);
//    this->hplabel = new minilabel(c->gethp(), this);
//
//
//    connect(this, SIGNAL(fighter::attack(fighter * attacker, QPoint pos)), parent, SLOT(fightspace::on_fighter_attack(fighter * attacker, QPoint pos)));
//    connect(this, SIGNAL(fighter::die(fighter * me)), parent, SLOT(fightspace::on_fighter_die(fighter * f)));
//}

void fighter::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        startPoint = this->mapToParent(event->pos());//记录此随从在战场的相对位置
        endPoint = startPoint;
        isDrawing = true;
        this->setStyleSheet("border :3px solid blue;");//点击变蓝色
    }

}
void fighter::mouseMoveEvent(QMouseEvent* event) {
    if (isDrawing) {
        endPoint = this->mapToParent(event->pos());
        update();
    }
}

void fighter::mouseReleaseEvent(QMouseEvent* event) {

    if (event->button() == Qt::LeftButton) {
        endPoint = startPoint;
        isDrawing = false;
        update();
    }

    emit attack(this,this->mapToParent(event->pos()));////////////////////////////////////////
}
void fighter::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.drawLine(startPoint, endPoint);

}

void fighter::wake() {
    if (this->sleep)
        sleep = false;
}

bool fighter::dead() {
    if (/*this->hplabel->val <= 0 */this->hp<=0 )
        return true;//血量小于等于0(或者标签血量小于0），死亡函数返回真
    else
        return false;
}

int fighter::getatk() {//获取攻击力
    return this->atk;
}