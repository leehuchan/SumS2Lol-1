#include <iostream>
#include <vector>
#include <list>

using namespace std;

#include "List.h"
#include "Vector.h"

// iterator : 반복자 (순회자)

int main()
{
	Vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);

	// vector는 임의접근연산자로 순회가 가능하다. <-> list는 순회불가능
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	// vector를 iter로 순회하는 방법
	Vector<int>::Iterator iter;
	iter = v.begin();
	for (iter; iter != v.end(); iter++)
	{
		cout << *iter << endl;
	}

	iter = v.begin();

	return 0;
}