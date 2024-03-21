#pragma once
#include <QLabel>
#include<qobject.h>
#include<qlabel.h>
#include <QMouseEvent>
#include <QPoint>
#include <QPaintEvent>
#include <qpainter.h>
#include <ctime>
#include <cstdlib>

#include <random>
#include<qtimer.h>
class Hero;
class BattleScene;
class BaseCard :
    public QLabel
{  
    //Q_OBJECT //加这个会报错  MSB4181	“QtRunWork”任务返回了 false，但未记录错误。

public:
    int widght_ = 60, height_ = 100;
    int attack_, blood_, cost_;
    QPoint start_pos_;
    QPoint end_pos_;
    int status_ = 0;//卡牌状态，0：手牌，1：战斗，2：死亡
    bool allow_click_ = false;
    void Attack(BaseCard* target);
    void Attack(Hero* target);
    void Death();
    bool isDragging = false;
    bool isAttacker = false;
    QPoint dragStartPos;
    QPoint startPos;
    QLabel blood_label;
    QLabel attack_label;
    QLabel cost_label;
    int getRand(int min, int max);
    void refresh();

    
 
public: signals:
    void status_change() {};//状态转变信号槽

    BaseCard()
    {
       
        // 创建随机数引擎
        std::random_device rd;
        std::mt19937 gen(rd());

        // 创建分布器，指定范围为1-9
        std::uniform_int_distribution<> dis(1, 9);

        // 生成随机数
        int randomNum = dis(gen);

        attack_ =  randomNum + 1;
        blood_ = randomNum + 1;
        cost_ = randomNum;
        blood_label.setParent(this);
        attack_label.setParent(this);
        cost_label.setParent(this);
        QString text_blood = QString("%1").arg(blood_);
        QString text_attack = QString("%1").arg(attack_);
        QString text_cost = QString("%1").arg(cost_);
        blood_label.setAlignment(Qt::AlignCenter);
        attack_label.setAlignment(Qt::AlignCenter);
        cost_label.setAlignment(Qt::AlignCenter);
        blood_label.setText(text_blood);
        attack_label.setText(text_attack);
        cost_label.setText(text_cost);
        blood_label.setFixedSize(20, 20);
        attack_label.setFixedSize(20, 20);
        cost_label.setFixedSize(20, 20);
        blood_label.move(40,80);
        attack_label.move(0,80);
        cost_label.move(0,0);
    }

public:
    void enterEvent(QEnterEvent* event)override {

    }
    void leaveEvent(QEvent* event)override {

    }
    void mousePressEvent(QMouseEvent* event) override {
       
        if (event->button() == Qt::LeftButton) {
            
            if (status_ != 2 && allow_click_ == true)
            {
                isAttacker = false;
                isDragging = true;
                dragStartPos = event->pos();
                startPos = this->pos();
                event->accept();
            }
            /*else if (status_ == 1);
            {
                QPoint event_parent = mapToParent(event->pos());
                startPoint = event_parent;
                endPoint = startPoint;
                isDrawing = true;
            }*/
            
        }
    }

    void mouseMoveEvent(QMouseEvent* event) override {
        /*if (isDrawing && status_==1) {
            QPoint event_parent = mapToParent(event->pos());
            endPoint = event_parent;
            update();

        }*/

        if (isDragging && status_ != 2 && allow_click_ == true) {
            isAttacker = true;
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
            //切换坐标系
            //qDebug()<<event->localPos().x();
            if (status_ != 2 && allow_click_ == true)
            {
                if (event_parent.x() >= 100 && event_parent.x() <= 800 && event_parent.y() >= 200 && event_parent.y() <= 600)
                {
                    status_ = 1;
                    //emit status_change();
                }
                else
                {
                    this->move(startPos);
                    event->accept();
                    update();
                }
            }
            /*if(status_==1)
            {
                endPoint = startPoint;
                isDrawing = false;
                update();
            }*/
           
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

