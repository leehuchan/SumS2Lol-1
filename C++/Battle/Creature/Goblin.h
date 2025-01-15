#pragma once
#include "Monster.h"
class Knight;

class Goblin : public Monster
{
public:
	Goblin();
	Goblin(int hp, int atk, string name);
	~Goblin();

	virtual void Attack(Creature* other) override;
	void DeadSound();
	//void Attack(Knight* other);
	//void Attack(Archer* other);
	//void Attack(Mage* other);

private:
};

