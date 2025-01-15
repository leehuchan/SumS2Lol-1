#include "pch.h"
#include "Creature.h"
#include "Player.h"
#include "Goblin.h"
#include "Knight.h"

Knight::Knight(int hp, int atk, string name)
: Player(hp,atk,name)
{
}

Knight::~Knight()
{
}

void Knight::Attack(Creature* other)
{
	cout << _name << " Knight Attack!!!" << endl;
	other->TakeDamage(_atk);
}
