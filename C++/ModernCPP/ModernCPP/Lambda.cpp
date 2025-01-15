#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <string>

using namespace std;

class Pet
{
public:
	int _atk;
};

class Player
{
public:
	int _hp = 0;
	int _atk = 0;

	Pet* _pet = 0;
};

bool ComparePlayer(Player* left, Player* right)
{
	if (left->_pet->_atk < right->_pet->_atk)
		return true;
	return false;
}

struct SortComparer
{
	bool operator()(Player* left, Player* right)
	{
		if (left->_pet->_atk < right->_pet->_atk)
			return true;
		return false;
	}
};

int main()
{
	vector<int> v = { 1,25,6,23,4,5 };

	int compareNum = 20;
	// 람다식
	//  [캡쳐](매개변수) -> (반환형식) { 함수 정의부 }
	// [캡쳐] : 람다 외부의 변수를 캡쳐하는 용도
	// 20보다 큰 수의 개수
	int c = std::count_if(v.begin(), v.end(), [&compareNum](const int& element) -> bool
		{
			if (element > compareNum)
				return true;
			return false;
		});

	cout << c << endl;

	// 25보다 큰 수의 개수
	compareNum = 25;
	c = std::count_if(v.begin(), v.end(), [&compareNum](const int& element) -> bool
		{
			if (element > compareNum)
				return true;
			return false;
		});
	cout << c << endl;

	std::for_each(v.begin(), v.end(), [](const int& element)->void { cout << "Hello World!" << endl; });

	auto func = []() {};

	// 함수 포인터,  (함수 객체, 람다) Callable 객체
	// Callable 객체를 매개변수 넘기는 것을 '콜백함수' => Delegate
	function<void(void)> fn; // fn은 함수 포인터, 함수 객체, 람다
	fn = []() {};

#pragma region 실습
	// 람다 : 무명함수
	vector<Player*> players;

	for(int i=0; i<10;i++)
	{
		Player* p = new Player();
		p->_pet = new Pet();
		p->_pet->_atk = rand() % 50;

		players.push_back(p);
	}

	// players 배열을 정렬할건데 player한명이 갖고있는 pet의 데미지에 따라서 players를 정렬하라
	// std::sort(players.begin(), players.end(), &ComparePlayer); => 함수 포인터
	// SortComparer functor;
	// std::sort(players.begin(), players.end(), functor); => 함수 객체
	std::sort(players.begin(), players.end(), [](Player* left, Player* right)-> bool
		{
			if (left->_pet->_atk < right->_pet->_atk)
				return true;
			return false;
		});
#pragma endregion

	
	return 0;
}