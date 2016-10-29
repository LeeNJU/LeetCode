#include<vector>
#include<string>
#include<unordered_map>
//题目描述:给定两个字符串s和p，在s中找到所有的子字符串的起始下标，使得子字符串和p是anagram，例如给定字符串
//        s = "cbaebabacd", p = "abc",返回[0,6]
//解法描述:hashtable和sliding window，count表示当前sliding window中出现了多少个p中的字符，如果sliding 
//        window的长度等于p的长度并且count等于0，说明找到一个anagram，

std::vector<int> findAnagrams(std::string s, std::string p) 
{
	std::vector<int> result;
	std::unordered_map<char, int> map;
	for (char c : p)
		++map[c];

	int count = p.size();
	for (int i = 0, j = 0; j < s.size(); ++j)
	{
		if (map.find(s[j]) != map.end() && --map[s[j]] >= 0)//注意这里更新count的条件
			--count;

		if (j - i + 1 == p.size())
		{
			if (count == 0)
				result.push_back(i);
			if (map.find(s[i]) != map.end() && ++map[s[i]] >= 1)//更新count的条件
				++count;
			++i;
		}
	}

	return result;
}