#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool Find_if(int element)
{
	if (element > 25)
		return true;
	return false;
}

void Multiple(int& value)
{
	value *= 3;
}

int main()
{
	vector<int> v = { 31, 23, 3, 2, 1, 3, 12, 15, 19 };

	// 1. v에서 23이 있는 원소의 자리(index, iter)를 찾아주세요.
	vector<int>::iterator iter = std::find(v.begin(), v.end(), 23);
	if (iter != v.end()) // 찾았다.
	{
		cout << *iter << endl;
	}
	 
	// 2. v에서 25보다 큰 수가 있다면 그 자리를 찾아주세요.
	iter = std::find_if(v.begin(), v.end(), &Find_if);

	struct Find_If_Functor
	{
		bool operator()(int element)
		{
			if (element > compareNum)
				return true;
			return false;
		}

		int compareNum;
	};
	Find_If_Functor functor1;
	functor1.compareNum = 25;
	iter = std::find_if(v.begin(), v.end(), functor1);

	functor1.compareNum = 27;
	iter = std::find_if(v.begin(), v.end(), functor1);

	cout << *iter << endl;

	// 3. v에서 3의 개수가 몇개인지
	int count = std::count(v.begin(), v.end(), 3);
	// 4. v에서 10보다 큰 수는 몇개인지
	functor1.compareNum = 10;
	count = std::count_if(v.begin(), v.end(), functor1);
	// 5. v에서 모든 수가 50보다 작은지 all_of
	// 6. v에서 하나라도 20보다 크고 30보다 작은 수가 있는지 any_of
	// 7. v의 배열을 꺼꾸로 만들어주세요. reverse
	// 8. 각 v의 원소에 3을 곱해주세요.
	std::for_each(v.begin(), v.end(), Multiple); // FN은 각 원소가 매개변수로 들어가는 함수 시그니쳐를 가져야한다.
	// 9. v를 정렬해주세요.
	std::sort(v.begin(), v.end(), less<int>());
	// 10. v에서 중복된 원소가 있다면 삭제해주세요.
	v.erase(std::unique(v.begin(), v.end()), v.end());
	// 11. v에서 45인 원소가 있다면 삭제
	v.erase(std::remove(v.begin(), v.end(), 45));
	
	// 12. v에서 20보다 작은 원소들 삭제
	struct Remove_IF
	{
		bool operator()(const int& element)
		{
			return element < removeCompare;
		}

		int removeCompare;
	};

	Remove_IF fn;
	fn.removeCompare = 20;
	v.erase(std::remove_if(v.begin(), v.end(), fn), v.end());

	// 57을 iter로 for문 돌면서 지우기
	for (auto iter = v.begin(); iter != v.end(); iter++)
	{
		if (*iter == 57)
		{
			iter = v.erase(iter);
		}
	}

	return 0;
}