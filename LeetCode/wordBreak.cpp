#include<string>
#include<vector>
#include<unordered_set>

//题目描述：给定一个字符串和字符串数组，判断该字符串能否被拆分成字符串数组中的单词，例如s = "leetcode"， dict = "leet", "code"， 那么s能被拆分
//解法描述：动态规划 转移方程vec[i] = any_of(vec[j]&&s[j + 1; i] 属于 dict); 0 <=j < i

bool wordBreak(std::string s, std::unordered_set<std::string>& wordDict)
{
	std::vector<bool> vec(s.size() + 1, false);
	vec[0] = true;
	for (int i = 0; i < s.size(); ++i)
	{
		for (int j = i; j >= 0; --j)//注意这里是逆向遍历
		{
			if (vec[j] && wordDict.find(s.substr(j, i - j + 1)) != wordDict.end())
			{
				vec[i + 1] = true;
				break;
			}
		}
	}
	return vec[s.size()];
}

//变种二
//题目描述：给定一个字符串和字符串数组，返回该字符串被拆分成字符串数组中的单词
//解法描述：直接递归生成所有的解，但是要注意剪枝

void GetAllSolution(int start, const std::string& s, const std::unordered_set<std::string>& dict, int len, std::string& result, std::vector<std::string>& solutions, std::vector<bool>& possible)
{
	if (start == len)
	{
		solutions.push_back(result.substr(0, result.size() - 1));//去除最后的空格
		return;
	}
	for (int i = start; i< len; ++i)
	{
		std::string piece = s.substr(start, i - start + 1);
		if (dict.find(piece) != dict.end() && possible[i + 1]) // 必须是剩余区间有解才继续递归
		{
			result.append(piece).append(" ");
			int beforeChange = solutions.size();
			GetAllSolution(i + 1, s, dict, len, result, solutions, possible);
			if (solutions.size() == beforeChange) // 判断剩余区间是否有解
				possible[i + 1] = false;
			result.resize(result.size() - piece.size() - 1);
		}
	}
}

std::vector<std::string> wordBreak2(std::string s, std::unordered_set<std::string>& dict) 
{
	std::string result;
	std::vector<std::string> solutions;
	int len = s.size();
	std::vector<bool> possible(len + 1, true); //possible[i]为true表示[i, n - 1]有解
	GetAllSolution(0, s, dict, len, result, solutions, possible);
	return solutions;
}

