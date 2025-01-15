#pragma once

#include "Creature/Player.h"
class Player;

class Knight : public Player
{
public:
	Knight(int hp, int atk, string name);
	~Knight();

	// 함수 오버라이딩
	virtual void Attack(Creature* other) override;

private:

};

