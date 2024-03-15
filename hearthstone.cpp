#include "hearthstone.h"
#include"card.h"
hearthstone::hearthstone(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    resize(1400, 950);
    QPixmap pic("C:/Users/24318/Desktop/QTpng/lg4.jpg");
    card* c = new card(3, 1  ,4, "zms", QPoint(400,400), this);

    c->setScaledContents(true);
    c->setPixmap(pic);
    c->show();
}

hearthstone::~hearthstone()
{}
