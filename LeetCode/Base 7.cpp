#include<string>
//题目描述:给定一个数字n，用7进制表示，例如100， 7进制表示为202，-10表示为"-10"
//解法描述:依次除以7，注意负数，注意0

std::string convertToBase7(int num)
{
	if (num == 0)
		return "0";

	std::string result;
	bool flag = false;
	if (num < 0)
		flag = true;

	int base = 7;
	num = abs(num);
	while (num)
	{
		result = std::to_string(num % base) + result;
		num /= base;
	}

	return flag ? "-" + result : result;
}