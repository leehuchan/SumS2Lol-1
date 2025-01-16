#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <string>

using namespace std;

// 좌측값(l-value), 우측값(r-value)

// l-value
// - 수정가능
// - 대표적인 예) 참조

// r-value
// - l-value아닌 얘들
// - 대표적인 예) const, 상수

// Shift : 이동, 이사
// (자료형)&& : 우측값참조 => C++11

class Pet
{
};

class Player
{
public:
	Player() { pet = new Pet(); }
	Player(int hp) { pet = new Pet(); }
	Player(const Player& other) 
	{ 
		// 깊은 복사
		this->pet = new Pet(*other.pet);
	}

	// 우측값 참조
	// 1. 원본에 접근 가능
	// 2. other은 문법적으로 우측값참조 => 껍데기만 남기겠다.
	// => 매개변수 other은 임시값처럼 사용하겠다.
	Player(Player&& other) noexcept  // 이동생성자
	{
		cout << "이동생성자 호출" << endl;
		this->pet = other.pet;
		other.pet = nullptr;
	}
	~Player() 
	{
		if(pet != nullptr)
			delete pet; 
	}


private:
	Pet* pet;
};

int& Temp()
{
	int aInt = 1;

	return aInt;
}

int main()
{
	int aInt = 1;
	aInt = 5;
	int& ref = aInt;
	ref = 3233;

	// player1에서 player2로 이사
	Player* player1 = new Player(std::move(Player()));

	Player* player2 = new Player(std::move(*player1)); // 이동개념 : 이사

	unique_ptr<Player> up = make_unique<Player>();
	unique_ptr<Player> up2(std::move(up));

	//vector<Player> players;
	//players.emplace_back(Player()); // players[0]

	delete player2;
	delete player1;

	return 0;
}