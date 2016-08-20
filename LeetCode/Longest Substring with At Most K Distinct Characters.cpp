#include<string>
#include<unordered_map>
#include<algorithm>
//题目描述:给定一个字符串和一个k值，找到最长的子串，使得子串最多包含k个不同的字符，例如:"eceba",k=2,最长的包
//        含k个字符的子串是"ece"
//解法描述:用hash表保存字符以及出现次数，当hash表的大小超过k的时候，删除左边的字符，使得hash表大小小于k
int lengthOfLongestSubstringKDistinct(std::string s, int k) 
{
	int result = 0, left = 0;
	std::unordered_map<char, int> m;
	for (int i = 0; i < s.size(); ++i) 
	{
		++m[s[i]];
		while (m.size() > k) 
		{
			if (--m[s[left]] == 0)//出现次数为1，从hash表中删除，如果不为1，只能继续移动left 
				m.erase(s[left]);
			++left;
		}
		result = std::max(result, i - left + 1);
	}
	return result;
}