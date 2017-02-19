#include<string>
#include<vector>
#include<algorithm>
//题目描述:给定一个字符串，找到最长的回文子序列的长度，例如"bbbab"，最长的回文子序列是"bbbb"
//解法描述:动态规划，dp[i][j]表示区间[i,j]之间最长的回文子序列，如果s[i] == s[j]，那么
//        dp[i][j] = dp[i + 1][j - 1] + 2.如果s[i] != s[j],那么dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])
//        其中dp[i][i]初始化为1

int longestPalindromeSubseq(std::string s) 
{
	int n = s.size();
	std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

	for (int length = 1; length <= n; ++length)
	{
		for (int i = 0; i + length - 1 < n; ++i)
		{
			int j = i + length - 1;
			if (i == j)
				dp[i][j] = 1;
			else if (s[i] == s[j])
				dp[i][j] = dp[i + 1][j - 1] + 2;
			else
				dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);
		}
	}
	return dp[0][n - 1];
}