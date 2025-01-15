#include <iostream>

using namespace std;

// 변수 (바구니)
// (자료형) (변수이름) = (초기화);

// 연산자
// 변수들을 가공하는 방법

// 사칙연산 (이항연산자)
// + - * / (%)

// a + b : a와 b를 더한 임시값을 반환한다.
// a - b : 
// (정수형)
// a / b : a를 b로 나눈 몫을 임시값에 담고 반환한다.
// (실수형)
// a / b : a를 b로 나눈 임시값을 반환한다.

// a % b : 정수형끼리 나머지 임시값을 반환한다.
// => 순환구조 만들 때 쓰인다.

// 증감연산자(단항연산자)
// ++a : 전위연산자 : a의 원본에 1을 더하고 원본을 반환한다.
// a++ : 후위연산자 : a를 복사한 임시값을 만들고, a에다 1을 더하고 임시값을 반환한다.
 
// 비교 연산자
// ==, !=, <, >, <=, >=
// 반환값이 bool
// a > b : a가 b보다 크면 true, 그게아니면 false 반환

// 삼항연산자
// (조건, bool) ? (a) : (b)
// 조건이 true면 a반환, false면 b반환
// 	aInt = (cInt > 0) ? 50 : 100;

// = : 대입연산자
// a = b : a에다가 b를 넣고 a의 원본을 반환한다.

// 논리연산자
// !, &&, ||
// !(bool) : 역으로 바꾼다.
// a && b : a와 b가 둘다 true일 때 true, 그게 아니면 false 반환
// a || b : a와 b 둘 중 하나가 true면 true, 그게아니면 false 반환.

int main()
{
	int aInt = 3;
	// Stack 영역에 4바이트만큼 할당받고 데이터는 1이다.

	int bInt = 5;
	int cInt = bInt % aInt; // 3의 나머지 0,1,2

	cInt = ++aInt; // 4
	cInt = aInt++; // 

	bool check1 = (aInt > bInt); // f
	bool check2 = (aInt == bInt) && check1; // f
	bool check3 = 3; // t

	aInt = 3;
	bool check4 = !check1 || check3; // t
	bool check5 = (check4 || check2) && (aInt > 2); // t
	bool check6 = (++aInt == 4) && (aInt++ == 5); // f

	return 0;
}