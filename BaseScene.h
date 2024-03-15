#pragma once
#include <qgraphicsscene.h>
#include <QGraphicsPixmapItem>
#include <QLabel>
#include <qstring.h>

class BaseScene :
    public QGraphicsScene
{
public:
    int width_ = 1400, height_ = 950;
    QLabel bg_;

private:

};

