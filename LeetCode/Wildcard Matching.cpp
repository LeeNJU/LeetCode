#include<string>
#include<vector>
//题目描述:匹配字符串，？表示匹配任何单一的字符，*表示匹配任意序列的字符
//解法描述:动态规划，dp[i][j]表示从字符串s的0到i，能否匹配字符串p的0到j，如果p[j]不是*或者?,那么dp[i][j] = 
//        dp[i - 1][j - 1] && s[i] == p[j],如果p[j]等于?,那么dp[i][j] = dp[i - 1][j - 1],如果p[j] == *,
//        那么dp[i][j] = dp[i][j - 1] || dp[i - 1][j - 1] || dp[i - 2][j - 1] ||...dp[0][j - 1].
//        因为dp[i - 1][j] = dp[i - 1][j - 1] || dp[i - 2][j - 1] || dp[i - 3][j - 1]...所以可以简化为
//        dp[i][j] = dp[i][j - 1] || dp[i - 1][j]

bool isMatch(std::string s, std::string p) 
{
	if (s.empty() && p.empty())
		return true;

	int n = s.size();
	int m = p.size();
	std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(m + 1, false));

	dp[0][0] = true;
	for (int i = 1; i < n + 1; i++)//字符串p为0，初始化为false
		dp[i][0] = false;

	for (int i = 1; i < m + 1; i++)
		dp[0][i] = p[i - 1] == '*' && dp[0][i - 1];


	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
		{
			if (p[j - 1] == '*')
				dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
			else if (p[j - 1] == '?')
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1]);
		}
	}

	return dp[n][m];
}