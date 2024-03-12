#pragma once
#include <qlabel.h>
#include <QMouseEvent>
#include <QPoint>
#include <QPaintEvent>
#include <qpainter.h>

class BaseCard :
    public QLabel
{

public:
    int widght_ = 60, height_ = 100;
    int attack_, blood_, cost_;
    QPoint start_pos_;
    QPoint end_pos_;
    int status_ = 0;//¿¨ÅÆ×´Ì¬£¬0£ºÊÖÅÆ£¬1£ºÕ½¶·£¬2£ºËÀÍö
 
    /*void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);*/
    
signals:
    // void status_change();

    BaseCard()
    {
        attack_ = 3;
        blood_ = 4;
        cost_ = 3;    
    }
public:
    void mousePressEvent(QMouseEvent* event) override {
        if (event->button() == Qt::LeftButton && status_ == 0) {
            /*QPoint event_parent = mapToParent(event->pos());
            startPoint = event_parent;
            endPoint = startPoint;
            isDrawing = true;*/

            isDragging = true;
            dragStartPos = event->pos();
            startPos = this->pos();
            event->accept();
        }
    }

    void mouseMoveEvent(QMouseEvent* event) override {
        /*if (isDrawing) {
            QPoint event_parent = mapToParent(event->pos());
            endPoint = event_parent;
            update();

        }*/

        if (isDragging && status_ == 0) {

            QPoint diff = event->pos() - dragStartPos;
            this->move(pos() + diff);
            event->accept();
        }
        
    }

    void mouseReleaseEvent(QMouseEvent* event) override {
        
        if (event->button() == Qt::LeftButton && status_ == 0) 
        {

           /* endPoint = startPoint;
            isDrawing = false;
            update();*/


            QPoint event_parent = mapToParent(event->pos());
            isDragging = false;
            //ÇÐ»»×ø±êÏµ
            //qDebug()<<event->localPos().x();
            
            if (event_parent.x() >= 100 && event_parent.x() <= 700 && event_parent.y() >= 200 && event_parent.y() <= 400)
            {
                status_ = 1;
                //status_change();
                qDebug() << status_;
            }
            else
            {               
                this->move(startPos);
                event->accept();
            }           
            update();
        }
       

    }
    /*void paintEvent(QPaintEvent* event) override {
        QPainter painter(this);
        painter.drawLine(startPoint, endPoint);
    }*/

private:
    bool isDragging;
    QPoint dragStartPos;
    QPoint startPos;

    bool isDrawing;
    QPoint startPoint;
    QPoint endPoint;
};

