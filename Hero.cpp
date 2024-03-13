#include "Hero.h"

void Hero::spell_fresh()
{
	if (max_spell < 10)max_spell++;
	remain_spell_ = max_spell;
}