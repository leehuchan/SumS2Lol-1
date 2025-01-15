#include <iostream>

using namespace std;

// 메모리 4영역
// CODE
// DATA : 전역변수, (정적변수)
// 생성주기 : 프로그램 실행 시 할당 / 프로그램 종료 시 해제
// 
// STACK : [매개변수 반환주소값 지역변수]
// 생성주기 : 함수 호출 시 할당 / 함수 종료 시 해제 
// 
// HEAP :
// 생성주기 : 프로그래머 마음대로

class Marine
{
public:
	Marine() : _hp(40), _armor(1){}
	~Marine() {}

	// 멤버함수 함수를 호출하려면...
	// 1. 객체
	// 2. 어딘 산하에 있는지
	void Attack() { cout << marine_atk << endl; }
	void Upgrade_ATK() { _armor++; marine_atk++; }

	// 정적멤버함수
	// 1. 객체가 없어도 호출 가능
	// 2. 모든 객체들이 바라보고 있는 공유함수
	// 3. 정적멤버변수만 접근가능
	static void Upgrade_ATK2() { marine_atk++; }

private:
	// Data영역
	// 모든 객체들이 바라보고 있는 공유변수
	static int marine_atk;
	int _hp;
	int _armor;
};

// :: => 범위지정연산자 ... ~ 산하의
// 정적멤버변수는 외부에서 초기화
int Marine::marine_atk = 5;

int main()
{
	Marine marine[50];

	marine[0].Attack();
	// 공업..?	
	Marine::Upgrade_ATK2();

	marine[2].Attack();
	

	return 0;
}