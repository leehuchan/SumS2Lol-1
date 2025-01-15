#include <iostream>

using namespace std;

// . : 멤버연산자
// -> : 간접멤버연산자 ( * .)

struct Player
{
	// 멤버 변수
	string name;
	int hp;
	int atk;
};

// Call By Value
// 단점
// => 원본에 접근할 수 없다.
// => 매개변수로 생성하는 바이트가 크다.
//void PrintPlayer(Player p)
//{
//	cout << "NAME : " << p.name << endl;
//	cout << "HP : " << p.hp << endl;
//	cout << "ATK : " << p.atk << endl;
//}

// Call By Address
// => 원본에 접근할 수 있다.
// => nullptr을 담을 수 있다.

// 단점
// => nullptr 체크
void PrintPlayer(const Player* const p)
{
	if (p == nullptr) return;

	cout << "NAME : " << p->name << endl;
	cout << "HP : " << p->hp << endl;
	cout << "ATK : " << p->atk << endl;
}

// Call By Reference
// => 원본에 접근할 수 있다.
// => 쓰기 쉽다.

// 단점
// => Call By Value와 구분할 수 없다.
void PrintPlayer(const Player& p) // => C++ 읽기전용
{
	cout << "NAME : " << p.name << endl;
	cout << "HP : " << p.hp << endl;
	cout << "ATK : " << p.atk << endl;
}

void SetPlayer(Player* p, string name, int hp, int atk)
{
	p->name = name;
	p->hp = hp;
	(*p).atk = atk;
}

void SetPlayer(Player& p, const string& name, int hp, int atk)
{
	p.name = name;
	p.hp = hp;
	p.atk = atk;
}

int main()
{
	Player p;
	p.name = "";
	p.hp = 1;
	p.atk = 2;
	PrintPlayer(p);


	return 0;
}