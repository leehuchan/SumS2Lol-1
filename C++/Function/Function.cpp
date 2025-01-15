#include <iostream>

using namespace std;

// 함수
// f(x) = y;

// 함수 시그니쳐
// (반환자료형) 함수이름 (매개변수);

// Stack영역
// - 지역변수
// - 매개변수
// - 반환주소값

// 스택프레임 : [매개변수][반환주소값][지역변수]
// First Input Last Out : 처음에 추가된게 가장 마지막에 사라진다 => 팬케이크

// 매개변수를 넣고 반환을 받는 것
void HelloWorld(int temp)
{
	int aInt = 1;

	cout << "Hello Wolrd " << temp << endl;

}

// Call By Value
int Add(int a, int b)
{
	int c = a + b;
	// main[반환주소값, 지역변수(aInt,bInt), 매개변수()] Add[반환주소값, 지역변수(c(3)), 매개변수 a(1),b(2))]

	cout << c << endl;

	return c;
}

// 함수 오버로딩
// 함수 이름이 같고, 매개변수의 자료형이나 개수가 다른 것
int Add(int a, int b, int c)
{
	int d = Add(a, b) + c;

	cout << d << endl;

	return d;
}

// 기본인자... 맨 뒤의 인자부터 정의 해줘야한다.
int Add(int a, int b, int c, int d, int e = 4)
{
	int f = Add(a,b,c) + d + e;

	cout << f << endl;

	return f;
}

// 재귀호출 : 함수가 자기 자신을 호출
// 5! = 5x4x3x2x1
int Factorial(int num)
{
	if (num == 1)
		return 1;

	return num * Factorial(num - 1);
}

int main()
{
	int aInt = 1;
	int bInt = 2;
	int cInt = 3;
	int dInt = 4;
	int eInt = 5;
	// main[반환주소값, 지역변수(aInt(1),bInt(2)), 매개변수()]
	if (Add(aInt, bInt, cInt, dInt) == 14)
	{
		cout << "14 입니다!!" << endl;
	}

	cout << Factorial(5) << endl;

	return 0;
}