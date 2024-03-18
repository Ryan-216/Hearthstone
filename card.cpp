#include "card.h"
#include"minilabel.h"
#include<QMouseEvent>
#include <QPaintEvent>
#include <qpainter.h>

card::card()
{
	init();
	this->setPixmap(QPixmap(":/assert/minion.png"));
}
card::card(int _cost, void(*_dirfp)(QPoint target), std::string _name, QPoint p, QWidget* parent):QLabel(parent)
{
	init();
	cost = _cost;
	costlabel = new minilabel(cost, 0, 0, this);
	name = _name;
	pos = p;
	this->move(pos);
	dirfp = _dirfp;
	type = DIRSPELL;
}

card::card(int _cost,  std::string _name, void(*nondirfp)(), QPoint p, QWidget* parent) :QLabel(parent)
{
	init();
	cost = _cost;
	costlabel = new minilabel(cost, 0, 0, this);
	name = _name;
	pos = p;
	this->move(pos);
	nondirfp = nondirfp;
	type = NONDIRSPELL;
}

card::card(int _cost, int _atk, int _hp, std::string _name, QPoint p, QWidget* parent) :QLabel(parent)
{
	init();
	cost = _cost;
	costlabel = new minilabel(cost, 0, 0, this);
	name = _name;
	pos = p;
	this->move(pos);
	atk = _atk;
	hp = _hp;
	atklabel = new minilabel(atk, 0, 100,this);
	hplabel = new minilabel(hp, 75, 100,this);
	type = MINION;
}


int card::getcost()
{
	return cost;
}

int card::getatk()
{
	return atk;
}

int card::gethp()
{
	return hp;
}

void card::init()
{
	//初始化常规项 如尺寸
	w = 125; h = 150;
	W = 250; H = 300;
	resize(w, h);
}

void card::enterEvent(QEnterEvent* event)
{
	//加边框 显示说明
	setToolTip("点击超链接显示URL");
	setStyleSheet("border-width: 3px;border-style: solid;border-color: rgb(255, 0, 0);");
}

void card::leaveEvent(QEvent* event)
{
	//去除边框 删除说明
	setStyleSheet("border-width: 0px;border-style: solid;border-color: rgb(255, 0, 0);");
}

void card::mousePressEvent(QMouseEvent* event)
{
	if (type != DIRSPELL) {
		emit sendpos2space(mapToParent(event->pos()), true);
	}
	else {
		//记录鼠标的世界坐标.
		m_point = event->globalPos();
		//记录窗体的世界坐标.
		m_pos = this->frameGeometry().topLeft();
	}
	

}

void card::mouseMoveEvent(QMouseEvent* event)
{

	if (type != DIRSPELL) {
		emit sendpos2space(mapToParent(event->pos()), false);
	}
	else {
		//移动中的鼠标位置相对于初始位置的相对位置.
		QPoint relativePos = event->globalPos() - m_point;
		//然后移动窗体即可.
		pos = m_pos + relativePos;
		this->move(pos);
	}
}

void card::mouseReleaseEvent(QMouseEvent* event)
{
	if (type == DIRSPELL) {
		emit sendpos2space(QPoint(-1,-1), true);
	}
	else {
		if (event->pos().y() < 750) {
			emit use(this, event->pos());

		}
		else {
			//回原地 需要xy
		}


	}
}

bool card::operator==(card* c)
{
	if (this->id == c->id) return true;
	else return false;
}

int card::w = 125;
int card::h = 150;
QString card::getname() {
	return QString::fromStdString(this->name);
}