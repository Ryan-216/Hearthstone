#include "hearthstone.h"
#include"card.h"
#include<qpainter.h>
hearthstone::hearthstone(QWidget *parent)
    : QWidget(parent)
{
    resize(1400, 950);
    QPixmap pic("C:/Users/24318/Desktop/QTpng/lg4.jpg");
    card* c = new card(3, 1  ,4, "zms", QPoint(400,400), this);

    c->setScaledContents(true);
    c->setPixmap(pic);
    c->show();
}

hearthstone::~hearthstone()
{}

void hearthstone::on_card_postohearthstone(QPoint p, bool start) {
    if (start) {//传入的是开始坐标
        startPoint = p;
        endPoint = startPoint;
        isDrawing = true;
    }
    else {
        if (p.x() >= 0) {
            if (isDrawing) {
                endPoint = p;
                update();
            }
        }
        else {
            endPoint = startPoint;
            isDrawing = false;
            update();
        }
        
    }
}

void hearthstone::paintEvent(QPaintEvent* event)
{
    this->show();
    QPainter painter(this);
    painter.drawLine(startPoint, endPoint);
}

