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



handcard::handcard(QWidget* parent)
{
	resize(1400, 197);
	this->bg = new QLabel(this);
	bg->setFixedSize(1400, 197);
	bg->setPixmap(QPixmap(":/assert/handcard.png"));
	// mycard.resize(9, nullptr);
	mycard.reserve(9);
	turnbutton = new QPushButton(this);
	turnbutton->resize(100, 100);
	turnbutton->move(0, 0);
	qDebug() << turnbutton->pos();
	turnbutton->setText("endturn");
	this->show();
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
		(*it)->move(mid_width - (i + 0.5 + num * 0.5) * card::w, 0);
		qDebug() << (*it)->x();
	}
}

void handcard::firstdraw()
{
	qDebug() << "firstdraw";
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
	qDebug() << "oncardlibsendcard";
	add(c);	
	qDebug() << mycard.size();
}
	