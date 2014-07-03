#include<iostream>
#include<string>
#include<stack>

using namespace std;

bool isValid(string s)
{
	if (s.length() % 2 != 0)//���������ֱ�ӷ���false
		return false;

	stack<char> stack;//��ջ��¼֮ǰ�ķ���
	for (size_t i = 0; i < s.length(); ++i)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			stack.push(s[i]);
		else if (s[i] == ')')
		{
			if (stack.empty() || stack.top() != '(')//Ҫ�ж�ջ�Ƿ�Ϊ��
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
	if (!stack.empty())//ѭ�����������ջ��Ϊ�գ���Ϊfalse
		return false;
	return true;
}

