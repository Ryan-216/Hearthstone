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

void fightspace::onfighterattack(fighter* attacker, QPoint pos) {//���������ź� attacker����posλ�õ���� ����Ѫ�� 
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

