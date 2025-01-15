#include <iostream>

using namespace std;

// Reference : 참조
// (자료형)& (참조이름) = (초기화);
// 크기 : 포인터와 동일

// - 어셈블리어 관점
// => 동일한 작업

// C++ 관점
// ptr
// 1. 위험하다. (nullptr에 접근, 초기화 되지않은 영역 접근 가능)
// 2. 쓰기 어렵다.
// 
// ref 
// 1. 누군가의 별칭
// => nullptr 참조가 불가능하다.
// => 반드시 유효한 변수의 별명이여한다.
// 2. 쓰기 쉽다.

// Ptr
// - 장점
// => nullptr을 가리킬 수 있다.

// Ref
// - 장점
// => 쓰기 쉽다.

int main()
{
	int aInt = 1;
	int bInt = 2;
	int* ptr = &aInt;
	int& ref = aInt;

	ref++;
	(*ptr)++;


	return 0;
}