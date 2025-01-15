#include <iostream>

using namespace std;

class Player
{
public:
	Player(int hp) : _hp(hp), _atk(0) { cout << "타입변환 생성자 호출" << endl; }
	
	// 역할
	// 1. 동적할당 해제
	// 2. 소멸처리
	~Player() { cout << "소멸자 호출" << endl; }

protected:
	int _hp;
	int _atk;
};

class Knight : public Player
{
public:
	Knight() 
	// 빠른초기화 영역에서 부모의 생성자를 암시적으로 호출한다.
	// 명시적으로 내가 호출해줄 수도 있다.
	: Player(150) 
	{ 
		cout << "Knight 기본생성자 호출" << endl; 
	}

	~Knight() { cout << "Knight 소멸자 호출" << endl; }
};

int main()
{
	Knight k;

	return 0;
}