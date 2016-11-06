#include<string>
//题目描述：实现strStr，从字符串haystack中找到字符串needle第一次出现的位置，返回下标
//解法：暴力解法，
int strStr(std::string haystack, std::string needle)
{
	if (needle.empty())//判断needle是否为空串，若是，直接返回0
		return 0;

	int lengthA = haystack.size(), lengthB = needle.size();
	for (int i = 0; i <= lengthA - lengthB; ++i)//注意是小于等于号,遍历字符串haystack
	{
		if (haystack[i] == needle[0])
		{
			if (needle == haystack.substr(i, needle.size()))
				return i;
		}
	}
	return -1;
}