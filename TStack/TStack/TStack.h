#pragma once
#include <iostream>

using namespace std;

const int MAX = 25;

template <class T>

class Stack
{
public:
	Stack(int size);
	~Stack();

	void Push(T);//äîáàâèòü ýëåìåíò
	T Pop();//ñ÷èòàòü è óäàëèòü âåðõíèé ýëåìåíò
	T Top();//âåðíóòü âåðõíèé ýëåìåíò
	bool isEmpty();//ïðîâåðêà íà ïóñòîòó
	bool isFull();//ïðîâåðêà íà ïîëíîòó
	void Print();//âûâåñòè ñòåê
private:
	T arr[MAX];
	int top;
	int size;
};

template <class T>
Stack<T>::Stack(int MAX)
{
	size = MAX;
	arr = new T[size];
	top = 0;
}

template <class T>
Stack<T>::~Stack()
{
	delete[]arr;
}

template <class T>
void Stack<T>::Push(T a)
{
	if (top == (size - 1)) 
	{
		throw overflow_error("Stack is full");
	}
	else 
	{
		top++;
		arr[top] = a;
	}
}

template <class T>
bool Stack<T>::isEmpty()
{
	return(top == 0);
}

template <class T>
bool Stack<T>::isFull()
{

	return(top = size);
}

template <class T>
T Stack<T>::Pop()
{
	if (top == -1)
	{
		throw underflow_error("Empty");
	}
	top--;
	int ret = arr[top];
	

	return ret;
}

template <class T>
T Stack<T>::Top()
{
	if (top == -1)
	{
		throw underflow_error("Empty");
	}
	int ret = arr[top];

	return ret;
}

template <class T>
void Stack<T>::Print()
{
	for (int i = 1; i < top+1; i++)
	{
		cout << arr[i];
	}
}


