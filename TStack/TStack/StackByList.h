#include "List.h"

#pragma once
#include <iostream>

template<class T>
class Stack
{
public:
	Stack()
	{
	}

	~Stack()
	{
	}

	void push(T value)
	{
		el.push_back(value);
	}

	T pop()
	{
		return el.pop();
	}

	void top()
	{
		cout << el.top();
	}

	bool isEmpty()
	{
		el.isEmpty();
	}

	void print()
	{
		el.print();
	}
private:
	List<T> el;
};