#include<iostream>
#include<string>
#include<stack>

//题目描述：给定一个字符串，只包含([{)]}几种字符，判断是否是有效的字符串，即(),[],{}是有效的，(],([)]等都是无效的
//解法描述：用一个栈把([[压入栈中，遇到)]}时，判断与栈顶元素是否相配

bool isValid(std::string s)
{
	if (s.length() % 2 != 0)//如果是奇数直接返回false
		return false;

	std::stack<char> stack;//用栈记录之前的符号
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
	
	return stack.empty();//循环结束，如果栈不为空，则为false
}

