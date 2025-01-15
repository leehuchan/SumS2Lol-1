#include <iostream>

using namespace std;

// DATA
// - bss영역 : 초기화되지않은 전역변수
// - data영역 : 초기화된 전역변수
// - rodata영역 : 상수(리터럴 상수... 등등)

// Casting (변환)

// 기본자료형 변환
// int -> float (안전)
// float-> int (불안전)
// short->int (안전)
// int -> short (불안전)


// 업캐스팅 : 자식 클래스로 생성된 객체를 부모 클래스 포인터로 가리키는 것
// => 안전한 캐스팅
// 다운캐스팅 : 부모 클래스로 생성된 객체를 자식 클래스 포인터로 가리키는 것
// => 불안전한 캐스팅

// C++ 캐스팅 4총사
// 1. static_cast
// - 논리적으로 가능하면 컴파일 통과
// - 컴파일 시간에 성공여부를 반환
// 2. dynamic_cast
// - 상속구조에서만, 가상함수테이블이 존재하는 경우 사용가능
// - 성공하면 캐스팅 성공, 실패하면 nullptr 반환
// - 실행시간에 성공여부를 반환하는 캐스팅
// 3. const_cast
// - const를 붙혔다 뗏다.
// 4. reinterpret_cast
// - 재해석(비트를 그대로 유지한 채 형변환)
// - 강제적 형변환
// - 서버에서 주로 쓰인다.

struct Packet
{
	int packetId; // 사용자끼리 정하는거
	int aInt; // 32비트 (0100)
};

class Player
{
public:
	virtual void Attack() { cout << "Player Attack!" << endl; }

	int type = 0;
};

class Knight : public Player
{
public:
	Knight() { type = 1; }

	virtual void Attack() override { cout << "Knight Attack!" << endl; }
};

class Archer : public Player
{
public:
	Archer() { type = 2; }

	virtual void Attack() override { cout << "Archer Attack!" << endl; }
};

template<typename T>
T MyDynamic(T player)
{
	if (player->type == 1)
		return reinterpret_cast<T>(player);
	else
		return nullptr;
}

int main()
{
	int aInt = 1;
	float aFloat = aInt;
	aFloat = 1.523f;
	aInt = aFloat;

	Knight* k = new Knight();
	Player* p = k; // 업캐스팅

	Player* temp = new Player();
	Knight* temp2 = (Knight*)temp; // 다운캐스팅

	// 캐스팅 4총사
	// static_cast
	aFloat = static_cast<float>(aInt);
	Player* p1 = static_cast<Player*>(new Knight()); // 업캐스팅

	// dynamic_cast
	Player* p2 = new Knight();

	// ... 많은 일들이 있었음.

	Knight* p3 = dynamic_cast<Knight*>(p2); // RTTI 정보를 줘야한다.
	if (p3 == nullptr)
	{
		cout << "p2는 Knight가 아니였습니다." << endl;
	}
	else
	{
		cout << "p2는 Knight였습니다." << endl;
	}

	// const_cast
	const char* str1 = "hello world!";
	char str2[13] = "hello world!";

	char* str3 = const_cast<char*>(str1);
	//str3[0] = 't';

	// reinterpret_cast
	// 서버에서 주로 쓰인다.
	aFloat = 1.234f;
	int* aPtr = reinterpret_cast<int*>(&aFloat); 

	switch (p2->type)
	{
	case 1:
	{
		p3 = reinterpret_cast<Knight*>(p2);
		break;
	}
	case 2:
	{
		p3 = nullptr;
	}

	default:
		break;
	}


	delete p2;
	delete temp;
	delete k;

	return 0;
}