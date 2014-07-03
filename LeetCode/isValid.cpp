#include<iostream>
#include<string>
#include<stack>

using namespace std;

bool isValid(string s)
{
	if (s.length() % 2 != 0)//如果是奇数直接返回false
		return false;

	stack<char> stack;//用栈记录之前的符号
	for (size_t i = 0; i < s.length(); ++i)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			stack.push(s[i]);
		else if (s[i] == ')')
		{
			if (stack.empty() || stack.top() != '(')//要判断栈是否为空
				return false;
			stack.pop();
		}
		else if (s[i] == ']')
		{
			if (stack.empty() || stack.top() != '[')
				return false;
			stack.pop();
		}
		else
		{
			if (stack.empty() || stack.top() != '{')
				return false;
			stack.pop();
		}
	}
	if (!stack.empty())//循环结束，如果栈不为空，则为false
		return false;
	return true;
}

