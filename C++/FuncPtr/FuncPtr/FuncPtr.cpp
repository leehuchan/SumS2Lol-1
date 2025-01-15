#include <iostream>

using namespace std;

// 함수도 어딘가에 저장이 되어있다면, 포인터로 걔를 가리키고 저장할 수 있지 않을까?

void HelloWorld()
{
	cout << "Hello World!" << endl;
}

void ByeWorld()
{
	cout << "Bye World!" << endl;
}

int PrintNum(int num)
{
	cout << num << endl;
	return num;
}

class Pet;
// 전역 함수 포인터
// 선언 방법 : (반환자료형) (*포인터이름)(매개변수)
void(*func)(void);
int(*func2)(int);

// typedef : 자료형 정의
typedef void(*FUNC)(void);
typedef int(*FUNC2)(int);
typedef void(Pet::*PETFUNC)(void); // Pet의 void(void)인 멤버함수를 저장할 수 있는 포인터 변수 자료형 선언

class Pet
{
public:
	void Bark() { cout << "멍멍" << endl; }
};

class Player
{
public:
	void SayHello() { if (_playerFunc) { _playerFunc(); } }

	void SetFunc(void(*func)(void)) { _playerFunc = func;}

private:
	void(*_playerFunc)(void);
};

int main()
{
	// 콜백함수가 무엇인지 조사하기
	// 콜백함수 : 나중에 뭐 호출해줘~
	// => 매개변수로 함수를 넘겨서 간접적으로 나중에 호출할 수 있게해주는 것

	Player* p = new Player();
	p->SetFunc(&HelloWorld);
	p->SayHello();

	p->SetFunc(&ByeWorld);
	p->SayHello();

	FUNC myFunc = &HelloWorld;

	func2 = &PrintNum;
	int temp = func2(5);

	Pet* pet = new Pet();
	PETFUNC myPetFunc = &Pet::Bark;
	pet->Pet::Bark();
	(pet->*myPetFunc)();
	
	delete pet;
	delete p;

	return 0;
}