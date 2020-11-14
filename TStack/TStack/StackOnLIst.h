#pragma once
#include <iostream>
template<class T>
struct Node
{
	T val;
	Node* next;
};

template<class T>
class Stack
{
public:
	Stack()
	{
		top = nullptr;
	}

	~Stack()
	{
		if (top == nullptr)
		{
			std::cout << "Stack is empty";
			throw - 1;
		}
		else
		{
			while (ptr != nullptr)
			{
				delete ptr;
				ptr = ptr->next;
			}
		}
		top = nullptr;
	}

	void Push(T value)
	{
		ptr = new Node<T>;
		if (ptr != nullptr)
		{
			ptr->val = value;
			ptr->next = top;
			top = ptr;
		}
	}

	T Pop()
	{
		if (top != nullptr)
		{
			T Val;
			Val = top->val;
			top = top->next;
			return Val;
		}
	}

	T Top()
	{
		if (top != nullptr)
		{
			T Val;
			Val = top->val;
			return Val;
		}
	}

	bool isEmpty()
	{
		if (top == nullptr)
			return 0;
		else return 1;
	}

	void Print()
	{
		if (top == nullptr) 
		{
			std::cout << "Empty"; 
			throw - 1;
		}
		else
		{
			ptr = top;
			while (ptr != nullptr)
			{
				std::cout << ptr->val << " ";
				ptr = ptr->next;
			}
		}
	}
private:
	Node<T>* top;
	Node<T>* ptr;
};