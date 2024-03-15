#include "minilabel.h"
#include <QLabel>
#include<QFont>
////用于在卡牌上显示法力值 攻击力 生命值的小标签
//class minilabel :
//    public QLabel
//{
//public:
//    minilabel(QWidget* parent);//默认val=1 xy=00
//    minilabel(int _val,QWidget* parent);//默认xy=00
//    minilabel(int _val,int x,int y,QWidget* parent);
//    int val;//minilabel显示的值
//private:
//    //int val;//minilabel显示的值
//    int d=50;//小标签边长 默认50
//public:
//    void init();//通用初始化 设置大小 字体样式（大小 颜色等）
//
//
//};
//左上法力消耗初始化
minilabel::minilabel(QWidget* parent) {
	this->init();
	this->val = 1;//姑且设为1，后续有变//////*******************************************************************************/////
	this->setParent(parent);
	this->move(0, 0);//
}
//左下角攻击标签初始化
minilabel::minilabel(int _val, int x, int y, QWidget* parent) {
	this->init();
	this->val = _val;
	this->setParent(parent);
	this->move(0,100);//我也不知道一张卡多大，只能大致估算位置
}
//右下生命标签初始化
minilabel::minilabel(int _val,QWidget* parent) {
	this->init();
	this->val = _val;
	this->setParent(parent);
	this->move(0, 50);//咕
}
//通用初始化
void minilabel::init() {
	this->resize(this->d, this->d);
	this->setFont(QFont("Microsoft YaHei", 18, QFont::Bold));
}
