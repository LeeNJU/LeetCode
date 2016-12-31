#include<string>
#include<stack>
#include"TreeNode.h"
//题目描述:给定字符串，将其转换成NestedInteger,例如"[123,[456,[789]]]",
//解法描述:利用栈，每次碰到'['，就代表有一个NestedInteger对象，压入栈中，遇到数字，将其加入到栈顶
//        NestedInteger中，遇到']',代表当前栈顶的NestedInteger结束了，弹出栈，把它加入到当前栈顶的
//        NestedInteger中

NestedInteger deserialize(std::string s) 
{
	if (s.empty() || s[0] != '[')
		return NestedInteger(stoi(s));

	std::stack<NestedInteger> stack;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '[')
			stack.push(NestedInteger());
		else if (isdigit(s[i]) || s[i] == '-')
		{
			int flag = 1;
			if (s[i] == '-')
			{
				flag = -1;
				++i;
			}

			int num = 0;
			for (; i < s.size() && isdigit(s[i]); ++i)
				num = num * 10 + s[i] - '0';
			--i;

			stack.top().add(NestedInteger(num * flag));
		}
		else if (s[i] == ']')
		{
			if (stack.size() > 1)//栈要大于1才能弹栈
			{
				NestedInteger n = stack.top();
				stack.pop();
				stack.top().add(n);
			}
		}
	}

	return stack.top();
}