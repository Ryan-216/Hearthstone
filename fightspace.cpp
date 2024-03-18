#include "fightspace.h"
#include "card.h"
#include"fighter.h"
#include"ability.h"

void fightspace::onhandcardusedirspell(card* c, QPoint pos) {//�����Ʒ���ʹ��ָ�������ź�ʱ ս��������Ӧ�仯 
	c->dirfp(pos);//�ͷŷ���
	//�ж��Ƿ��н�ɫ����
	for (auto it = myspace.begin(); it < myspace.end(); it++) {
		if ((*it)->dead()) myremove(*it);//�Ƴ�
	}
	for (auto it = enemyspace.begin(); it < enemyspace.end(); it++) {
		if ((*it)->dead()) enemyremove(*it);//�Ƴ�
	}
}

void fightspace::onhandcardusenodirspell(card* c) {//�����Ʒ���ʹ�÷�ָ�������ź�ʱ ս��������Ӧ�仯 
	c->nondirfp();//�ͷŷ�����ӦЧ��
	//�ж��Ƿ��н�ɫ����
	for (auto it = myspace.begin(); it < myspace.end();it++ ) {
		if ((*it)->dead()) myremove(*it);//�Ƴ�
	}
	for (auto it = enemyspace.begin(); it < enemyspace.end(); it++) {
		if ((*it)->dead()) enemyremove(*it);//�Ƴ�
	}
}

void fightspace::onhandcarduseability(ability* a, QPoint* pos) {//��Ӣ�ۼ���ʹ��ʱ ս��������Ӧ�仯
	a->dirfp(*pos);
	//�ж��Ƿ��н�ɫ����
	for (auto it = myspace.begin(); it < myspace.end(); it++) {
		if ((*it)->dead()) myremove(*it);//�Ƴ�
	}
	for (auto it = enemyspace.begin(); it < enemyspace.end(); it++) {
		if ((*it)->dead()) enemyremove(*it);//�Ƴ�
	}
}

void fightspace::onfighterattack(fighter* attacker, QPoint pos) {//�����������ź� attacker����posλ�õ���� ����Ѫ�� 
	for (auto it = enemyspace.begin(); it < enemyspace.end(); it++) {
		if (((*it)->mapToParent((*it)->pos()).x() + 125) >= pos.x() >= (*it)->mapToParent((*it)->pos()).x() && ((*it)->mapToParent((*it)->pos()).y() + 150) >= pos.y() >= (*it)->mapToParent((*it)->pos()).y()) {
			//������������빥����Ч//
			(*it)->losehp(attacker->getatk());//�����������Ѫ������,����ֵΪattacker�Ĺ���
			attacker->losehp((*it)->getatk());//�����ߵ�����ֵ����٣�����ֵΪ��������ӵĹ���
		}
	}

	//�ж��Ƿ��н�ɫ����
	for (auto it = myspace.begin(); it < myspace.end(); it++) {
		if ((*it)->dead()) myremove(*it);
	}
	for (auto it = enemyspace.begin(); it < enemyspace.end(); it++) {
		if ((*it)->dead()) enemyremove(*it);
	}

}


//ս������
double mid_width = 1075 * 0.5;
double mid_height = 735 * 0.5;

void fightspace::enemyadd(fighter* f)
{
	enemyspace.push_back(f);
}

void fightspace::enemyremove(fighter* f)
{
	for (std::vector<fighter*>::iterator it = enemyspace.begin(); it < enemyspace.end(); it++)
	{
		if ((*it) == f) myspace.erase(it);
	}
}

void fightspace::myadd(fighter* f)
{
	myspace.push_back(f);
}

void fightspace::myremove(fighter* f)
{
	for (std::vector<fighter*>::iterator it = myspace.begin(); it < myspace.end(); it++)
	{
		if ((*it) == f) myspace.erase(it);
	}
}

void fightspace::myrefresh()//�����ս��������
{
	int i = 0;
	//�ҷ�ս��
	for (std::vector<fighter*>::iterator it = myspace.begin(); it < myspace.end(); it++, i++)
	{
		(*it)->move(mid_width - ( - i + mynum * 0.5 + 25) * card::w, 390);
	}
	//�з�ս��
	for (std::vector<fighter*>::iterator it = enemyspace.begin(); it < enemyspace.end(); it++, i++)
	{
		(*it)->move(mid_width - ( - i + enemynum * 0.5 + 25) * card::w, 190);
	}
}

bool fightspace::onhandcarduseminion(card* c, QPoint pos)//�����������ս�������꣬���������ڵ���Ҫת����x()-=163;
{
	qDebug() << "onhandcarduseminion";
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