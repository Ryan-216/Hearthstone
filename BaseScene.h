#pragma once
#include <qgraphicsscene.h>
#include <QGraphicsPixmapItem>
#include <QLabel>
#include <qstring.h>

class BaseScene :
    public QGraphicsScene
{
public:
    int width_ = 900, height_ = 800;
    QLabel bg_;

private:
    
};

