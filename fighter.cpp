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

    this->atklabel = new minilabel(_atk,0,100,this);
    this->hplabel = new minilabel(_hp,75,100,this);

    connect(this, SIGNAL(attack(fighter *, QPoint)), parent, SLOT(onfighterattack(fighter *, QPoint)));//����ӵĹ����źź�ս���Ĺ����ۺ�������
}

fighter::fighter(int _x, int _y, card* c, QWidget* parent) {
    this->resize(this->w, this->h);//��Ӵ�С
    this->setParent(parent);//���ø��ؼ�
    this->setFont(QFont("Microsoft YaHei", 18, QFont::Bold));
    this->setAlignment(Qt::AlignCenter);//���־�����ʾ
    this->name = c->getname();//��������
    this->setText(this->name);//��ʾ����
    this->atk = c->getatk();
    this->hp = c->gethp();

    this->atklabel = new minilabel(c->getatk(), 0, 100, this);
    this->hplabel = new minilabel(c->gethp(),75,100 ,this);

    connect(this, SIGNAL(attack(fighter * , QPoint)), parent, SLOT(onfighterattack(fighter *, QPoint)));//����ӵĹ����źź�ս���Ĺ����ۺ�������
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
        if (!this->sleep) emit attack(this, this->mapToParent(event->pos()));////////////////////////////////////////������û�йֶ��ᴫ���ź�
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
        return true;//Ѫ��С�ڵ���0(���߱�ǩѪ��С��0������������������
    else
        return false;
}

int fighter::getatk() {//��ȡ������
    return this->atk;
}