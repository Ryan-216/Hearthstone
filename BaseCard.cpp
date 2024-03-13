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


