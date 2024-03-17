#include "fightspace.h"
#include "card.h"
#include "fighter.h"

//ս������
double mid_width = 1075 * 0.5;
double mid_height = 735 * 0.5;

void fightspace::myrefresh()//�����ս��������
{
	
	int i = 0;
	//�ҷ�ս��
	for (std::vector<fighter*>::iterator it = myspace.begin(); it < myspace.end(); it++, i++)
	{
		(*it)->move(mid_width - (i + mynum * 0.5 + 25) * card::w, 390);
	}
	//�з�ս��
	for (std::vector<fighter*>::iterator it = enemyspace.begin(); it < enemyspace.end(); it++, i++)
	{
		(*it)->move(mid_width - (i + enemynum * 0.5 + 25) * card::w, 190);
	}
}

bool fightspace::on_handcard_useminion(card* c, QPoint pos)//�����������ս�������꣬���������ڵ���Ҫת����x()-=163;
{
	if (myspace.size() == 7) return false;
	int i = 0;//˳��
	for (std::vector<fighter*>::iterator it = myspace.begin(); it < myspace.end(); it++, i++)
	{
		if (pos.x() < (*it)->x() + card::w * 0.5) break;
	}
	for (int j = mynum - 1; j > i; j--)
	{
		myspace[j] = myspace[j - 1];
	}
	myspace[i] = new fighter(0,0,c,this);//��Ҫͨ��card* ����fighter
	myrefresh();
	return true;
}

fighter* fightspace::searchfighter(QPoint * p)//�����������ս�������꣬���������ڵ���Ҫת����x()-=163;
{
	int i = 0;
	if (p->y() > mid_height)//���ҷ�fighter
	{
		for (std::vector<fighter*>::iterator it = myspace.begin(); it < myspace.end(); it++, i++)
		{
			if (p->x() - (*it)->x() <= card::w && p->x() - (*it)->x() >= 0 && p->y() - (*it)->y() <= card::h && p->y() - (*it)->y() >= 0)
				return (*it);
		}
	}
	else//�ҵз�fighter
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