#include <iostream>

using namespace std;

// static 변수 : 정적변수

// 메모리 4영역
// CODE
// DATA : Global, static(딱 하나만 존재)
//  생성주기 : 프로그램 시작 / 프로그램 종료
// STACK : parameter, local
//  생성주기 : 함수 호출 시/ 함수 종료 시
// HEAP : 프로그래머 영역

int aInt = 1;
static int cInt = 3;

void Hello()
{
	int bInt = 2;
}


class Mushroom
{
public:

	void Upgrade()
	{
		_atk++;
	}

	// 멤버 함수
	// - 멤버 변수에 접근해서 수정,읽기
	// - 멤버함수 호출 조건(1. 어디 산하, 2. 객체)
	void PrintAtk()
	{
		cout << _atk << endl;
	}

	// 정적 멤버 함수
	// => 모든 객체들이 공유하는 공용함수 => 멤버함수의 전역화
	// ==> 각자의 멤버변수에 접근할 수 없다.
	static void Hello()
	{
		cout << "Hello" << endl;
	}

private:
	int _hp = 100;
	// 정적 멤버 변수 : Data영역에 할당 => 멤버변수인데 Data에 있고, 생성주기가 혼자 다르다.
	static int _atk; // 모든 객체들이 공유하는 공용변수
};

int Mushroom::_atk = 5;

int main()
{
	Mushroom arr[5];
	
	arr[0].Upgrade();
	arr[1].PrintAtk();

	arr[0].Hello();
	Mushroom::Hello();

	return 0;
}