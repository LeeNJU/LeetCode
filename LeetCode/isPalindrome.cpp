#include<string>
#include<cctype>
//题目描述：给定一个字符串(只包含数字和字母)，判断其是否是回文串，忽略大小写
//解法：两个头尾指针向中间逼近，其中要忽略空格的情况

bool isPalindrome(std::string s)
{
	int first = 0, last = s.length() - 1;
	while (first <= last)
	{
		if (!isalnum(s[first]))//判断是否为空格
		{
			++first;
		}
		else if (!isalnum(s[last]))//判断是否为空格
		{
			--last;
		}
		else
		{
			if (tolower(s[first]) != tolower(s[last]))//ignore case
				return false;
			else
			{
				++first;
				--last;
			}
		}
	}
	return true;
}