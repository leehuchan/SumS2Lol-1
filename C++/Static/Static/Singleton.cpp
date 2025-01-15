#include <iostream>

using namespace std;

// 사운드 매니저
// 1. 프로그램 내에서 단 한개
// 2. 여러가지 사운드를 갖고, 어디서든 출력도 가능해야됌.
// 3. 생성 삭제를 사용자가 조정할 수 있어야함.

class SoundManager
{
public:
	static void Create()
	{
		if(_instance == nullptr)
			_instance = new SoundManager();
	}

	static void Delete()
	{
		if (_instance != nullptr)
			delete _instance;
	}

	static SoundManager* GetInstance()
	{
		return _instance;
	}

	void AttackSound() { cout << _attackSound << endl; }

private:
	SoundManager() : _attackSound("Attack!!!") {}
	~SoundManager() {}

private:
	static SoundManager* _instance;

	string _attackSound;
};

SoundManager* SoundManager::_instance = nullptr;

int main()
{
	SoundManager::Create();

	SoundManager::GetInstance()->AttackSound();

	SoundManager::Delete();

	return 0;
}