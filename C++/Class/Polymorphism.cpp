#include <iostream>

using namespace std;

// 다형성(클래스 여러가지 형태를 가질 수 있다.)
// 1. 멤버함수 오버라이딩 : 부모의 함수를 자식에서 재정의(함수시그니쳐가 동일)하는 것
// 2. 멤버함수 오버로딩 : 함수의 이름이 같고, 매개변수의 개수나 자료형이 다른 함수를 정의할 수 있다.

class Player
{
public:
	void Attack() { cout << "ATTACK!!!" << endl; }

	void Set(int hp, int atk) { _hp = hp; _atk = atk; }

	// 연산자 오버로딩
	// a + b : a와 b를 더하고 임시값을 반환한다.
	Player operator+(const Player& other)
	{
		Player result;
		result._hp = _hp + other._hp;
		result._atk = _atk + other._atk;

		return result;
	}

	void operator()()
	{
		cout << "Hello I'm Player!!" << endl;
	}

protected:
	int _hp;
	int _atk;
};

class Knight : public Player
{
public:
	void Attack() { cout << "Knight!!!" << endl; } // 함수 오버라이딩
};

int main()
{
	Knight knight;
	knight.Attack();

	Player p1;
	Player p2;
	Player p3 = p1 + p2; // +연산자 오버로딩

	p3();

	int aInt = 1;
	int bInt = 2;
	int cInt = aInt + bInt;

	return 0;
}