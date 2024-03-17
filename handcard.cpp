#include "handcard.h"
#include <qlabel.h>
#include "card.h"

void handcard::oncardpostohandcard(QPoint p, bool start)
{
	//接收到card中的鼠标坐标
	if (p.x() > 0) {
		emit postohearthstone(this->mapToParent(p), start);
	}
	else {
		emit postohearthstone(QPoint(-1,-1), true);
	}
	

}




handcard::handcard(QWidget* parent)
{
	mycard.resize(9, nullptr);
}

void handcard::add(card* c)
{
	mycard.push_back(c);
	refresh();
}

void handcard::remove(card*c)
{
	for (auto it = mycard.begin(); it < mycard.end(); it++)
	{
		if ((*it) == c) mycard.erase(it);
	}
	refresh();
	// find(mycard.begin(), mycard.end(), c);
	// mycard.erase(find(mycard.begin(), mycard.end(), c));
}

void handcard::refresh()
{	
	double mid_width = 700;
	int i = 0;	
	for (std::vector<card*>::iterator it = mycard.begin(); it < mycard.end(); it++,i++)
	{
		(*it)->move(mid_width - (i + num * 0.5) * card::w, 780);
	}
}

void handcard::firstdraw()
{
	emit draw(3);
}


void handcard::on_card_use(card* c, QPoint* pos)
{
	remove(c);
	switch (c->card_type)
	{
	case card::CARDTYPE::MINION:
	{
		emit useminion(c, pos);
		break;
	}
	case card::CARDTYPE::DIRSPELL:
	{
		emit usedirspell(c, pos);
		break;
	}
	case card::CARDTYPE::NONDIRSPELL:
	{
		emit usenodirspell(c);
		break;
	}
	default:
		break;
	}
}
void handcard::oncardlibsendcard(card* c)
{
	add(c);
	refresh();
}
	