#include<string>
//题目描述:给定一个字符串，判断字符串能否由某一个子字符串重复多次而得到。例如"abab", 该字符串可以由"ab"重复
//        两次得到，返回true，"abcabcabcabc"可以由"abc"重复四次，或者"abcabc"重复两次得到
//解法描述:该字符串既然可以由子字符串拼接而成，必然存在与第一个字符相等的字符，扫描字符串，如果碰到与第一个字符
//        相等的字符，说明该字符串可能是正确的子字符串

bool repeatedSubstringPattern(std::string str) 
{
	for (int i = 1; i < str.size(); ++i)
	{
		if (str[i] == str[0])
		{
			std::string s = str.substr(0, i);
			if ((int) str.size() % (int) s.size() != 0)
				continue;

			std::string res = "";
			int count = (int) str.size() / (int) s.size();
			while (count)
			{
				res += s;
				--count;
			}

			if (res == str)
				return true;
		}
	}
	return false;
}