#pragma once
#include "object.h"
class card;
class fighter :
    public object
{
public:

    fighter(int _x, int _y,int _cost,int _atk, int _hp, QString _name, QWidget* parent);
    fighter(int _x, int _y, card* c, QWidget* parent) {};
private:
    int cost;
    int atk;
    minilabel* atklabel;
    minilabel* hplabel;
    bool sleep;//是否沉睡 每回合只能攻击一次 故攻击后陷入沉睡
    QPoint startPoint;
    QPoint endPoint;
    bool isDrawing;
public:
    void wake();//合会开始时 如果沉睡 则唤醒
    bool dead();
    int getatk();//获取攻击力
    //获取当前血量
protected:
    //实现拖动出攻击
    void mousePressEvent(QMouseEvent* );//按下后卡牌外观发生轻微变化 指示准攻击
    void mouseMoveEvent(QMouseEvent* );//拖动选择目标
    void mouseReleaseEvent(QMouseEvent* );//释放时根据坐标选择行为 是攻击 还是无效
    void paintEvent(QPaintEvent*);
   
signals:
    //攻击需要请求上层容器服务  connect的是上层的fightspace容器
    void attack(fighter* attacker, QPoint pos) {};
    //向上层发送死亡信号 删除自己
    void die(fighter* me);
};

