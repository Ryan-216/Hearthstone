#pragma once
#include <qlabel.h>
#include <QMouseEvent>
#include <QPoint>
#include <QPaintEvent>
#include <qpainter.h>

class Hero;
class BattleScene;
class BaseCard :
    public QLabel
{  
    //Q_OBJECT //������ᱨ��  MSB4181	��QtRunWork�����񷵻��� false����δ��¼����

public:
    int widght_ = 60, height_ = 100;
    int attack_, blood_, cost_;
    QPoint start_pos_;
    QPoint end_pos_;
    int status_ = 0;//����״̬��0�����ƣ�1��ս����2������
    bool allow_click_ = true;
    void Attack(BaseCard* target);
    void Attack(Hero* target);
    void Death();
    bool isDragging = false;
    QPoint dragStartPos;
    QPoint startPos;
 
public: signals:
    void status_change() {};//״̬ת���źŲ�


    BaseCard()
    {
        //setMouseTracking(true);
        attack_ = 3;
        blood_ = 4;
        cost_ = 3;             
    }

public:
    void mousePressEvent(QMouseEvent* event) override {
       
        if (event->button() == Qt::LeftButton) {
            
            if (status_ != 2 && allow_click_ == true)
            {
                isDragging = true;
                dragStartPos = event->pos();
                startPos = this->pos();
                event->accept();
            }
            else if (status_ == 1);
            {
                QPoint event_parent = mapToParent(event->pos());
                startPoint = event_parent;
                endPoint = startPoint;
                isDrawing = true;
            }
            
        }
    }

    void mouseMoveEvent(QMouseEvent* event) override {
        if (isDrawing && status_==1) {
            QPoint event_parent = mapToParent(event->pos());
            endPoint = event_parent;
            update();

        }

        if (isDragging && status_ != 2 && allow_click_ == true) {

            QPoint diff = event->pos() - dragStartPos;
            this->move(pos() + diff);
            event->accept();
        }      
    }

    void mouseReleaseEvent(QMouseEvent* event) override {
        if (event->button() == Qt::LeftButton )
        {
            QPoint event_parent = mapToParent(event->pos());
            isDragging = false;
            //�л�����ϵ
            //qDebug()<<event->localPos().x();
            if (status_ != 2&& allow_click_ == true)
            {
                if (event_parent.x() >= 100 && event_parent.x() <= 700 && event_parent.y() >= 200 && event_parent.y() <= 400)
                {
                    status_ = 1;
                    emit status_change();
                }
                else
                {
                    this->move(startPos);
                    event->accept();
                    update();
                }
            }
            else if(status_==1)
            {
                endPoint = startPoint;
                isDrawing = false;
                update();
            }
           
        }
       
    }

    //void paintEvent(QPaintEvent* event) override {
    //    QPainter painter(this);
    //    painter.drawLine(startPoint, endPoint);
    //}

private:
    bool isDrawing;
    QPoint startPoint;
    QPoint endPoint;
};

