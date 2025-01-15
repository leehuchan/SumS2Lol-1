#include <iostream>

using namespace std;

// 분기문
// if(조건절)
// {
//		실행문
// }
// else if(조건절)
// {}
// else
// {}

// switch(정수형)
// {
//	case :
//    break;
// 
//  default:
//    break;
// }

// while(조건)
// {
//	 실행문
//   제어문
//   continue
//   탈출(break)
// }

// for(초기화; 조건; 제어)
// {
//   실행
//   continue
//   탈출(break)
// }

int main()
{
	int aInt = 3;

#pragma region 조건문
	bool check = aInt > 3;
	if (aInt > 3)
	{
		cout << "aInt가 3보다 큽니다." << endl;
	}
	else if (aInt < 3)
	{
		cout << "aInt가 3보다 작습니다." << endl;
	}
	else
	{
		cout << "aInt는 3입니다." << endl;
	}

	switch (aInt)
	{
	case 1:
	{
		cout << "aInt는 1입니다." << endl;
		break;
	}
	case 2:
	{
		cout << "aInt는 2입니다." << endl;
		break;
	}
	case 3:
	case 4:
	{
		cout << "aInt는 3혹은 4입니다." << endl;
		break;
	}

	default:
		break;
	}
#pragma endregion

	int count = 0;
	// 10번반복
	while (true)
	{
		count++; // 제어문
		if (count == 3)
			continue;

		cout << count << endl;

		if (count >= 10)
			break; // 탈출
	}

	for (int i = 0; i < 10; i++)
	{
		if (i == 3)
			continue;

		cout << i << endl;
	}

	//do
	//{

	//} while (true);

	return 0;
}