#include "power.h"

power::power(QWidget* parent):QLabel(parent)
{
	max = 0;
	cur = 0;
	text = "0/0";
}

void power::increase(int val)
{
	max++;
}

void power::consume(int val)
{
	//法力值是否足够？
	cur -=val;
	text = QString::fromStdString(std::to_string(cur) + "/" + std::to_string(max));
	setText(text);
}

void power::refresh()
{
	cur = max;
	text = QString::fromStdString(std::to_string(cur) + "/" + std::to_string(max));
	setText(text);
}
