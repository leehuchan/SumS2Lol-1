#include <iostream>

using namespace std;

// 수학함수
// y = f(x)
// (반환자료형) 함수이름(매개변수) => 함수 시그니쳐
// 함수 선언방법
// void : 공허한, 

// 포인터 연산자
// *ptr : 간접연산자, 포탈연산자 => 포인터가 담고있는 주소값으로 포탈타고 들어감
// &(변수) : 주소연산자 => 변수가 담겨있는 주소값

// Stack : 컴파일 시간에 크기가 결정

// 스택프레임 : 함수가 호출 될 때 Stack영역에 쌓이는 [반환주소값, 매개변수, 지역변수]
// 포인터, 참조의 차이에 대해서 조사
// 
// std::vector, std::list 조사해보고 차이점

void HelloWorld(void)
{
	cout << "Hello World!" << endl;
}

int Add(int a, int b)
{
	int c = a + b;

	// main[반환주소값(), 매개변수(void), 지역변수(aInt(cccccccc)), Add[반환주소값(&aInt), 매개변수(a 1,b 2), 지역변수 c(3)]
	
	cout << c << endl;

	return c;
}

// C : 같은 이름으로 다른 버전으로 만들자 => 함수 오버로딩
// 다른 버전 : 매개변수의 자료형이나, 개수 다른 것
int Add(int a, int b, int c)
{
	int d = Add(a,b) + c;
	return d;
}

// 함수 매개변수의 기본인자  => 매개변수(인자, Parameter, Arrgument)
// 기본인자는 맨 뒤부터
int Add(int a, int b, int c, int d, int e = 1)
{
	int f = Add(a,b,c) + d + e;
	return f;
}

// 재귀호출 : 스택오버플로우 => 스택에 더 이상 할당할 수가 없다.
// !5 : 5 x 4 x 3 x 2 x1
int Factorial(int num)
{
	if (num == 1)
		return 1;

	//     5   * 4 * 3 * 2 * 1
	return num * Factorial(num - 1);
}

// 메모이제이션
int cache[200] = {};
int Fibonacci(int num)
{
	if (num == 0 || num == 1)
		return 1;

	int* ref = &cache[num];
	if (*ref != 0)
		return *ref;

	*ref = Fibonacci(num - 1) + Fibonacci(num - 2); // cache[2] = 2

	return *ref;
}

// Call by Value
void AddOne(int num)
{
	// main[반환주소값(), 매개변수(void), 지역변수(aInt(3)), AddOne[반환주소값(&aInt), 매개변수(num : 3), 지역변수()]
	num++;
	// main[반환주소값(), 매개변수(void), 지역변수(aInt(3)), AddOne[반환주소값(&aInt), 매개변수(num : 4), 지역변수()]
}

// Call by Address
void AddOne(int* ptr)
{
	// main[반환주소값(), 매개변수(void), 지역변수((0x12)aInt(3)), AddOne[반환주소값(&aInt), 매개변수(ptr : 0x12), 지역변수()]
	(*ptr)++;
	// main[반환주소값(), 매개변수(void), 지역변수((0x12)aInt(4)), AddOne[반환주소값(&aInt), 매개변수(ptr : 0x12), 지역변수()]
}

int main()
{
	HelloWorld();

	// main[반환주소값(), 매개변수(void), 지역변수(aInt(cccccccc))

	int aInt = Add(1, 2);

	// aInt ... 3
	AddOne(aInt);
	// main[반환주소값(), 매개변수(void), 지역변수(aInt(3))
	cout << aInt << endl;

	AddOne(&aInt);
	// main[반환주소값(), 매개변수(void), 지역변수(aInt(4))
	cout << aInt << endl;

	aInt = Add(1, 2, 3, 4);

	aInt = Factorial(5);
	
	aInt = Fibonacci(1000);
	cout << aInt << endl;

	return 0;
}