#pragma once
#include <QLabel>
class power :
    public QLabel
{
public:
    power(QWidget* parent);
private:
    int max;//当前法力值上限
    int cur;//当前法力值
    QString text;//QLabel上显示的文字  如5/6
public:
    void increase(int val);//获得val个水晶 增加的是上限
    void consume(int val);//消耗val个水晶
    void refresh();//每回合开始充满水晶
    
    //法力值是否足够使用卡牌？

};

