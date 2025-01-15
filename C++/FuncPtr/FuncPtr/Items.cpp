#include <iostream>

using namespace std;

struct Item
{
	Item() :id(0), price(0), value(0) {}
	Item(int id, int price, int value) : id(id), price(price), value(value) {}

	void PrintItem()
	{
		cout << "ID : " << id << endl;
		cout << "Price : " << price << endl;
		cout << "Value : " << value << endl;
	}

	int id;
	int price;
	int value;
};

#pragma region 값으로 찾기
Item* FindItemByValue(Item arr[], int size, int value)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i].value == value)
			return &arr[i];
	}

	return nullptr;
}
#pragma endregion

#pragma region 함수포인터를 전달해서 찾기
typedef bool(*ItemFunc)(const Item&);
Item* FindItemByFuncPtr(Item arr[], int size, ItemFunc fn)
{
	for (int i = 0; i < size; i++)
	{
		if (fn(arr[i]))
			return &arr[i];
	}

	return nullptr;
}

bool FindItemValue(const Item& item)
{
	// value가 5인 얘 찾고 싶다.
	if (item.value == 5)
		return true;
	return false;
}

bool FindItemPrice(const Item& item)
{
	// price가 3000인 얘 찾고 싶다.
	if (item.price == 3000)
		return true;
	return false;
}
#pragma endregion

#pragma region 함수객체를 전달해서 찾기
struct Finder_Price
{
	bool operator()(const Item& item)
	{
		if (item.price == compare_Price)
			return true;
		return false;
	}

	int compare_Price;
};

// 1. Price와 Value를 속성으로 갖고 찾을 수 있는 함수객체
struct Finder_PriceValue
{
	bool operator()(const Item& item)
	{
		if (item.price == compare_Price && item.value == compare_Value)
			return true;
		return false;
	}

	int compare_Price;
	int compare_Value;
};

// 2. id, price value 속성으로 갖고 찾을 수 있는 함수객체
struct Finder_IdPriceValue
{
	bool operator()(const Item& item)
	{
		if (item.id == compare_Id && item.price == compare_Price && item.value == compare_Value)
			return true;
		return false;
	}

	int compare_Id;
	int compare_Price;
	int compare_Value;
};

template <typename T>
Item* FindItemByFunctor(Item arr[], int size, T functor)
{
	for (int i = 0; i < size; i++)
	{
		if (functor(arr[i]))
			return &arr[i];
	}

	return nullptr;
}

int main()
{
	Item items[10];

	for (int i = 0; i < 10; i++)
	{
		items[i].id = i;
		items[i].price = 10000 - 1000 * i;
		items[i].value = 10 - i;
	}

	// items에서 value가 5인 아이템이 있으면 아이템 정보 출력
	Item* findItem = nullptr;

	// Item 찾기
	findItem = FindItemByValue(items, 10, 5);

	if (findItem)
	{
		findItem->PrintItem();
	}

	// Item 찾기 value가 5인
	findItem = FindItemByFuncPtr(items, 10, &FindItemValue);

	if (findItem)
	{
		findItem->PrintItem();
	}

	// Item 찾기 price 3000
	findItem = FindItemByFuncPtr(items, 10, &FindItemPrice);
	if (findItem)
	{
		findItem->PrintItem();
	}

	// Item 찾기 price 5000
	Finder_Price functor;
	functor.compare_Price = 5000;
	findItem = FindItemByFunctor<Finder_Price>(items, 10, functor);
	if (findItem)
	{
		findItem->PrintItem();
	}

	// Item 찾기 price 2000
	functor.compare_Price = 2000;
	findItem = FindItemByFunctor<Finder_Price>(items, 10, functor);
	if (findItem)
	{
		findItem->PrintItem();
	}

	// Price == 2000, value = 2
	Finder_PriceValue functor2;
	functor2.compare_Price = 2000;
	functor2.compare_Value = 2;
	findItem = FindItemByFunctor<Finder_PriceValue>(items, 10, functor2);
	if (findItem)
	{
		findItem->PrintItem();
	}

	// Price == 7000, value = 7 , id = 3
	Finder_IdPriceValue functor3;
	functor3.compare_Id = 3;
	functor3.compare_Price = 7000;
	functor3.compare_Value = 7;
	findItem = FindItemByFunctor<Finder_IdPriceValue>(items, 10, functor3);
	if (findItem)
	{
		findItem->PrintItem();
	}

	return 0;
}