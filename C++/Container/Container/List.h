#pragma once

template<typename T>
struct Node
{
	Node() :data(T()), prev(nullptr), next(nullptr) {}
	Node(const T& data) : data(data), prev(nullptr), next(nullptr) {}
	~Node() {}

	T data;
	Node<T>* prev;
	Node<T>* next;
};

template<typename T>
class List
{
public:
	class Iterator
	{
	public:
		Iterator() : _ptr(nullptr) {}
		Iterator(Node<T>* ptr) { _ptr = ptr; }
		Iterator(const Iterator& other){ _ptr = other._ptr; }

		T operator*()
		{
			return _ptr->data;
		}

		Iterator operator++(int)
		{
			Iterator result;
			result._ptr = _ptr;

			_ptr = _ptr->next;

			return result;
		}

		Iterator& operator++()
		{
			_ptr = _ptr->next;

			return *this;
		}

		bool operator==(const Iterator& other)
		{
			return _ptr == other._ptr;
		}

		bool operator!=(const Iterator& other)
		{
			return _ptr != other._ptr;
		}

	private:
		Node<T>* _ptr;
	};

	List()
	: _size(0)
	{
		_head = new Node<T>();
		_head->next = _head;
		_head->prev = _head;
	}

	~List()
	{
		clear();
		delete _head;
	}

	void clear()
	{
		int size = _size;
		for (int i = 0; i < size; i++)
		{
			pop_back();
		}
	}

	void push_back(const T& data)
	{
		Node<T>* newNode = new Node<T>(data);

		Node<T>* nextNode = _head;
		Node<T>* prevNode = _head->prev;

		newNode->next = nextNode;
		newNode->prev = prevNode;

		nextNode->prev = newNode;
		prevNode->next = newNode;

		_size++;
	}

	void push_front(const T& data)
	{
		Node<T>* newNode = new Node<T>(data);

		Node<T>* nextNode = _head->next;
		Node<T>* prevNode = _head;

		newNode->next = nextNode;
		newNode->prev = prevNode;

		nextNode->prev = newNode;
		prevNode->next = newNode;

		_size++;
	}

	void pop_back()
	{
		Node<T>* target = _head->prev;
		Node<T>* prevNode = target->prev;

		delete target;

		_head->prev = prevNode;
		prevNode->next = _head;

		_size--;
	}

	void pop_front()
	{
		Node<T>* target = _head->next;
		Node<T>* nextNode = target->next;

		delete target;

		_head->next = nextNode;
		nextNode->prev = _head;

		_size--;
	}

	// where노드의 next에 삽입
	void insert(const T& data, unsigned __int64 index)
	{
		Node<T>* newNode = new Node<T>(data);
		Node<T>* prev = at(index);
		Node<T>* next = prev->next;

		newNode->next = next;
		newNode->prev = prev;

		prev->next = newNode;
		next->prev = newNode;

		_size++;
	}

	T operator[](unsigned __int64 index)
	{
		if (index >= _size)
		{
			int* error = (int*)0xDEADBEEF;
			*(error) = 1;
			// ERROR
		}

		Node<T>* node = _head->next;

		for (int i = 0; i < index; i++)
		{
			node = node->next;
		}

		return node->data;
	}

	unsigned __int64 size() { return _size; }

	Iterator begin() { return Iterator(_head->next); }
	Iterator end() { return Iterator(_head); }

private:
	Node<T>* at(unsigned __int64 index)
	{
		if (index >= _size)
		{
			int* error = (int*)0xDEADBEEF;
			*(error) = 1;
			// ERROR
		}

		Node<T>* node = _head->next;

		for (int i = 0; i < index; i++)
		{
			node = node->next;
		}

		return node;
	}

	Node<T>* _head;
	unsigned __int64 _size;
};