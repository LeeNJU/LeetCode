#include<string>
#include<vector>
#include<algorithm>
//题目描述：
//解法描述：bugs

bool isPalindrome(const std::string& s)
{
	for (int i = 0, j = s.size() - 1; i <= j; ++i, --j)
	{
		if (s[i] != s[j])
			return false;
	}
	return true;
}

int minCut(std::string s)
{
	std::vector<int> dp(s.size() + 1, -1);
	for (int i = 0; i < s.size(); ++i)
	{
		int min = INT_MAX;
		for (int j = 0; j <= i; ++j)
		{
			if (isPalindrome(s.substr(j, i - j + 1)))
				min = std::min(dp[j] + 1, min);
		}
		dp[i + 1] = std::min(min, dp[i] + 1);
	}
	return dp[s.size()];
}