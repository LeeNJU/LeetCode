#include<string>
#include<algorithm>
//题目描述：给定一个字符串s，找到其中最大的回文子串
//解法描述：暴力法，列举回文子串的中心字符，向左右两边扩展,要注意奇数回文串和偶数回文串的区别

int expandAroundCenter(const std::string& s, int left, int right)
{
	while (left >= 0 && right < s.length() && s[left] == s[right])//向两边扩张
	{
		--left;
		++right;
	}
	return right - left - 1;
}

std::string longestPalindrome(std::string s)
{
	int maxLength = 1, index = 0;//记录最大长度和开始的下标
	for (int i = 0; i < s.length(); ++i)
	{
		int length = 0;
		length = expandAroundCenter(s, i, i);//判断奇数回文串
		if (length > maxLength)
		{
			maxLength = length;
			index = i - length / 2;
		}

		length = expandAroundCenter(s, i, i + 1);//判断偶数回文串
		if (length > maxLength)
		{
			maxLength = length;
			index = i - length / 2 + 1;
		}
	}
	return s.substr(index, maxLength);
}