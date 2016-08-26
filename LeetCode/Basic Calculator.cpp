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

//version2:运算符号包括加减乘除
//解法描述:用一个stack保存数字，另一个stack保存操作符。当得到一个数字并且符号栈的栈顶元素是乘号或者除号的时
//        候，进行乘除操作，直到符号栈顶元素不是乘除号为止，把计算结果压入数字栈中。这样循环结束时，符号栈中
//        就只包含加减号。然后对栈里的元素进行求值。另一个技巧是把减号当成负号，这样栈里就只剩加号，进行累加
//        就可以了
int calculate2(std::string s)
{
	std::stack<int> num;
	std::stack<char> op;
	int result = 0;
	int sign = 1; //读到减号，把sign设为-1
	for (int i = 0; i < s.length(); ++i)
	{
		if (isblank(s[i]))
			continue;
		else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
		{
			if (s[i] == '-')//读到减号，把sign设为-1，并且把加号压入栈中
			{
				sign = -1;
				op.push('+');
			}
			else
				op.push(s[i]);
		}
		else
		{
			int value = s[i++] - '0';
			for (; i < s.length() && isdigit(s[i]); ++i)//计算数字
				value = value * 10 + s[i] - '0';
			--i;
			if (op.empty() || (op.top() != '*' && op.top() != '/'))//如果符号栈为空或者栈顶元素不是乘除号，入栈
			{
				num.push(value * sign);
				sign = 1; //注意这里
				continue;
			}
			int t = 0;
			while (!op.empty() && !num.empty() && (op.top() == '*' || op.top() == '/'))
			{
				if (op.top() == '*')
					t += num.top() * value;
				else if (op.top() == '/')
					t += num.top() / value;

				op.pop();
				num.pop();
			}
			num.push(t * sign);
			sign = 1;
		}
	}

	if (op.empty())
		return num.top();

	result = num.top();
	num.pop();
	while (!op.empty()) //最后对栈里的元素进行累加
	{
		result += num.top();
		op.pop();
		num.pop();
	}
	return result;
}