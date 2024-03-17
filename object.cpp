#include "object.h"
#include "label.h"
#include"minilabel.h"
//class minilabel;
//class object :
//    public label
//{
//public:
//    object() {};///////
//    object(int _x, int _y, int _hp, QWidget* parent);
//    object(int _x, int _y, int _hp, std::string _name, QWidget* parent);
//
//protected:
//    int hp;
//    minilabel* hplabel;
//    std::string name;
//    int w;
//    int h;
//    QPoint pos;
//public:
//    void losehp(int val);
//    void init();//通用初始化 大小 字体 图片自适应等
//};
//我方
//object::object(int _x, int _y, int _hp, QWidget* parent) {
//	this->init();
//	this->name = "xxxxxxx";//名字设置
//	this->setParent(parent);
//	this->hp = _hp;
//	this->hplabel = new minilabel(_hp, this);
//
//}

object::object(int _x, int _y, int _hp, QString _name, QWidget* parent) {
	this->name = _name;//名字设置
	this->setParent(parent);
	this->init();
	
	this->hp = _hp;
	this->hplabel = new minilabel(_hp,75,100, this);
}

void object::losehp(int val) {
	this->hp -= val;
}

void object::init() {
	w = 125;
	h = 150;
	this->resize(this->w,this->h);
	this->setFont(QFont("Microsoft YaHei", 18, QFont::Bold));
	this->setAlignment(Qt::AlignCenter);//名字居中显示
	this->setText(this->name);

	//调整位置
}