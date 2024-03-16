#pragma once
#include "label.h"
class minilabel;
class object :
    public label
{
public:
    object() {};///////
   // object(int _x,int _y,int _hp,QWidget* parent);
    object(int _x,int _y, int _hp, QString _name,QWidget* parent);

protected:
    int hp;
    minilabel* hplabel;
    //std::string name;
    QString name;
    int w;
    int h;
    QPoint pos;
public:
    void losehp(int val);
    void init();//通用初始化 大小 字体 图片自适应等
};

