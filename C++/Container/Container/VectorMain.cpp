#include <iostream>
#include <vector>

using namespace std;

class Player
{
	int data[100]; // 400바이트
};

int main()
{
	vector<int> v;
	vector<Player> p;
	p.reserve(10); // => 4000바이트 예약

	vector<Player*> p2;
	p2.reserve(10); // => 40바이트
	p2.push_back(new Player());
	

	v.reserve(1000);
	// v.resize(1000, -1);

	for (int i = 0; i < 1000; i++)
	{
		v.push_back(i);
		cout << "v의 용량 : " << v.capacity() << "    v의 크기 : " << v.size() << endl;
	}

	return 0;
}