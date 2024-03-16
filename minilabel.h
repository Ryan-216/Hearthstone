#pragma once
#include <QLabel>
#include<QFont>
//用于在卡牌上显示法力值 攻击力 生命值的小标签
class minilabel :
    public QLabel
{
public:
    minilabel(QWidget* parent);//默认val=1 xy=00

    minilabel(int _val,QWidget* parent);//默认xy=00

    minilabel(int _val,int x,int y,QWidget* parent);

    //int val;//minilabel显示的值
private:
    int val;//minilabel显示的值
    int d=50;//小标签边长 默认50
public:
    void init();//通用初始化 设置大小 字体样式（大小 颜色等）


};

