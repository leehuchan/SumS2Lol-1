#include "pch.h"

// 과제
// 1. Creature 최상위 부모, 추상클래스
// 2. Goblin 10마리 vs (아처,메이지,나이트) 싸우기


#include <string>

#include "Creature/Creature.h"
#include "Creature/Player.h"
#include "Creature/Knight.h"
#include "Creature/Goblin.h"

bool IsAllDead(Creature* arr[], int size)
{
	bool allDead = true;

	for (int i = 0; i < size; i++)
	{
		if (arr[i]->IsDead() == false)
			return false;
	}

	return allDead;
}

int main()
{
	Creature* k = nullptr;

	int choice = 0;

	cin >> choice;

	switch (choice)
	{
	case 1:
	{
		k = new Knight(100, 5, "hanil");
		break;
	}
	case 2:
	{
		//k = new Archer(550, 2, "hanil2");
		break;
	}
	case 3:
	{
		//k = new Mage(101, 13, "asdasd");
		break;
	}

	default:
		k = new Knight(100, 5, "hanil");
		break;
	}

	// Goblin : 800바이트
	Creature* goblins[10] = {};
	for (int i = 0; i < 10; i++)
	{
		goblins[i] = new Goblin();
	}

	for (int i = 0; i < 10; i++)
	{
		goblins[i]->SetName("Goblin" + to_string(i));
	}

	while (true)
	{
		// k가 죽거나
		if (k->IsDead())
			break;

		// 모든 고블린 사망
		if (IsAllDead(goblins, 10))
			break;

		for (int i = 0; i < 10; i++)
		{
			k->Attack(goblins[i]);
			goblins[i]->Attack(k);
		}
	}


	// 만약에 고블린1이 죽었다면 DeadSound 출력
	if (goblins[1]->IsDead())
		((Goblin*)goblins[1])->DeadSound(); // ?
	
	for (int i = 0; i < 10; i++)
	{
		delete goblins[i];
	}

	delete k;

	return 0;
}