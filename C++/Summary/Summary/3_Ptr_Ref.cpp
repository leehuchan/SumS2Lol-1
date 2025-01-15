#include <iostream>

using namespace std;

// 과제
// 1. 상수 선언방법 3가지
// 2. 포인터 연산
// 3. 배열, 배열과 포인터의 상관관계

struct Player
{
	// 멤버변수
	int hp;
	int atk;
};

// Call By Value
//void PrintPlayer(Player p) // 8 ~~~ 바이트 전달
//{
//	cout << p.hp << endl;
//	cout << p.atk << endl;
//}

void PrintPlayer(Player* ptr) // 4바이트
{
	cout << (*ptr).hp << endl;
	cout << (*ptr).atk << endl;
}

void PrintPlayer(Player& p) // 4 바이트 전달
{
	cout << p.hp << endl;
	cout << p.atk << endl;
}

void SetPlayer(Player* p, int hp, int atk)
{
	(*p).hp = hp;
	(*p).atk = atk;
}

void SetPlayer(Player& p, int hp, int atk)
{
	p.hp = hp;
	p.atk = atk;
}

int main()
{
	// . : 멤버접근연산자
	Player player;
	player.hp = 1;
	player.atk = 2;

	Player* ptr = &player;
	Player& ref = player;

	SetPlayer(player, 100, 5);
	//SetPlayer(&player, 100, 5);

	PrintPlayer(&player);

	return 0;
}