#include "handcard.h"

void handcard::on_card_postohandcard(QPoint p, bool start)
{
	//接收到card中的鼠标坐标
	if (p.x() > 0) {
		emit postohearthstone(this->mapToParent(p), start);
	}
	else {
		emit postohearthstone(QPoint(-1,-1), true);
	}
	

}

void handcard::postohearthstone(QPoint p, bool strat)
{
}


handcard::handcard(QWidget* parent)
{
	mycard.resize(9, nullptr);
}

void handcard::add(card* c)
{
	mycard.push_back(c);
}

void handcard::remove(card*c)
{
	// find(mycard.begin(), mycard.end(), c);
	// mycard.erase(find(mycard.begin(), mycard.end(), c));
}
