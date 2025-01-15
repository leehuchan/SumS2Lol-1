#include <iostream>

using namespace std;

// 상속
// - 코드의 재사용성
// - is a 관계가 성립할 때만 상속을 건다. 단방향
// => Animal is a Cat(X)
// => Cat is a Animal(O)
// 
// ...
// 1. 상속을 걸면 층개념
// 2. 상속을 걸면 부모의 속성, 기능을 물려받는다. 

class Animal
{
public:
	void Eat() { cout << "쩝쩝" << endl; }
	void SetAnimal(int legs, int mouth)
	{
		_legs = legs;
		_mouth = mouth;
	}
protected:
	int _legs;
	int _mouth;
};

class Cat : public Animal
{
public:
	// 함수 오버라이딩 : 부모의 함수를 자식에서 재정의
	void Eat()
	{
		cout << "냥냥" << endl;
	}

	void SetTail(int tail)
	{
		_tail = tail;
	}

private:
	int _tail;
};

int main()
{
	Animal animal;
	animal.SetAnimal(2, 1);
	animal.Eat();

	Cat cat;
	cat.SetAnimal(4, 1);
	cat.SetTail(1);
	cat.Eat();

	return 0;
}