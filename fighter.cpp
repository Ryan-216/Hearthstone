#include"card.h"
#include "fighter.h"
#include<QMouseEvent>
#include<QPainter>
#include"minilabel.h"
#include"fightspace.h"
#include<QPoint>
#include<QFont>

fighter::fighter(int _x, int _y, int _cost, int _atk, int _hp, QString _name, QWidget* parent){
    this->resize(this->w, this->h);//��Ӵ�С
    this->setParent(parent);//���ø��ؼ�
    this->setFont(QFont("Microsoft YaHei", 18, QFont::Bold));
    this->setAlignment(Qt::AlignCenter);//���־�����ʾ
    this->name = _name;//��������
    this->setText(this->name);//��ʾ����
    this->atk = _atk;
    this->hp = _hp;

    this->atklabel = new minilabel(_atk,0,0,this);
    this->hplabel = new minilabel(_hp,this);

    connect(this, SIGNAL(fighter::attack(fighter * attacker, QPoint pos)), parent, SLOT(fightspace::on_fighter_attack(fighter * attacker, QPoint pos)));//����ӵĹ����źź�ս���Ĺ����ۺ�������
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
        startPoint = this->mapToParent(event->pos());//��¼�������ս�������λ��
        endPoint = startPoint;
        isDrawing = true;
        this->setStyleSheet("border :3px solid blue;");//�������ɫ
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
        return true;//Ѫ��С�ڵ���0(���߱�ǩѪ��С��0������������������
    else
        return false;
}

int fighter::getatk() {//��ȡ������
    return this->atk;
}