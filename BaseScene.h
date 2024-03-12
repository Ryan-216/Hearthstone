#pragma once
#include <qgraphicsscene.h>
#include <QGraphicsPixmapItem>

class BaseScene :
    public QGraphicsScene
{
public:
    int width_ = 900, height_ = 600;
    QGraphicsPixmapItem bg_;

private:
    
};

