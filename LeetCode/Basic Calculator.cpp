#include<string>
#include<stack>

int value(const std::string& s, int index)
{
	int value = 0;
	for (int i = index; isdigit(s[i]) && i < s.size(); ++i)
	{
		value = value * 10 + s[i] - '0';
	}
	return value;
}

int calculate(std::string s)
{
	std::stack<std::string> exp;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '+' || s[i] == '-' || s[i] == '(')
			exp.push(s.substr(i, 1));
		else if (s[i] == ')')
		{
			std::string left, right;
			while (exp.top() != "(")
			{
				right = exp.top();
				exp.pop();
				std::string op = exp.top();
				exp.pop();
				left = exp.top();
				exp.pop();
				if (op == "+")

			}
		}
	}
}