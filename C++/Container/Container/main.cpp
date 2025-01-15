#include <iostream>
#include <vector>
#include <list>

using namespace std;

#include "List.h"
#include "Vector.h"

int main()
{
	List<int> myList;

	myList.push_back(1);
	myList.push_back(2);
	myList.push_back(3);
	myList.push_back(4);
	myList.push_front(5);
	myList.push_front(6);
	myList.push_front(7);
	myList.push_front(8);
	// 8 7 6 5 1 2 3 4

	myList.pop_front();
	myList.pop_back();

	//myList.insert(100, 3);

	//for (int i = 0; i < myList.size(); i++)
	//{
	//	cout << myList[i] << endl;
	//}

	cout << "------------" << endl;
	Vector<int> myV;
	myV.push_back(1);
	myV.push_back(5);
	myV.push_back(6);
	myV.push_back(2);
	myV.push_back(87);

	myV.pop_back();

	myV.insert(10, 3);

	for (int i = 0; i < myV.size(); i++)
	{
		cout << myV[i] << endl;
	}

	myV.clear();
	//vector<int>().swap(myV); // => 임시객체와 Swap해서 실제 데이터를 날리는 코드
	cout << myV.capacity() << endl; // => Clear한다고 해서 _data가 가리키고 있던 Heap영역이 해제되는 게 아니다.

	return 0;
}