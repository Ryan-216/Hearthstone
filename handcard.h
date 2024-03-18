#pragma once
#include <QWidget>
#include <algorithm>
#include<QPushButton>
#include <qlabel.h>
class card;
class hero;
class ability;
class handcard :
    public QWidget
{
    Q_OBJECT
    //handcard内部自己维护一个法力水晶（逻辑）
private:
    int pow_max = 1;
    int pow_remain = 1;
    
public:
    void pow_add();
public:

    handcard(QWidget* parent);
    
    //QSize sizeHint()const;
private:
    std::vector<card*>mycard;//手牌容器 至多9张√
    QPushButton* turnbutton;
    QLabel* bg;
    //一开始初始化 vector大小就初始化为9 0-5有牌 6-8 nullptr√
    int num = 0;//当前手牌数量√
public:
    void add(card* c);//向容器中加一张牌√
    void remove(card* c);//单纯从容器中删除一张牌√
    void refresh();//刷新手牌 修改坐标√
    void drawcard(int n);//初始抽牌信号√
    // void playcard(card* c);//出牌 删除出的手牌 发送信号
public:
    int w;
    int h;

public slots:
    void on_card_use(card* c, QPoint* pos);//出哪张牌，出到哪里坐标√
    //需要做2件事  1.删除出的牌 2.向战场容器发指定信号
   
public  slots:
    void oncardlibsendcard(card* c);//接收卡牌 加入手牌


public slots:
    void onsendpos2space(QPoint p, bool start);
   
signals:
    void send2main(QPoint p, bool start);

signals:
    void costpower(int val);//向power发送信号 消耗量val个水晶
    void draw(int num) ;
    void useminion(card* c, QPoint* pos);
    void usedirspell(card* c, QPoint* pos) ;
    void usenodirspell(card* c) ;
    void useability(ability* a, QPoint* pos) ;
    //void postohearthstone(QPoint p, bool strat) ;//将在主窗口坐标系中的坐标传给主窗口

};

