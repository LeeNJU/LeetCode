#include<vector>
#include<string>
#include<unordered_set>
#include<algorithm>
//题目描述:给定一个字符串数组(没有重复)，找到其中所有的字符串，使得该字符可以由数组中至少两个字符串拼接而成，例如
//        ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"],返回
//        ["catsdogcats","dogcatsdog","ratcatdogcat"]，因为"catsdogcats"可以由"cats","dot"和"cats"组成，
//        要求返回所有的字符串
//解法描述:动态规划，类似于word break，先根据字符串长度排序，判断每一个字符串的时候，把之前的所有字符串加入到
//        hashset中

static int compare(const std::string& s1, const std::string& s2)
{
	return s1.size() < s2.size();
}

bool canForm(const std::string& s, const std::unordered_set<std::string>& set)
{        //判断这个字符串是否能由hashset中的字符串组成
	if (s.empty())
		return false;

	std::vector<bool> dp(s.size() + 1, false);
	dp[0] = true;

	for (int i = 0; i < s.size(); ++i)
	{
		for (int j = i; j >= 0; --j)
		{
			if (!dp[j])
				continue;

			std::string str = s.substr(j, i - j + 1);
			if (set.find(str) != set.end())
				dp[i + 1] = dp[i + 1] | dp[j];
			if (dp[i + 1])
				break;
		}
	}

	return dp.back();
}

std::vector<std::string> findAllConcatenatedWordsInADict(std::vector<std::string>& words) 
{
	std::sort(words.begin(), words.end(), compare);
	std::unordered_set<std::string> set;

	std::vector<std::string> result;
	for (const std::string& s : words)//注意这里，考虑当前元素的时候，不能把当前元素加入到hashset中
	{
		if (canForm(s, set))
			result.push_back(s);
		set.insert(s);
	}

	return result;
}