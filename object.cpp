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
object::object(int _x, int _y, int _hp, QWidget* parent) {
	this->init();
	this->hp = _hp;
	this->hplabel = new minilabel(_hp, this);

}
//敌方
object::object(int _x, int _y, int _hp, std::string _name, QWidget* parent) {
	this->init();
	this->hp = _hp;
	this->hplabel = new minilabel(_hp, this);
}
void object::losehp(int val) {
	this->hp -= val;
}
void object::init() {
	this->resize(this->w,this->h);
	this->setFont(QFont("Microsoft YaHei", 18, QFont::Bold));
	this->setAlignment(Qt::AlignCenter);//名字居中显示
	this->setText(this->name);
	//调整位置
}