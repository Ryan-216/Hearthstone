#include "minilabel.h"
#include <QLabel>
#include<QFont>
////�����ڿ�������ʾ����ֵ ������ ����ֵ��С��ǩ
//class minilabel :
//    public QLabel
//{
//public:
//    minilabel(QWidget* parent);//Ĭ��val=1 xy=00
//    minilabel(int _val,QWidget* parent);//Ĭ��xy=00
//    minilabel(int _val,int x,int y,QWidget* parent);
//    int val;//minilabel��ʾ��ֵ
//private:
//    //int val;//minilabel��ʾ��ֵ
//    int d=50;//С��ǩ�߳� Ĭ��50
//public:
//    void init();//ͨ�ó�ʼ�� ���ô�С ������ʽ����С ��ɫ�ȣ�
//
//
//};

minilabel::minilabel(int _val, int x, int y, QWidget* parent) {
	this->init();
	this->setParent(parent);
	this->val = _val;
	this->move(x,y);
}

void minilabel::init() {
	this->resize(this->d, this->d);
	this->setFont(QFont("Microsoft YaHei", 18, QFont::Bold));
}




