#pragma once
#include <qgraphicsscene.h>
#include <QGraphicsPixmapItem>
#include <QLabel>

class BaseScene :
    public QGraphicsScene
{
public:
    int width_ = 900, height_ = 600;
    QLabel bg_;

private:
    
};

