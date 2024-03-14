#pragma once
class card;
#include<vector>
#include"label.h"
//类简介
//兼具存储卡牌的仓库 和 场上可见的牌库 2个功能 继承label 
//分为专门存储随从牌的minionlib 专门存储法术牌的spelllib 和总牌库lib 
//功能是存储卡牌和为手牌提供抽牌服务（信号与槽）

class cardlib:
	public label
{
public:
	cardlib();
private:
	std::vector<card*>minionlib;//随从牌库
	std::vector<card*>spelllib;//法术牌库
	std::vector<card*>lib;//总牌库=随从牌库+法术牌库
public:
	card* randoncard();//随机获取卡牌
	card* randonminion();//随机获取随从
	card* randonspell();//随机获取法术
	card* getcard(int x);//按下标获取卡牌
	card* getminion(int x);//按下标获取随从
	card* getcspell(int x);//按下标获取法术

signals:
	void sendcard(card*c);//给handcard发送卡牌 完成抽卡的操作
public slots:
	void on_handcard_draw(int num);//接收到手牌的抽牌信号后准备卡牌 发还给handcard 调用sendcard信号


};

