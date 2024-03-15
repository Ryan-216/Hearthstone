#include "hero.h"
#include <QLabel>
#include<QFont>

//我方英雄
hero::hero(int _x, int _y, int _hp, QWidget* parent):object(_x, _y, _hp, parent)
{
	//this->resize(this->w, this->h);
	//this->hp = _hp;
	//this->setParent(parent);
	//this->move(_x,_y);
	//this->setFont(QFont("Microsoft YaHei", 18, QFont::Bold));
	//this->name = "xxxxxxxxxxxxxx";//我方英雄名（大概）
	//this->setText(this->name);
}
//敌方英雄
hero::hero(int _x, int _y, int _hp, std::string _name, QWidget* parent):object(_x,  _y,  _hp, _name, parent)
{
	//this->resize(this->w, this->h);
	//this->hp = _hp;
	//this->setParent(parent);
	//this->move(_x, _y);
	//this->setFont(QFont("Microsoft YaHei", 18, QFont::Bold));
	//this->setText(name);
}