#include<string>
#include<algorithm>
#include<unordered_map>
//题目描述:给定一个字符串，找到最长的子串，使得其最多包含两个不同的字符，例如"eceba",最长的子串是"ece"
//解法描述:用hash表保存字符出现的次数，当hash表大小超过2的时候，删除左边的元素，删除的时候，只有当左边字符
//        出现次数为1的时候才能删除。

int lengthOfLongestSubstringTwoDistinct(std::string s)
{
	int result = 0, left = 0;
	std::unordered_map<char, int> m;
	for (int i = 0; i < s.size(); ++i)
	{
		++m[s[i]];
		while (m.size() > 2)
		{
			if (--m[s[left]] == 0)//出现次数为1，从hash表中删除，如果不为1，只能继续移动left 
				m.erase(s[left]);
			++left;
		}
		result = std::max(result, i - left + 1);
	}
	return result;
}