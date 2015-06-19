#include<string>
//题目描述：给定一个数字,该数字的范围1到3999，返回它的罗马数字表示形式
//解法描述：看代码吧

std::string intToRoman(int num)
{
	const int radix[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
	const std::string symbol[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
	std::string roman;
	for (size_t i = 0; num > 0; ++i) 
	{
		int count = num / radix[i];
		num %= radix[i];
		for (; count > 0; --count) 
			roman += symbol[i];
	}
	return roman;
}