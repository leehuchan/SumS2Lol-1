#include <iostream>

using namespace std;

// 과제
// 1. 로또번호 뽑기
// 2. 생성자와 소멸자 조사하기

// Class
// - struct와 99% 동일
// - 클래스로 객체를 만들 수 있다.
//  -- 객체 : 기능과 속성을 갖는다
// - 설계도 : 객체를 만들어낼 수 있는 설계도

// * 객체 : 기능(멤버변수, attribute)과 속성(멤버함수, method)을 갖고, 메모리에 올라와 있는 데이터

// 절차지향 vs 객체지향
// 객체지향의 특징
// - 은닉성(캡슐화)
//	=> 접근을 못하게 할 수 있다.
//  => 접근 지정자 : public(모든 곳에 접근가능), protected(자식만 접근 가능), private(멤버함수만 접근가능)
// 
// - 상속성
// - 다형성(형태가 여려가지일 수 있다.)

class Car
{
public:

	// Car의 기능: 멤버함수
	// 멤버함수를 호출하려면 객체가 있어야한다.
	// 멤버함수는 private 속성에 접근(수정, 읽기)를 할 수 있는 방법을 열어준다.
	void Set(int engine, int handle, int wheel, int door)
	{
		// 예외처리
		if (engine < 0) return;
		if (engine > 2) return;

		_engine = engine;
		_handle = handle;
		_wheels = wheel;
		_doors = door;
	}

	// Car의 속성 : 멤버변수
private:
	int _engine;
	int _handle;
	int _wheels;
	int _doors;
};

int main()
{
	Car car1;
	car1.Set(1,1,4,4);


	return 0;
}