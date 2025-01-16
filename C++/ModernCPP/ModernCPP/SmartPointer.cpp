#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <memory>

using namespace std;

struct RefCountBlock
{
	int refCount = 1;
};

template<typename T>
class Shared_ptr
{
public:
	Shared_ptr() = default;
	Shared_ptr(T* ptr)
	: _ptr(ptr)
	{
		_block = new RefCountBlock();
		cout << "RefCount : " << _block->refCount << endl;
	}

	Shared_ptr(const Shared_ptr<T>& other)
	{
		_ptr = other._ptr;
		_block = other._block;

		if (_ptr != nullptr)
		{
			_block->refCount++;
			cout << "RefCount : " << _block->refCount << endl;
		}
	}

	Shared_ptr(std::nullptr_t)
	{
		_block->refCount--;
		_ptr = nullptr;

		cout << "RefCount : " << _block->refCount << endl;
	}

	~Shared_ptr()
	{
		if (_ptr != nullptr)
		{
			_block->refCount--;
			cout << "RefCount : " << _block->refCount << endl;

			if (_block->refCount <= 0)
			{
				delete _ptr;
				_ptr = nullptr;
			}
		}
	}

	Shared_ptr<T>& operator=(const Shared_ptr<T>& other)
	{
		_ptr = other._ptr;
		_block = other._block;

		if (_ptr != nullptr)
		{
			_block->refCount++;
			cout << "RefCount : " << _block->refCount << endl;
		}

		return *this;
	}

	Shared_ptr<T>& operator=(std::nullptr_t)
	{
		_block->refCount--;
		_ptr = nullptr;

		cout << "RefCount : " << _block->refCount << endl;

		return *this;
	}

	T& operator*() { return *_ptr; }
	T* Get() { return _ptr; }

private:
	T* _ptr = nullptr;
	RefCountBlock* _block = nullptr;
};

class Player
{
public:
	Player() { cout << "Player의 생성자" << endl; }
	~Player() { cout << "Player의 소멸자" << endl; }

	void Attack() 
	{ 
		if (target.expired() == false)
		{
			target.lock()->_hp -= _atk;
			cout << "Attack" << endl;
		}
	}

public:
	weak_ptr<Player> target;
	int _hp = 1;
	int _atk = 2;
};

void PrintPlayer(Shared_ptr<Player> p)
{
	// ->
	cout << (*p)._hp << endl;
	cout << (*p)._atk << endl;
}

int main()
{
	// 공유포인터
	// - 참조된 횟수
	//  => shared_ptr의 소멸자가 호출될 때 그냥 지우는게 아니라, 참조된 횟수가 0회일 때 실제 힙에 있는 데이터 삭제
	shared_ptr<Player> myShared1 = make_shared<Player>(); 
	shared_ptr<Player> myShared2 = make_shared<Player>();

	myShared1->target = myShared2;
	myShared2->target = myShared1;

	// weak_ptr
	// shared_ptr의 순환참조 문제의 해결방법
	// - 보통 target으로 물고있을 때 쓴다. => 멤버변수로 다른 포인터를 가리키고 있는 것

	// unique_ptr
	unique_ptr<Player> uPtr = make_unique<Player>();

	vector<Player*> v1;
	vector<shared_ptr<Player>> v2;

	// dxdiag

	return 0;
}