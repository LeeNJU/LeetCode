#include<vector>
#include<string>
//题目描述:给定两个字符串，判断第一个字符串能不能由第二个字符串中的字符构成，例如"aa", "aab",返回true
//解法描述:记录第二个字符串的个数，判断第一个字符串中的字符出现次数是不是小于等于第二个

bool canConstruct(std::string ransomNote, std::string magazine) 
{
	std::vector<int> mag(256, 0);
	for (int i = 0; i < magazine.size(); ++i)
		++mag[magazine[i]];

	for (int i = 0; i < ransomNote.size(); ++i)
	{
		if (mag[ransomNote[i]] == 0)
			return false;

		--mag[ransomNote[i]];
	}
	return true;
}