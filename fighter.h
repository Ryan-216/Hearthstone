#pragma once
#include "object.h"
class card;
class fighter :
    public object
{
public:
    fighter(int _x, int _y,int _cost,int _atk, int _hp,  QWidget* parent);
    fighter(int _x, int _y,int _cost,int _atk, int _hp, std::string _name, QWidget* parent);
    fighter(int _x, int _y, card* c, QWidget* parent);
private:
    int cost;
    int atk;
    minilabel* atklabel;
    bool sleep;//是否沉睡 每回合只能攻击一次 故攻击后陷入沉睡
public:
    void wake();//合会开始时 如果沉睡 则唤醒
    bool dead();
    void hit(QPoint p);
    int getatk();//获取攻击力
protected:
    //实现拖动出攻击
    void mousePressEvent(QMouseEvent* event);//按下后卡牌外观发生轻微变化 指示准攻击
    void mouseMoveEvent(QMouseEvent* event);//拖动选择目标
    void mouseReleaseEvent(QMouseEvent* event);//释放时根据坐标选择行为 是攻击 还是无效
   
signals:
    //攻击需要请求上层容器服务  connect的是上层的fightspace容器
    void attack(fighter* attacker, QPoint pos);
    //向上层发送死亡信号 删除自己
    void die(fighter* me);
};

