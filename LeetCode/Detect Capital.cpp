#include<string>
#include<cctype>
//题目描述:给定一个字符串，判断是不是合法的字符串，如果全部是大写字母，或者全是小写字母，或者第一个字母是大写，
//        其余字母是小写，都是合法的字符串
//解法描述:统计大写字母和小写字母的个数，一次判断

bool detectCapitalUse(std::string word)
{
	int upper = 0, lower = 0;
	for (int i = 0; i < word.size(); ++i)
	{
		if (isupper(word[i]))
			++upper;
		else
			++lower;
	}

	return upper == word.size() || lower == word.size() || (upper == 1 && isupper(word[0]));
}