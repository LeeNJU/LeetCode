#include<string>
#include<stack>
#include<algorithm>
//题目描述：给定一个只包含()的字符串，找到最长的有效字符串，返回其长度，()为有效字符串
//解法描述：用一个栈记录未匹配的（的下标，用一个变量记录上一个）的下标，作为分隔符

int longestValidParentheses(std::string s)
{
	std::stack<int> left;
	int result = 0, last = -1;//last记录上一个）的下标，用做分隔符，分隔有效的字段
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '(')
			left.push(i);
		else
		{
			if (left.empty())//左边的（都已经得到匹配，此时的）表明上一个有效字段结束
				last = i;
			else
			{
				left.pop();//匹配一个
				if (left.empty())//这种情况：）（）（）
					result = std::max(result, i - last);
				else//这种情况：（（）（）
					result = std::max(result, i - left.top());
			}
		}
	}
	return result;
}
