#include "handcard.h"

#include "card.h"



void handcard::onsendpos2space(QPoint p, bool start) {
	setStyleSheet("border-width: 4px;border-style: solid;border-color: rgb(255,0, 255);");
	emit send2main(p, start);
	setAttribute(Qt::WA_TranslucentBackground);
}

//QSize handcard::sizeHint() const {
//	return QSize(1400, 197);
//}

void handcard::pow_add()
{
	if (pow_max < 10)pow_max++;
	pow_remain = pow_max;
}

handcard::handcard(QWidget* parent)
{
	//setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
	//hide();
	resize(1400, 197);
	this->bg = new QLabel(this);
	bg->setFixedSize(1400, 197);
	// mycard.resize(9, nullptr);
	mycard.reserve(9);
}

void handcard::add(card* c)
{
	c->setParent(this);
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
		(*it)->move(mid_width - (mycard.size() * 0.5 - i) * card::w, 0);
		(*it)->show();
		qDebug() << i << (*it)->x();
	}
	
}

void handcard::drawcard(int n)
{
	if (mycard.size() + n <= 9) emit draw(n);
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
}
	