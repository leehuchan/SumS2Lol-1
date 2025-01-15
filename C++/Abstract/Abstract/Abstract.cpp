#include <iostream>

using namespace std;

// Abstract Class : 추상클래스
// 1. 객체화될 수 없다.
//	=> 순수가상함수를 하나 이상 포함하는 클래스여야한다.
// 2. 자식들한테 인터페이스(순수가상함수)를 제공할 것을 강제함.

// 인터페이스(interface)
// - C++ 관점 : 접근하고자하는 변수 혹은 기능에 접근하려는 수단

// 개념
class Car
{
public:
	// 순수가상함수 : 인터페이스
	// => 멤버변수에 접근할 수 있는 수단
	virtual void Handling() abstract;
	//virtual void Hitter() abstract;
};

class Urus : public Car
{
public:
	// 추상클래스를 상속받은 경우
	// 순수가상함수를 오버라이딩하지 않으면 객체화 될 수 없다.
	virtual void Handling() override 
	{
		cout << "SUV 부릉부릉" << endl;
	}
};

class Coontach : public Car
{
public:
	virtual void Handling() override 
	{
		cout << "스포츠카 부웅부웅" << endl;
	}
};

int main()
{
	Urus urus;
	Coontach coontach;

	return 0;
}