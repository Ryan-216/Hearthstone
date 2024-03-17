#include "fightspace.h"
#include "card.h"
#include "fighter.h"

//战场中线
double mid_width = 1075 * 0.5;
double mid_height = 735 * 0.5;

void fightspace::myrefresh()//相对于战场的坐标
{
	
	int i = 0;
	//我方战场
	for (std::vector<fighter*>::iterator it = myspace.begin(); it < myspace.end(); it++, i++)
	{
		(*it)->move(mid_width - (i + mynum * 0.5 + 25) * card::w, 390);
	}
	//敌方战场
	for (std::vector<fighter*>::iterator it = enemyspace.begin(); it < enemyspace.end(); it++, i++)
	{
		(*it)->move(mid_width - (i + enemynum * 0.5 + 25) * card::w, 190);
	}
}

bool fightspace::on_handcard_useminion(card* c, QPoint pos)//传过来相对于战场的坐标，若是主窗口的需要转换，x()-=163;
{
	if (myspace.size() == 7) return false;
	int i = 0;//顺序
	for (std::vector<fighter*>::iterator it = myspace.begin(); it < myspace.end(); it++, i++)
	{
		if (pos.x() < (*it)->x() + card::w * 0.5) break;
	}
	for (int j = mynum - 1; j > i; j--)
	{
		myspace[j] = myspace[j - 1];
	}
	myspace[i] = new fighter(0,0,c,this);//需要通过card* 构造fighter
	myrefresh();
	return true;
}

fighter* fightspace::searchfighter(QPoint * p)//传过来相对于战场的坐标，若是主窗口的需要转换，x()-=163;
{
	int i = 0;
	if (p->y() > mid_height)//找我方fighter
	{
		for (std::vector<fighter*>::iterator it = myspace.begin(); it < myspace.end(); it++, i++)
		{
			if (p->x() - (*it)->x() <= card::w && p->x() - (*it)->x() >= 0 && p->y() - (*it)->y() <= card::h && p->y() - (*it)->y() >= 0)
				return (*it);
		}
	}
	else//找敌方fighter
	{
		for (std::vector<fighter*>::iterator it = enemyspace.begin(); it < enemyspace.end(); it++, i++)
		{
			if (p->x() - (*it)->x() <= card::w && p->x() - (*it)->x() >= 0 && p->y() - (*it)->y() <= card::h && p->y() - (*it)->y() >= 0)
				return (*it);
		}
	}
	return nullptr;
}

QPoint* fightspace::convert(QPoint* p)
{
	return new QPoint(p->x() - 163, y());
}