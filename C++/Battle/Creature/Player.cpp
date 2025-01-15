#include "pch.h"

#include "Creature.h"
#include "Player.h"

// cpp Á¤ÀÇ
Player::Player(int hp, int atk, string name)
: Creature(hp, atk)
{
	SetName(name);
}

Player::~Player()
{
}

