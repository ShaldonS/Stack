#pragma once
#include <iostream>

using namespace std;

const int MAX = 25;

template <class T>

class Stack
{
public:
	Stack(double size);
	~Stack();

	void Push(T);//добавить элемент
	T Pop();//считать и удалить верхний элемент
	T Top();//вернуть верхний элемент
	bool isEmpty();//проверка на пустоту
	bool isFull();//проверка на полноту
	void Print();//вывести стек
private:
	T arr[MAX];
	int top;
	int size;
};

template <class T>
Stack<T>::Stack(double MAX)
{
	//size = MAX;
	//arr = new T[size];
	top = 0;
}

template <class T>
Stack<T>::~Stack()
{
	//delete[]arr;
}

template <class T>
void Stack<T>::Push(T a)
{
	top++;
	arr[top] = a;
}

template <class T>
bool Stack<T>::isEmpty()
{
	return(top == 0);
}

template <class T>
bool Stack<T>::isFull()
{

	return(top >= size);
}

template <class T>
T Stack<T>::Pop()
{
	top--;
	return arr[top];
}

template <class T>
T Stack<T>::Top()
{
	return arr[top];
}

template <class T>
void Stack<T>::Print()
{
	for (int i = 1; i < top+1; i++)
	{
		cout << arr[i];
	}
}




