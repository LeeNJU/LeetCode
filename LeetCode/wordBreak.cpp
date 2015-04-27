#include<string>
#include<vector>
#include<unordered_set>
//题目描述：给定一个字符串和字符串数组，判断该字符串能否被拆分成字符串数组中的单词，例如s = "leetcode"， dict = "leet", "code"， 那么s能被拆分
//解法描述：动态规划 转移方程vec[i] = any_of(vec[j]&&s[j + 1; i] 属于 dict); 0 <=j < i

bool wordBreak(std::string s, std::unordered_set<std::string>& wordDict)
{
	std::vector<bool> vec(s.size() + 1, false);
	vec[0] = true;
	for (int i = 1; i <= s.size(); ++i) 
	{
		for (int j = i - 1; j >= 0; --j)//注意这里是逆向遍历
		{
			if (vec[j] && wordDict.find(s.substr(j, i - j)) != wordDict.end()) 
			{
				vec[i] = true;
				break;
			}
		}
	}
	return vec[s.size()];
}