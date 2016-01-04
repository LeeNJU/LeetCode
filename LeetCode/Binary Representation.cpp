#include<string>
//题目描述:给定一个字符串表示一个小数，把她转换成二进制形式，例如"3.5"转换成"11.1",如果小数部分不能用32个字符表示，返回
//        "ERROR"
//解法描述:分别得到整数部分和小数部分，转换成二进制，注意edge cases
std::string integer_binary(int n)//把整数转换成二进制
{
	std::string s = "";
	while (n)
	{
		if (n % 2 == 0)
			s += "0";
		else
			s += "1";

		n /= 2;
	}
	reverse(s.begin(), s.end());
	return s;
}

std::string fraction_binary(double num)//把小数转换成二进制
{
	std::string s = "";
	while (num)
	{
		num *= 2;
		if (num >= 1)
		{
			num -= 1;
			s += "1";
		}
		else
			s += "0";

		if (s.size() > 32)
			return "ERROR";
	}
	return s;
}
std::string binaryRepresentation(std::string n) 
{
	int index = n.size();
	for (int i = 0; i < n.size(); ++i)//找到小数点的位置
	{
		if (n[i] == '.')
		{
			index = i;
			break;
		}
	}

	std::string integer = integer_binary(stoi(n.substr(0, index)));//得到整数部分的二进制表示
	if (index == n.size())//没有小数部分
		return integer;

	std::string result;
	if (integer == "")//整数部分是0
		result += "0" + integer;
	else
		result = integer;

	std::string fraction = "0" + n.substr(index);
	fraction = fraction_binary(atof(fraction.c_str()));//得到小数部分的二进制表示
	
	if (fraction == "ERROR")
		return "ERROR";
	else if (fraction == "")//小数部分为0
		return result;
	else
		return result + "." + fraction;
}