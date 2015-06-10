#include<string>
#include<vector>

//题目描述：给定一个字符串，划分该字符串，使得每一个子串都是palindrome，返回所有可能的结果
//解法描述：类似于深搜，递归调用

bool isPalindrome(const std::string& s)
{
	for (int i = 0, j = s.size() - 1; i <= j; ++i, --j)
	{
		if (s[i] != s[j])
			return false;
	}
	return true;
}

void dfs(std::vector<std::vector<std::string>>& result, std::vector<std::string> intermediate, const std::string& s, int start)
{
	if (start >= s.size())
	{
		result.push_back(intermediate);
		return;
	}

	for (int i = start; i < s.size(); ++i)
	{
		if (isPalindrome(s.substr(start, i - start + 1)))
		{
			intermediate.push_back(s.substr(start, i - start + 1));
			dfs(result, intermediate, s, i + 1);
			intermediate.pop_back();
		}
	}
}

std::vector<std::vector<std::string>> partition(std::string s)
{
	std::vector<std::vector<std::string>> result;
	std::vector<std::string> intermediate;
	dfs(result, intermediate, s, 0);
	return result;
}