#pragma once
#include <iostream>
using namespace std;

template<typename T>
class List
{
public:
	List();
	~List();
	void push_back(T Data);
	int GetSize() { return Size; };
	T& operator[](const int Index);

	T pop()
	{
		if (head != nullptr)
		{
			T Val;
			Val = head->Data;
			head = head->pNext;
			return Val;
		}
	}

	T top()
	{
		if (head != nullptr)
		{
			T Val;
			Val = head->Data;
			return Val;
		}
	}

	bool isEmpty()
	{
		if (head == nullptr)
			return 0;
		else return 1;
	}

	void print()
	{
		if (head == nullptr)
		{
			std::cout << "Empty";
			throw - 1;
		}
		else
		{
			ptr = new Node<T>;
			ptr = head;
			while (ptr != nullptr)
			{
				std::cout << ptr->Data << " ";
				ptr = ptr->pNext;
			}
		}
	}
private:
	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T Data;
		Node(T _Data = T(), Node* _pNext = nullptr) :Data(_Data), pNext(_pNext) {}
	};
	int Size;
	Node<T>* head;
	Node<T>* ptr;
};

template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
};

template<typename T>
List<T>::~List()
{
	while (head != (nullptr))
	{
		Node<T>* p = head;
		head = head->pNext;
		delete p;
	}
}

template<typename T>
void List<T>::push_back(T data)
{
	ptr = new Node<T>;
	if (ptr != nullptr)
	{
		ptr->Data = data;
		ptr->pNext = head;
		head = ptr;
	}
	/*
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	Size++;*/
}

template<typename T>
T& List<T>::operator[](const int Index)
{
	Node<T>* current = this->head;
	int counter = 0;
	while (current != nullptr)
	{
		if (counter == Index)
		{
			return current->Data;
		}
		else current = current->pNext;
		counter++;
	}
}

