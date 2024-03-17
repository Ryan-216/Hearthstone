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
//    void init();//ͨ�ó�ʼ�� ��С ���� ͼƬ����Ӧ��
//};
//�ҷ�
//object::object(int _x, int _y, int _hp, QWidget* parent) {
//	this->init();
//	this->name = "xxxxxxx";//��������
//	this->setParent(parent);
//	this->hp = _hp;
//	this->hplabel = new minilabel(_hp, this);
//
//}

object::object(int _x, int _y, int _hp, QString _name, QWidget* parent) {
	this->name = _name;//��������
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
	this->setAlignment(Qt::AlignCenter);//���־�����ʾ
	this->setText(this->name);

	//����λ��
}