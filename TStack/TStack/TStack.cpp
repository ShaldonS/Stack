#include "TStack.h"
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;


void Check();//проверка скобок, знаков
double Result();//преобразование строки выражения в выражение с числами целочисленного типа и подсчет результата

Stack <char> myStack(10);
string str = "(6*(2+1)/(3)-1";
string out = "";
int count_war = 0;

int main(int argc, char* argv)
{
	setlocale(LC_ALL, "rus");

	cout << "Инфиксная форма: " << str <<  endl;

	Check();
	cout << "Ошибок: " << count_war << endl;
	cout << "Постфиксная форма: " << out << endl;
	cout << "Результат выражения: " << Result() << endl;

	return 0;
}

void Check()
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ') continue;
		switch (str[i]) {
		case '(':
			myStack.Push('(');
			break;
		case ')':
		{
			while (!myStack.isEmpty())
			{
				if (myStack.Top() != '(')
				{
					out.push_back(myStack.Top());
					myStack.Pop();
				}
				else
				{
					count_war++;
					break;
				}
			}
			myStack.Pop();
		}
		break;
		case '-':
		case '+':
			if (myStack.isEmpty()) myStack.Push(str[i]);
			else {
				while (!myStack.isEmpty())
				{
					if (myStack.Top() != '(')
					{
						out.push_back(myStack.Top());
						myStack.Pop();
					}
					else break;
				}
				myStack.Push(str[i]);
			}
			break;
		case '*':
		case '/':
			if (myStack.isEmpty()) myStack.Push(str[i]);
			else
			{
				while (!myStack.isEmpty() || myStack.Top() == '*' || myStack.Top() == '/')
				{
					if (myStack.Top() != '(')
					{
						out.push_back(myStack.Top());
						myStack.Pop();
					}
					else break;
				}
				myStack.Push(str[i]);
			}
			break;
		default: out.push_back(str[i]);
		}
	}
	out.push_back(myStack.Top());
}


double Result()
{
	double first, second;
	for (size_t i = 0; i < out.length(); i++)
	{
		switch (out[i]) {
		case '+':
			second = myStack.Top();
			first = myStack.Pop() + second;
			myStack.Pop();
			myStack.Push(first);
			break;
		case '-':
			second = myStack.Top();
			first = myStack.Pop() - second;
			myStack.Pop();
			myStack.Push(first);
			break;
		case '*':
			second = myStack.Top();
			first = myStack.Pop() * second;
			myStack.Pop();
			myStack.Push(first);
			break;
		case '/':
			second = myStack.Top();
			if (second == 0)
			{
				cout << "На ноль делить нельзя!\n";
				return 0;
			}
			else
				first = myStack.Pop() / second;
			myStack.Pop();
			myStack.Push(first);
			break;
		default: default: myStack.Push(out[i] - '0');
		}
		if (out[out.length() - 1] == '(')
		{
			cout << endl << "Вычисление невозможно" << endl;
			return 0;
		}

		if (str[i] == '(')
		{
			count_left++;
		}

		if (str[i] == ')')
		{
			count_right++;
		}
		cout << endl << str[i] << endl;
		cout << endl << "l: " << count_left << " r: " << count_right << endl;
	}
	if (count_left != count_right)
	{
		cout << endl << "Число открывающих скобок не равно числу закрывающих!" << endl;
		return 0;
	}
	return myStack.Top();
}
