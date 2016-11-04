#include<string>
#include<vector>
//题目描述:匹配字符串.和*，.表示任意单一字符，*表示前一个字符出现0次或多次,例如s="aab", p="c*a*b",返回true
//        因为b匹配一次，a匹配两次，c匹配0次
//解法描述:动态规划，dp[i][j]表示s的[0,i]是否匹配p的[0,j],如果p[j]是字符,那么dp[i][j] = dp[i - 1][j - 1]
//        && s[i] == p[j],如果p[j]是.,那么dp[i][j] = dp[i - 1][j - 1],如果p[j] == *,又分几种情况，如果
//        p[j - 1] == .或者p[j - 1] == s[i],那么dp[i][j] = dp[i][j - 2](匹配0次) || dp[i][j - 1](匹配
//        1次) || dp[i - 1][j](匹配多次)

bool isMatch(std::string s, std::string p)
{
	int m = s.length(), n = p.length();
	std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));
	dp[0][0] = true;

	//初始化第0列,除了[0][0]全为false，毋庸置疑，因为空串p只能匹配空串，其他都无能匹配
	for (int i = 1; i < m + 1; ++i)
		dp[i][0] = false;
	//初始化第0行，只有X*能匹配空串，如果有*，它的真值一定和p[0][j-2]的相同（略过它之前的符号）
	for (int j = 1; j < n + 1; ++j)
		dp[0][j] = j > 1 && '*' == p[j - 1] && dp[0][j - 2];

	for (int i = 1; i < m + 1; ++i)
	{
		for (int j = 1; j < n + 1; ++j)
		{
			if (p[j - 1] == '*')
				dp[i][j] = dp[i][j - 2] || ((s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
			else   //只有当前字符完全匹配，才有资格传递dp[i-1][j-1] 真值
				dp[i][j] = (p[j - 1] == '.' || s[i - 1] == p[j - 1]) && dp[i - 1][j - 1];
		}
	}
	return dp[m][n];
}