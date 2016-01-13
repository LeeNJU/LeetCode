#include<string>
#include<vector>
//题目描述:给定一个字符串，判断该字符串的某个组合能不能组成一个回文串，例如"aab"可以组成"aba"
//解法描述:如果能够组成回文串，那么字符出现的次数为偶数，最多只能有一个字符的出现次数为奇数
bool canPermutePalindrome(std::string s)
{
	int dict[256] = { 0 };
	std::vector<int> vec(256, 0);
	for (int i = 0; i < s.size(); ++i)//统计每个字符的次数
		++vec[s[i]];

	int count = 0;
	for (int i = 0; i<256; i++)//统计奇数字符的个数
	{
		if (vec[i] % 2 != 0)   
			++count;
	}

	return count <= 1;
}