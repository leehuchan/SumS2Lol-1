#include <iostream>

using namespace std;

// Template : 주조 틀
// => 뭔가를 쉽게 찍어내서 만들기 위한

// 템플릿함수 : 함수(기능)를 찍어내는 틀
template <typename T = int>
void PrintNum(T num)
{
	cout << num << endl;
}

// 템플릿함수의 특수화
template<>
void PrintNum(double num)
{
	cout << "Double 형 함수 생성!!" << endl;
	cout << num << endl;
}

// 템플릿 클래스
// : 클래스(설계도)를 찍어내는 주조틀
// 
template<typename T = float> // 템플릿 클래스의 기본인자 설정 (템플릿 클래스를 나타내는 <>는 생략할 수 없다.)
class Vector
{
public:
	Vector() :x(T()), y(T()) {}
	Vector(T x, T y) : x(x), y(y) {}

	// 덧셈연산자 오버로딩 
	// 덧셈연산자 : a + b => a와 b를 더하고 임시값을 반환한다.
	Vector<T> operator+(const Vector<T>& other)
	{
		Vector<T> result;
		result.x = x + other.x;
		result.y = y + other.y;

		return result;
	}

	void PrintVector()
	{
		cout << "X : " << x << endl;
		cout << "Y : " << y << endl;
	}
	

	T x;
	T y;
};

template<>
class Vector<double>
{
public:
	Vector() :x(double()), y(double()) {}
	Vector(double x, double y) : x(x), y(y) {}

	// 덧셈연산자 오버로딩 
	// 덧셈연산자 : a + b => a와 b를 더하고 임시값을 반환한다.
	Vector<double> operator+(const Vector<double>& other)
	{
		Vector<double> result;
		result.x = x + other.x;
		result.y = y + other.y;

		return result;
	}

	void PrintVector()
	{
		cout << "Double 특수화" << endl;

		cout << "X : " << x << endl;
		cout << "Y : " << y << endl;
	}

	double x;
	double y;
};

class Player
{
public:

private:
};

int main()
{
	int aInt = 1;
	PrintNum(aInt); // =>

	double aDouble = 1.1;
	PrintNum<double>(aDouble);

	Vector<int> v1(1,1);
	Vector<int> v2(2,3);
	Vector<int> temp = v1 + v2;
	temp.PrintVector();

	Vector<> fv1(1.1f,2.3f);

	Vector<double> dv1(2.2,2.5);
	Vector<double> dv2(1.1,3.3);
	Vector<double> temp2 = dv1 + dv2;
	temp2.PrintVector();

	return 0;
}