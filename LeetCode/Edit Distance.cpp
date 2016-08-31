#include<vector>
#include<string>
#include<algorithm>

//题目描述:给定两个字符串word1和word2，允许三种操作，删除一个字符，替换一个字符，插入一个字符，求问把word1转换成word2最少需要多少步操作
//解法描述:动态规划，如果word1[i] == word2[j],那么dp[i][j] = dp[i - 1][j - 1], 如果word1[i] != word2[j],
//        dp[i][j]等于dp[i - 1][j],dp[i][j - 1],dp[i - 1][j - 1]的最小值再加1，这三个值分别代表三种操作

int minDistance(std::string word1, std::string word2)
{
	int m = word1.size();
	int n = word2.size();
	std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
	for (int i = 0; i < dp.size(); ++i)
		dp[i][0] = i;
	for (int i = 0; i < n + 1; ++i)
		dp[0][i] = i;

	for (int i = 1; i < m + 1; ++i)
	{
		for (int j = 1; j < n + 1; ++j)
		{
			if (word1[i - 1] == word2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = std::min(std::min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
		}
	}
	return dp[m][n];
}