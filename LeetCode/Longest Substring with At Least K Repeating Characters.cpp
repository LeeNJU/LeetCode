#include<string>
#include<unordered_map>
#include<algorithm>
//题目描述:给定一个字符串和k值，找到最长的子字符串，使得子字符串中的每个字符出现次数大于等于k，例如
//        "aaabb", k = 3,返回3，"ababbc", k = 2，返回5
//解法描述:递归，对当前字符串，统计每个字符的出现次数，如果每个字符出现次数都大于等于k，那么直接返回字符串长度，
//        如果有字符的次数小于k，以这些字符把整个字符串划分成小的字符串，那么最优解必然存在于这些小字符串中，
//        然后对这些小字符串递归调用。

int longestSubstring(std::string s, int k) 
{
	std::unordered_map<char, int> map;
	for (char c : s)  //统计字符次数
		++map[c];

	bool exist = true;
	auto iter = map.begin();
	while (iter != map.end())//判断是否每个字符的次数都大于等于k
	{
		if (iter->second < k)
		{
			exist = false;
			break;
		}
		++iter;
	}

	if (exist)
		return s.size();
	
	int result = 0;
	int i = 0, j = 0;
	for (; j < s.size(); ++j)
	{
		if (map[s[j]] < k) //找打一个次数小于k的字符，以此来划分整个字符串
		{
			result = std::max(result, longestSubstring(s.substr(i, j - i), k));
			i = j + 1;
		}
	}
	result = std::max(result, longestSubstring(s.substr(i, j - i), k));//注意这里结尾的字符串
	return result;
}