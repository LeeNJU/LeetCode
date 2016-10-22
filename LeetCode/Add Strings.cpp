#include<string>
//题目描述:给定两个字符串表示两个整数，求两个数字的和，返回string，例如"11" + "9" = "20"
//解法描述:双指针依次扫描

std::string addStrings(std::string num1, std::string num2) 
{
	std::string result = "";
	int carry = 0;
	for (int i = num1.size() - 1, j = num2.size() - 1; i >= 0 || j >= 0; --i, --j)
	{
		int a = i >= 0 ? num1[i] - '0' : 0;
		int b = j >= 0 ? num2[j] - '0' : 0;

		result = std::to_string((a + b + carry) % 10) + result;
		carry = (a + b + carry) / 10;
	}

	if (carry > 0)
		result = "1" + result;
	return result;
}