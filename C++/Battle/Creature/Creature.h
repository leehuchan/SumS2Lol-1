#pragma once
class Creature
{
public:
	Creature(int hp, int atk);
	virtual ~Creature();

	// 가상함수 
	// - 상속구조에 쓰이는 함수 : 모든 자식이 오버라이딩이 가능
	// - 오버라이딩

	virtual void Attack(Creature* other);
	void TakeDamage(int amount);

	bool IsDead();

	// C# getset
	string GetName() { return _name; }
	void SetName(string name) { _name = name; }

protected:
	int _hp;
	int _atk;
	string _name;
};

