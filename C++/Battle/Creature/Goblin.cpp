#include "pch.h"

#include "Creature.h"
#include "Monster.h"
#include "Knight.h"
#include "Goblin.h"


Goblin::Goblin()
: Monster(50, 5)
{
}

Goblin::Goblin(int hp, int atk, string name)
: Monster(hp, atk)
{
	SetName(name);
}

Goblin::~Goblin()
{
}

void Goblin::DeadSound()
{
	cout << "²Ù¿¡¿¢!!!" << endl;
}

void Goblin::Attack(Creature* other)
{
	cout << _name << " Goblin Attack!!!" << endl;
	other->TakeDamage(_atk);
}
