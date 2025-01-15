#include <iostream>
#include <algorithm>

using namespace std;

// 로또번호 뽑기
// 1. 1 ~ 45의 숫자 중에서 중복없이 7개의 숫자를 뽑는다.
// 2. 이를 정렬한다.
// 3. 출력한다.

//            1      2
void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

//     i
//              j
// [4][3][2][1][5]
// 
// 순차정렬
void Sort(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[j] > arr[i])
				Swap(arr[j], arr[i]);
		}
	}
}

// Swap을 좀 줄이고 싶다.
void SelectSort(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int bestIndex = i;
		for (int j = i; j < size; j++)
		{
			if (arr[j] < arr[bestIndex])
			{
				bestIndex = j;
			}
		}

		if (bestIndex != i)
			Swap(arr[i], arr[bestIndex]);
	}
}


// [5][4][3][2][1]
// [4][5][3][2][1] - Swap
// [4][3][5][2][1] - Swap
// [4][3][2][5][1] - Swap
// [4][3][2][1][5] - Swap
// [4][3][2][1]  [5]
// [3][2][1]  [4][5]

void BubbleSort(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i; j++)
		{
			if (arr[j] > arr[j+1])
				Swap(arr[j], arr[j+1]);
		}
	}
}

void PrintArr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}

void Shuffle(int arr[], int size, int count = 10000)
{
	for (int i = 0; i < count; i++)
	{
		int randNum1 = rand() % size;
		int randNum2 = rand() % size;

		Swap(arr[randNum1], arr[randNum2]);
	}
}

void Lotto()
{
	// 7개의 랜덤하고, 중복되지 않은 수
	// 구현
	int arr[45] = {};
	for (int i = 0; i < 45; i++)
	{
		arr[i] = i + 1;
	}

	Shuffle(arr, 45, 10000);

	// 정렬
	BubbleSort(arr, 7);

	// 출력
	PrintArr(arr,7);
}

int main()
{
	Lotto();

	return 0;
}