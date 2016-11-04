#include<string>
#include<vector>
//题目描述:给定一个非负数字，把数字转换成英文表示形式，例如123，返回"One Hundred Twenty Three"，12345返回
//        "Twelve Thousand Three Hundred Forty Five"
//解法描述:每3位数字看成一个group，使用digits和tens数组，然后递归

std::string int2string(int n, const std::vector<std::string>& digits, 
						const std::vector<std::string>& tens) 
{
	if (n >= 1000000000) 
		return int2string(n / 1000000000, digits, tens) + " Billion" + int2string(n % 1000000000, digits, tens);
	else if (n >= 1000000) 
		return int2string(n / 1000000, digits, tens) + " Million" + int2string(n % 1000000, digits, tens);
	else if (n >= 1000) 
		return int2string(n / 1000, digits, tens) + " Thousand" + int2string(n % 1000, digits, tens);
	else if (n >= 100) 
		return int2string(n / 100, digits, tens) + " Hundred" + int2string(n % 100, digits, tens);
	else if (n >= 20) 
		return  " " + tens[n / 10] + int2string(n % 10, digits, tens);
	else if (n >= 1) 
		return " " + digits[n];
	else 
		return "";
}

std::string numberToWords(int num) 
{
	if (num == 0) 
		return "Zero";
	else 
	{
		std::vector<std::string> digits = { "Zero", "One", "Two", "Three", "Four", "Five", "Six", 
			"Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", 
			"Sixteen", "Seventeen", "Eighteen", "Nineteen" };
		std::vector<std::string> tens = { "Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", 
			"Sixty", "Seventy", "Eighty", "Ninety" };
		std::string result= int2string(num, digits, tens);
		return result.substr(1, result.length() - 1);
	}
}