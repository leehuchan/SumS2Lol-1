#include <iostream>

using namespace std;

// 과제
// 1. 포인터와 참조에 대해서 비교, 조사
// 2. 포인터 연산자에 대해서 조사
// 3. 배열에 대해서 조사
// 4. Player 싸우기

// x86, x64
// x86 : 32비트 처리 프로그램
// x64 : 64비트 처리 

// 포인터 (자료형)
// - 어딘가를 가리키는 얘
// - 주소값
// (자료형)* 변수이름 = (초기화);
// 크기 : 32비트 환경 4바이트
//        64비트 환경 8바이트

// &(변수) : 해당 변수의 주소값을 반환한다. => 주소연산자
// *(변수) : 포인터가 갖고있는 주소값을 타고 들어갔을 때 그 값을 반환 => 간접연산자... 포탈연산자

// (자료형) 이 필요한 이유?
// 힌트, 타고 들어갔을 때 (자료형)인 변수가 있어야한다.

// Call by Value
// 매개변수에 값을 복사

// Call by Address
// => 매개변수에 주소값을 복사
void AddOne(int* a)
{
	++(*a);
}

int main()
{
	int aInt = 1;
	int* aPtr = &aInt;

	AddOne(&aInt);
	cout << aInt << endl;

	float* bPtr = (float*)&aInt;
	cout << *bPtr << endl;

	return 0;
}