#include <iostream>

using namespace std;

// 프로그래밍
// - 정의 
// - 왜? (써본 사람은 얘기)
// - 어떻게? (경력자)

// 절차지향(순서대로) vs 객체지향(객체)
// 객체 : 속성과 기능을 갖고 메모리에 할당되어있는 것
// 객체화 : (class 자료형을) 메모리에 할당하는 것
// 인스턴스 : 속성과 기능을 안가져도 메모리에 할당되어있는 것
// 인스턴스화 : 

// 1. 객체지향의 3속성
//	- 은닉성
//		=> 외부에서 쉽게(직접) 접근해서 바꾸지 못하게 하려고
//      ==> 멤버함수 내에서만 통제시킬려고
//  - 접근지정자 : public(접근 어디에서든) / protected(멤버함수, 자식의 멤버함수) / private(멤버함수, friend)
struct Vector // 수학
{
public:
	float x;
	float y;
};

class Car // 객체(속성,기능)
{
public:
	// 멤버함수
	// - 기능
	// 멤버변수에 직접 접근 => 속성을 다루는 '기능'
	// 멤버함수는 객체가 있어야 호출이 가능하다.
	void PrintCar() { cout << _engine << endl; }
	int GetEngine() { return _engine; }
	void SetEngine(int engine) {
		if (engine < 0) return;

		this->_engine = engine; }

private:
	// 멤버변수
	// - 속성
	int _engine;
	int _handle;
	int _wheels;
	int _doors;
};

//  - 상속성
// 
// 
//  - 다형성
// 
// 2. 클래스의 생성자/소멸자
// 3. 클래스의 오버라이딩 / 오버로딩
// 4. Vector에 대해서 공부해오기(내적 / 외적)

int main()
{
	Car car;
	
	// 사용자 사용 코드
	car.SetEngine(5);
	cout << car.GetEngine() << endl;

}