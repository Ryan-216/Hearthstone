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
//���Ϸ������ĳ�ʼ��
minilabel::minilabel(QWidget* parent) {
	this->init();
	this->val = 1;//������Ϊ1�������б�//////*******************************************************************************/////
	this->setParent(parent);
	this->move(0, 0);//
}
//���½ǹ�����ǩ��ʼ��
minilabel::minilabel(int _val, int x, int y, QWidget* parent) {
	this->init();
	this->val = _val;
	this->setParent(parent);
	this->move(0,100);//
}
//����������ǩ��ʼ��
minilabel::minilabel(int _val,QWidget* parent) {
	this->init();
	this->val = _val;
	this->setParent(parent);
	this->move(75, 100);
}
//ͨ�ó�ʼ��
void minilabel::init() {
	this->resize(this->d, this->d);
	this->setFont(QFont("Microsoft YaHei", 18, QFont::Bold));
}

minilabel::minilabel(QWidget* parent)
{
}

minilabel::minilabel(int _val, QWidget* parent)
{
}

minilabel::minilabel(int _val, int x, int y, QWidget* parent)
{
}

void minilabel::init()
{
}
