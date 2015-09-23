#include<string>
#include<cctype>
#include<iostream>
//题目描述：给定一个字符串，把它转换成int
//要求，先忽略空格，找到第一个非空格的字符，要考虑第一个字符可能是+或者-，然后后面跟多个数字，把这些数字转换成int，
//这些有效数字后可以跟其他非数字字符，但不影响值。如果值越界了，返回INT_MAX或者INT_MIN.如果是非法字符，则返回0
//解法描述：先忽略前面的空白，直到第一个非空字符，再确定符号，剩下的简单了

int atoi(std::string str)
{
	const int length = str.length();
	int i = 0, result = 0, sign = 1;
	while (isblank(str[i]) && i < length)//忽略前面的空白符
		++i;

	if (str[i] == '-')
	{
		sign = -1;
		++i;
	}
	else if (str[i] == '+')
		++i;
	else
		;

	for (; i < length; ++i)
	{
		if (isdigit(str[i]))
		{
			if (result > INT_MAX / 10 || (result == INT_MAX / 10 && str[i] - '0' > INT_MAX % 10))//判断是否越界，要用最大值除以10来判断，注意此时result值为正
				return sign > 0 ? INT_MAX : INT_MIN;
			result = result * 10 + (str[i] - '0');

		}
		else
			break;
	}

	return  result * sign;
}
