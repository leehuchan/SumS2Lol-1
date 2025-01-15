#include <iostream> // input output stream

// 컴파일 4단계 (우리가 읽을 수 있는 언어를 컴퓨터언어로 바꾸는 작업)
// 1. 전처리기
// 2. 컴파일러
// 3. 어셈블러
// 4. 링커

// CPU - 메모리
// CPU : 연산, 제어, 논리 작업을 수행하는 장치

// 메모리 : 
// 주기억 장치 : (RAM)
// - 게임을 실행시키면 현재 눈에 보여야하는 데이터들이 이 장치에 올라온다.
// - 휘발성 메모리
// - 물리적으로 CPU와 거리가 가깝고
// - 읽고 쓰는데 속도가 상대적으로 빠르다.
// 
// 보조기억 장치 : HDD, SSD
// - 게임을 다운 받으면 여기다가 저장
// - 영구적인 저장장치
// - 읽고 저장하는데 꽤나 오랜 시간
// - 저장하러 가기에도 물리적 거리가 멀다.

// 주기억 장치
// CODE : 코드
// DATA : 전역변수, 정적변수
//  - 초기화가 안되어있으면 0x00000000
// STACK : [지역변수, 매개변수, 반환주소값] => 스택프레임
//  - 초기화가 안되어있으면 0xcccccccc
// HEAP : 사용자 메모리

using namespace std;


// 정수 자료형 : 
int aInt = 1; // 크기 : 4바이트

// 실수 자료형 
// 비트를 표현하고 읽을 때 부동소수점
float aFloat = 1.0f; // 4바이트(부호 1비트, 지수부 8, 유효숫자부 : 23비트)
double aDouble = 1.5;

bool aBool = false; // 1바이트
char aChar = 97; // 정수(비트)를 저장하고, 출력하면 아스키코드에 따라서 문자가 나온다.

// 사용저의 정의 자료형
// - 복합자료형
struct MyStruct
{
	int a;
	float b;
	char c;

	char padding1;
	char padding2;
	char padding3;
};

// 포인터 : 누군가를 가리키는 얘
// 포인터 선언하는 방법:  (자료형)* 포인터변수이름 = (초기화);
// 크기 : 32비트환경(메모리 처리할 때 4바이트만큼씩 처리) => 4바이튼
//        64비트환경(메모리 처리할 때 8바이트만큼씩 처리) => 8바이트

int main()
{
	// 지역변수
	int bInt = 2;

	MyStruct myStruct;
	myStruct.a = 1;
	myStruct.b = 2;
	myStruct.c = 3;

	cout << sizeof(myStruct) << endl;

	int* aPtr = &bInt; // 0x12341234

}