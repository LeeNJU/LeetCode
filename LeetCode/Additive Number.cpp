#include<string>
#include<vector>
//题目描述:给定一个数字字符串，判断其是不是additive number，例如"112358"是additive number，因为可以被分成
//        "1", "1", "2", "3", "5", "8"并且满足1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8，其中以0开头的
//        数字字符串是非法字符串，例如"02"
//解法描述:先枚举第一个数和第二个数，然后两个数相加，递归判断剩下的字符串是否等于两个数之和。

bool isValid(std::string num1, std::string num2, std::string num)
{   //非法字符串
	if (num1.size() > 1 && num1[0] == '0' || num2.size() > 1 && num2[0] == '0') 
		return false;
	
	std::string sum = std::to_string(std::stol(num1) + std::stol(num2));
	if (num == sum) 
		return true;
	if (num.size() <= sum.size() || sum.compare(num.substr(0, sum.size())) != 0) 
		return false;
	else 
		return isValid(num2, sum, num.substr(sum.size()));//递归判断
}

bool isAdditiveNumber(std::string num) 
{   //i和j代表第一和第二个数的长度
	for (int i = 1; i <= num.size() / 2; ++i)//第一个数的长度肯定不会超过字符串的第一半
	{
		for (int j = 1; j <= (num.size() - i) / 2; ++j)//第二个数的长度也不会超过剩余字符串的一半
		{
			if (isValid(num.substr(0, i), num.substr(i, j), num.substr(i + j))) 
				return true;
		}
	}
	return false;
}