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
	
}