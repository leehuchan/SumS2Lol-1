#include <iostream>
#include <list>

using namespace std;

// vector
// - Heap에 배열을 만든다.(만들었다, 복사, 삭제, 생성을 반복한다.)
// list
// - Node형식으로 서로를 잇는다.

// vector와 list 차이
// 1. 임의접근하는데 걸리는 시간(vector: 상수, list : N)
// 2. 중간삽입에 걸리는 시간(vector : N, list : (삽입하려는 prev노드 혹은 next노드를 알고있는 경우 상수)
// 3. 메모리의 파편화가 됬을 때 크기가 큰 vector는 끼어들어가지 못할 수도 있다. 

int main()
{
	list<int> l;
	
	l.push_back(1);
	l.push_back(111);
	l.push_back(113);
	l.push_back(13);
	l.push_front(2);
	l.push_front(340);
	l.push_front(2);
	l.push_front(3);

	list<int>::iterator iter = l.begin();
	for (iter; iter != l.end(); iter++)
	{
		cout << *iter << endl;
	}

	return 0;
}