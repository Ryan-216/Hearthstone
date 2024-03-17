#include "fightspace.h"
#include "card.h"
#include"fighter.h"
#include"ability.h"

void fightspace::onhandcardusedirspell(card* c, QPoint pos) {//当手牌发出使用指向法术的信号时 战场发生相应变化 
	c->dirfp(pos);//释放法术
	//判断是否有角色死亡
	for (auto it = myspace.begin(); it < myspace.end(); it++) {
		if ((*it)->dead()) myremove(*it);//移除
	}
	for (auto it = enemyspace.begin(); it < enemyspace.end(); it++) {
		if ((*it)->dead()) enemyremove(*it);//移除
	}
}

void fightspace::onhandcardusenodirspell(card* c) {//当手牌发出使用非指向法术的信号时 战场发生相应变化 
	c->nondirfp();//释放法术相应效果
	//判断是否有角色死亡
	for (auto it = myspace.begin(); it < myspace.end();it++ ) {
		if ((*it)->dead()) myremove(*it);//移除
	}
	for (auto it = enemyspace.begin(); it < enemyspace.end(); it++) {
		if ((*it)->dead()) enemyremove(*it);//移除
	}
}

void fightspace::onhandcarduseability(ability* a, QPoint* pos) {//当英雄技能使用时 战场发生相应变化
	a->dirfp(*pos);
	//判断是否有角色死亡
	for (auto it = myspace.begin(); it < myspace.end(); it++) {
		if ((*it)->dead()) myremove(*it);//移除
	}
	for (auto it = enemyspace.begin(); it < enemyspace.end(); it++) {
		if ((*it)->dead()) enemyremove(*it);//移除
	}
}

void fightspace::onfighterattack(fighter* attacker, QPoint pos) {//处理攻击的信号 attacker攻击pos位置的随从 更新血量 
	for (auto it = enemyspace.begin(); it < enemyspace.end(); it++) {
		if (((*it)->mapToParent((*it)->pos()).x() + 125) >= pos.x() >= (*it)->mapToParent((*it)->pos()).x() && ((*it)->mapToParent((*it)->pos()).y() + 150) >= pos.y() >= (*it)->mapToParent((*it)->pos()).y()) {
			//可以在这里插入攻击特效//
			(*it)->losehp(attacker->getatk());//被攻击的随从血量减少,减少值为attacker的攻击
			attacker->losehp((*it)->getatk());//攻击者的生命值会减少，减少值为被攻击随从的攻击
		}
	}

	//判断是否有角色死亡
	for (auto it = myspace.begin(); it < myspace.end(); it++) {
		if ((*it)->dead()) myremove(*it);
	}
	for (auto it = enemyspace.begin(); it < enemyspace.end(); it++) {
		if ((*it)->dead()) enemyremove(*it);
	}

}

