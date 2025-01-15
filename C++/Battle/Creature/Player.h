#pragma once

// h는 선언부
// h, cpp 결합
// => 링커

// 전방선언
#include "Creature/Creature.h"

class Creature;
// #include 를 하지 않는 이유

class Player : public Creature
{
public:
	Player(int hp, int atk, string name);
	~Player();

};
