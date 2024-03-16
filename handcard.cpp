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


