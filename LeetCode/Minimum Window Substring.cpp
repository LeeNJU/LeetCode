#include<vector>
#include<unordered_map>
#include<algorithm>

//题目描述：给定两个字符串s和t，在s中找到最小的长度的子串，使得子串包含t中所有字符，例如s="ADOBECODEBANC"，t="ABC"，结果为"BANC"
//解法描述：此题要考虑的情况很多！先用1个hashtable保存字符串t出现的元素以及次数，再用i和j两个指针维护一个小区间，用j遍历字符串s，用hashtable记录
//出现的元素以及次数，同时用count记录总共出现了多少个t中的元素，这里要注意重复的元素（看代码注释）。当i和j的区间包含整个t的时候，从i开始遍历，企图
//收缩i，使得长度最小，就相当于找到了一个解，记录遇到的最小的解，然后继续用j遍历字符串s

std::string minWindow(std::string s, std::string t)
{
	if (s.size() < t.size())
		return "";

	int min_length = INT_MAX; //保存结果的最小长度和相应的起始下标
	int min_start = 0;
	std::unordered_map<char, int> appeared_count;
	std::unordered_map<char, int> expected_count;//这是为了防止t中有重复元素，必须记录每个元素出现的次数
	for (int i = 0; i < t.size(); ++i)
		++expected_count[t[i]];
	
	int count = 0;
	for (int i = 0, j = 0; j < s.size(); ++j)
	{
		if (expected_count.count(s[j]) > 0)//在t中包含当前元素
		{
			++appeared_count[s[j]];//记录出现次数
			if (appeared_count[s[j]] <= expected_count[s[j]])//防止多于的重复出现，例如s="AAA", t="A",那么算做出现一次
				++count;
		}

		if (count == t.size())//出现完整的t
		{
			while (expected_count.count(s[i]) == 0 || appeared_count[s[i]] > expected_count[s[i]])//循环结束后，代表求出一个解
			{
				--appeared_count[s[i]];
				++i;
			}
			if (j - i + 1 < min_length)//如果当前解更优，保存
			{
				min_length = j - i + 1;
				min_start = i;
			}
		}
	}

	if (min_length == INT_MAX)
		return "";
	return s.substr(min_start, min_length);
}