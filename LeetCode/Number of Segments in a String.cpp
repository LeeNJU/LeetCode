#include<string>
//题目描述:给定一个字符串，字符串中的字符用空格隔开，求多少个隔开的字符，例如"Hello, my name is John"，总共有
//        5个被空格隔开的字符串
//解法描述:忽略开头的空格，注意中间连续的空格

int countSegments(std::string s) 
{
	int count = 0;
	int index = 0;
	while (index < s.size() && s[index] == ' ')//去掉leading的空格
		++index;

	if (index >= s.size())//全是空格
		return 0;

	for (; index < s.size(); ++index)//注意连续的空格
	{
		if (s[index] == ' ' && s[index - 1] != ' ')
			++count;
	}

	if (s.back() != ' ')
		++count;
	return count;
}