#include "card.h"
//如果每个构造函数里都把初始化尺寸这些写上 如果要修改需要改多个地方 
//不如把这些常规初始化写到init里再由构造函数调用 改起来只需要改init
void card::init()
{
	//初始化常规项 如尺寸
}

bool card::operator==(card* c)
{
	if (this->id == c->id) return true;
	else return false;
}
