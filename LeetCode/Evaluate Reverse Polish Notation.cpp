#include<stack>
#include<vector>
#include<string>

//题目描述：算出逆波兰表达式的值，2 1 + 3 * = 9
//解法描述：用栈保存数字，根据运算符进行运算，把结果保存到栈中，最后的结果就在栈中

bool isOperator(std::string s)
{
	return s.size() == 1 && std::string("+-*/").find(s) != std::string::npos;
}

int evalRPN(std::vector<std::string> &tokens)
{
	std::stack<int> s;
	for (int i = 0; i < tokens.size(); ++i)
	{
		if (!isOperator(tokens[i]))
			s.push(stoi(tokens[i]));//stoi把string转换成int
		else//取出栈顶的2个元素，根据运算符号进行运算
		{
			int x = s.top();//注意取出的两个元素的顺序，尤其是进行除法或者减法的时候
			s.pop();
			int y = s.top();
			s.pop();
			if (tokens[i] == "+")
				s.push(x + y);
			else if (tokens[i] == "-")
				s.push(y - x);
			else if (tokens[i] == "*")
				s.push(x * y);
			else
				s.push(y / x);
		}
	}
	return s.top();
}