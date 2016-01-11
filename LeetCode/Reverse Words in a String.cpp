#include<string>
//题目描述:给定一个字符串，包含多个单词，每个单词用一个或多个空格隔开，开头和结尾可能有空格，要求对反转字符串，
//        最后一个单词放在第一的位置，倒数第二个单词放在第二的位置，每个单词用一个空格隔开，开头和结尾不能有
//        空格
//解法描述:从后往前扫描
void reverseWords(std::string& s)
{
	std::string result;
	for (int i = s.size() - 1; i >= 0;)
	{
		while (i >= 0 && isspace(s[i]))//去除每个单词前面的空格
			--i;

		if (i < 0)//没有单词了
			break;

		int j = i;
		while (i >= 0 && !isspace(s[i]))
			--i;

		result += s.substr(i + 1, j - i) + ' ';
	}
	s = result.substr(0, result.size() - 1);
}

//version 2
//现在字符串开头和结尾没有空格，每个单词只用一个空格隔开，要求同上
//解法描述:把整个字符串反转一遍，然后吧每个单词再反转一遍
void reverse(std::string& s, int left, int right) 
{
	while (left < right)
		std::swap(s[left++], s[right--]);
}

void reverseWords(std::string& s) 
{
	reverse(s, 0, s.size() - 1);//反转整个字符串

	int first = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		if (isspace(s[i]))//找到一个单词
		{
			reverse(s, first, i - 1);
			first = i + 1;
		}
	}
	reverse(s, first, s.size() - 1);//反转结尾的单词
}