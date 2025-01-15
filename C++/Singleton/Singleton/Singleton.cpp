#include <iostream>
#include <unordered_map>

using namespace std;

// 디자인패턴 : 어떤 문제를 해결하기 위해 사람들 고안해서 굳혀진 패턴
// 싱글턴
// - 단 하나만 존재해야한다.
// - 전역에서 접근해야된다.
// - 생성주기도 조절할 수 있어야한다.

class SoundManager
{
public:
	static void Create()
	{
		if(instance == nullptr)
			instance = new SoundManager();
	}

	static void Delete()
	{
		if (instance != nullptr)
		{
			delete instance;
			instance = nullptr;
		}
	}

	static SoundManager* Instance()
	{
		if (instance != nullptr)
			return instance;
		return nullptr;
	}
	
	void AttackSound() { cout << "Attack!!" << endl; }
	void PlaySound(string key) { cout << _soundMap[key] << endl; }

private:
	SoundManager() 
	{
		_soundMap["Attack"] = "Attack!! Sound!!";
		_soundMap["Dead"] = "Dead Sound!";
	}

	static SoundManager* instance;

	unordered_map<string, string> _soundMap;
};

SoundManager* SoundManager::instance = nullptr;


int main()
{
	SoundManager::Create();

	SoundManager::Instance()->PlaySound("Dead");

	SoundManager::Delete();

	return 0;
}