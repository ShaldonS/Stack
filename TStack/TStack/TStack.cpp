#include <algorithm>
#include <stack>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	stack <char> steck;
	string str = "2 * 4 + 3";


	cout << str;

	string out = "";

	//оформить функцией
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ') continue;
		switch (str[i])
		{
		case '(': steck.push('('); break;
		case ')':

			while (!steck.empty() || steck.top() != '(')
			{
				out.push_back(steck.top());
				steck.pop();
			}
			steck.pop();
			break;

		case '+':
			if (steck.empty())
				steck.push('+');
			else
			{
				while (!steck.empty())
				{
					if (steck.top() != '(')
					{
						out.push_back(steck.top());
						steck.pop();
					}
					else break;
				}
				steck.push('+');
			}
			break;
		case '-':
			if (steck.empty())
				steck.push('+');
			else
			{
				while (!steck.empty() || steck.top() != '(')
				{
					out.push_back(steck.top());
					steck.pop();
				}
				steck.push('+');
			}
			break;
		case '*':
		case '/':
			if (steck.empty())
				steck.push(str[i]);
			else
			{
				while (!steck.empty() || steck.top() == '*' || steck.top() == '/')
				{
					out.push_back(steck.top());
					steck.pop();
				}
				steck.push(str[i]);
			}
			break;
		default: out.push_back(str[i]);
		}
	}

	while (!steck.empty())
	{
		out.push_back(steck.top());
		steck.pop();
	}

	cout << endl << out;

	return 0;
}
