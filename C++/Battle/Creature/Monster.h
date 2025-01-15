#pragma once
#include "Creature.h"

class Monster : public Creature
{
public:
	Monster(int hp, int atk);
	~Monster();
};

