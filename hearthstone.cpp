#include "hearthstone.h"
#include"card.h"
hearthstone::hearthstone(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    resize(1400, 950);
    QPixmap pic("C:/Users/24318/Desktop/QTpng/lg4.jpg");
    card* c = new card(3, 1, 4, "zms", QPoint(100,100), this);
    c->setScaledContents(true);
    c->setPixmap(pic);
}

hearthstone::~hearthstone()
{}
