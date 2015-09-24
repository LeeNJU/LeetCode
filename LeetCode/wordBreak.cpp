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

//变种二
//题目描述：给定一个字符串和字符串数组，返回该字符串被拆分成字符串数组中的单词
//解法描述：通过动态规划找到所有的解，再用递归生成所有的解

void gen_path(const std::string &s, const std::vector<std::vector<bool>>& prev,
	int cur, std::vector<std::string>& path, std::vector<std::string>& result) 
{
	if (cur == 0) 
	{
		std::string tmp;
		for (auto iter = path.rbegin(); iter != path.rend(); ++iter)
			tmp += *iter + " ";
		tmp.erase(tmp.end() - 1);
		result.push_back(tmp);
	}
	for (int i = 0; i < s.length(); ++i) 
	{
		if (prev[cur][i]) 
		{
			path.push_back(s.substr(i, cur - i));
			gen_path(s, prev, i, path, result);
			path.pop_back();
		}
	}
}

std::vector<std::string> wordBreak2(std::string s, std::unordered_set<std::string>& dict) 
{
	// 长度为n 的字符串有n+1 个隔板
	std::vector<bool> f(s.length() + 1, false);
	// path[i][j] 为true，表示s[j, i) 是一个合法单词，可以从j 处切开
	// 第一行未用
	std::vector<std::vector<bool>> prev(s.length() + 1, std::vector<bool>(s.length()));
	f[0] = true;
	for (int i = 1; i <= s.length(); ++i) 
	{
		for (int j = i - 1; j >= 0; --j) 
		{
			if (f[j] && dict.find(s.substr(j, i - j)) != dict.end()) 
			{
				f[i] = true;
				prev[i][j] = true;
			}
		}
	}
	std::vector<std::string> result;
	std::vector<std::string> path;
	gen_path(s, prev, s.length(), path, result);
	return result;
}