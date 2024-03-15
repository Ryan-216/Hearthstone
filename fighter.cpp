#include "fighter.h"
#include<QMouseEvent>
#include<QPainter>
#include"minilabel.h"
#include"fightspace.h"
#include<QPoint>
#include"card.h"

fighter::fighter(int _x, int _y, int _cost, int _atk, int _hp, std::string _name, QWidget* parent){
    this->atklabel = new minilabel(_atk,0,0,this);
    this->hplabel = new minilabel(_hp,this);
    connect(this, SIGNAL(fighter::attack(fighter * attacker, QPoint pos)), f, SLOT(fightspace::on_fighter_attack(fighter * attacker, QPoint pos)));
    connect(this, SIGNAL(fighter::die(fighter * me)), f, SLOT(fightspace::on_fighter_die(fighter * f)));
}

fighter::fighter(int _x, int _y, card* c, QWidget* parent) {
    this->atklabel = new minilabel(c->getatk(), 0, 0, this);
    this->hplabel = new minilabel(c->gethp(), this);
    connect(this, SIGNAL(fighter::attack(fighter * attacker, QPoint pos)), f, SLOT(fightspace::on_fighter_attack(fighter * attacker, QPoint pos)));
    connect(this, SIGNAL(fighter::die(fighter * me)), f, SLOT(fightspace::on_fighter_die(fighter * f)));
}

void fighter::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        startPoint = event->scenePos();
        endPoint = startPoint;
        isDrawing = true;
        this->setStyleSheet("border :3px solid blue;");//点击变蓝色
    }

}
void fighter::mouseMoveEvent(QMouseEvent* event) {
    if (isDrawing) {
        endPoint = event->scenePos();
        update();
    }
}
fightspace* f = new fightspace(nullptr);///////////////***************************************************************************************************////////////////////////
void fighter::mouseReleaseEvent(QMouseEvent* event) {

    if (event->button() == Qt::LeftButton) {
        endPoint = startPoint;
        isDrawing = false;
        update();
    }

    emit attack(this, event->scenePos());
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

void fighter::hit(QPoint p) {
    ///
}

int fighter::getatk() {//获取攻击力
    return this->atk;
}