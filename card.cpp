#include "card.h"
#include"minilabel.h"
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

card::card(int _cost, void(*nondirfp)(), std::string _name, QPoint p, QWidget* parent)
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

card::card(int _cost, int _atk, int _hp, std::string _name, QPoint p, QWidget* parent)
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
	resize(W, H);
	pos = QPoint(pos.x() - 62, pos.y() - 150);
	move(pos);
	costlabel->move(0,0);
	if (type = MINION) {
		atklabel->move(0, H - 50);
		hplabel->move(W - 50, H - 50);
	}
	
}

void card::leaveEvent(QEvent* event)
{
	resize(w, h);
	pos = QPoint(pos.x() + 62, pos.y() + 150);
	move(pos);
	costlabel->move(0, 0);
	if (type = MINION) {
		atklabel->move(0, h - 50);
		hplabel->move(w - 50, h - 50);
	}
}

void card::mousePressEvent(QMouseEvent* event)
{
}

void card::mouseMoveEvent(QMouseEvent* event)
{
}

void card::mouseReleaseEvent(QMouseEvent* event)
{
}
