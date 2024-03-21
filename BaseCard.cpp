#include "BaseCard.h"
#include "Hero.h"


void BaseCard::Attack(BaseCard* target)
{
	target->blood_ -= this->attack_;
	this->blood_ -= target->attack_;
}

void BaseCard::Attack(Hero* target)
{
	target->blood_ -= this->attack_;
}

void BaseCard::Death()
{
	if (blood_ <= 0) status_ = 2;
}

int BaseCard::getRand(int min, int max)
{	
	return (rand() % (max - min + 1)) + min;
}

void BaseCard::refresh()
{
	QString text_blood = QString("%1").arg(blood_);
	QString text_attack = QString("%1").arg(attack_);
	QString text_cost = QString("%1").arg(cost_);
	blood_label.setText(text_blood);
	attack_label.setText(text_attack);
	cost_label.setText(text_cost);
}


