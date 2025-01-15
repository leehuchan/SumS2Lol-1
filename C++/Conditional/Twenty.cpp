#include <iostream>

using namespace std;

// 아홉고개
// 1. 1 ~500의 숫자를 컴퓨터가 가지고있음. (난수)
// 2. 플레이어가 수를 입력함
// 3. 이를 9번 반복으로 수를 맞춰야함
// 4. UP / DOWN

int main()
{
	// 시점
	srand(time(NULL));

	int playerNum = 0;
	int computerNum = rand() % 500 + 1; // 0 ~ 499 + 1

	int count = 0;
	while (true)
	{
		cin >> playerNum;

		if (computerNum > playerNum)
		{
			cout << "UP" << endl;
		}
		else if (computerNum < playerNum)
		{
			cout << "DOWN" << endl;
		}
		else
		{
			cout << "정답입니다." << endl;
			break;
		}

		count++;

		if (count >= 9)
			break;
	}


	return 0;
}