#include <iostream>

#define PI 3.141592f

using namespace std;

// 컴파일 4단계
// 1. 전처리기
//		- # 얘들 처리, 주석
// 2. 컴파일러
//      - 고수준 언어(C++)를 어셈블리어로 바꾸는 작업
// 3. 어셈블러
//		- 어셈블리어를 기계어로 바꾸는 작업
// 4. 링커
//      - 파일결합을 해서 최종단계 .obj 변환작업

// ref
// (자료형)& (Ref 이름) = (초기화);
// - C++ 관점 : 해당 변수의 별명
// - 어셈블리어 : 포인터랑 동일하다.
// - 크기 : 32비트환경(4바이트) 64비트환경(8바이트)

// ptr, ref 차이
// 1. 포인터는 중간에 대상을 변경할 수 있다 / Ref는 중간에 대상을 변경할 수 없다.
// 2. 포인터는 nullptr을 저장할 수 있다. / Ref 없는 값을 참조할 수 있다.
// 3. 포인터는 초기화를 하지않아도 된다. / Ref는 무조건 초기화

// Call By Value
// 매개변수 value만 읽기, 수정 가능하다.
// 원본을 수정할 수 없다. / 원본을 읽어오기(복사)는 가능하다
//void AddOne(int value)
//{
//	value++;
//}

// Call By Address
// 매개변수 ptr에 타고 들어가서 읽기/ 수정 가능
// 원본을 수정할 수 있다.
// -> 쓰기어렵다(메모리 오염)
void AddOne(int* ptr) // 0x12
{
	(*ptr)++;
}

// Call By Reference
// 매개변수 ref(별명)에 가서 읽기/ 수정 가능
// 원본을 수정할 수 있다.
// -> 쓰기 쉽다
void AddOne(int& ref)
{
	ref++;
}

int main()
{
	float pi = PI;
	int aInt = 1;
	int bInt = 2;

	int* ptr = &aInt;//0xcccccccc
	ptr = NULL;

	int& ref = aInt;
	ref = 2; 

	cout << aInt << endl;
	cout << ref << endl;
	cout << bInt << endl;

	aInt = 1;
	AddOne(&aInt); // (0x12)aInt
	AddOne(aInt);

	cout << aInt << endl;

	return 0;
}