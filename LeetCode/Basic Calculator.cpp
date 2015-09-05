#include<string>
#include<stack>
//题目描述：给定一个字符串表示数字之间的加减操作，包含数字，空格，括号和加减号，求出运算结果
//解法描述：直接去掉括号进行计算，用栈保存当前的运算的符号(正或者负)，用result直接计算结果
int calculate(std::string s)
{
	std::stack<int> stack;
	stack.push(1);
	stack.push(1);
	int result = 0;
	for (int i = 0; i < s.length(); ++i)
	{
		if (isdigit(s[i]))
		{
			int value = 0;
			for (; i < s.size() && isdigit(s[i]); ++i)
				value = value * 10 + s[i] - '0';
			
			--i;
			result += stack.top() * value;//与当前栈顶的符号相乘进行计算，减号被算成是负数
			stack.pop();
		}
		else if (s[i] == '+' || s[i] == '(')//碰到加号或者左括号，把栈顶元素再次入栈
			stack.push(stack.top());
		else if (s[i] == '-')//碰到减号，栈顶元素乘以-1
			stack.push(-1 * stack.top());
		else if (s[i] == ')')//碰到右括号，弹栈
			stack.pop();
	}
	return result;
}