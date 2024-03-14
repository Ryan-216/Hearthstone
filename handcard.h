#pragma once
#include <QWidget>
class card;
class hero;
class ability;
class handcard :
    public QWidget
{
public:
    handcard(QWidget* parent);
private:
    std::vector<card*>mycard;//手牌容器 至多9张
    //一开始初始化 vector大小就初始化为9 0-5有牌 6-8 nullptr
    int num;//当前手牌数量
public:
    void add(card* c);//向容器中加一张牌
    void remove(card* c);//单纯从容器中删除一张牌
    void refresh();//刷新手牌 调整位置 发生于add 和remove中
    void firstdraw();//初始抽牌
    void playcard(card* c);//出牌 删除出的手牌 发送信号
public:
    int w;
    int h;
    QPoint pos;
public slots:
    void on_card_use(card* c, QPoint* pos);//与card的use信号connect 处理出牌事件 
    //需要做2件事  1.删除出的牌 2.向战场容器发指定信号
    void on_ability_use(ability* a, QPoint* pos);

public  slots:
    void on_cardlib_sendcard(card* c);//接收卡牌 加入手牌

signals:
    void draw(int num);
    void useminion(card* c, QPoint pos);
    void usedirspell(card* c, QPoint pos);
    void usenodirspell(card* c);
    void useability(ability* a, QPoint* pos);
};

