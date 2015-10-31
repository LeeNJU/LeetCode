#include<string>
#include<vector>
#include<algorithm>
//题目描述：给定一个字符串s，对它进行切割，使得每个部分都是palindrome，求最小的切割数
//解法描述：动态规划，dp[i]表示从0到i的字符串的最小切割数，dp[i] = min(dp[j] + 1, dp[i])如果j + 1到i是palindrome的话。
//         关键是判断j + 1到i是否是palindrome也需要动态规划，否则超时，matrix[j][i]表示从j到i是否是palindrome。
//         判断是否是palindrome:如果s[i] == s[j]并且i与j的差不超过1，或者matrix[j + 1][i - 1]为true

int minCut(std::string s)
{
	std::vector<int> dp(s.size() + 1, s.length());
	dp[0] = -1;//第一个元素初始化为-1
	std::vector<std::vector<bool>> matrix(s.length(), std::vector<bool>(s.length(), false));
	for (int i = 0; i < s.size(); ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			if ((s[i] == s[j] && i - j <= 1) || (s[i] == s[j] && matrix[j + 1][i - 1]))//j到i为回文，表示可以更新
			{
				matrix[j][i] = true;
				dp[i + 1] = std::min(dp[j] + 1, dp[i + 1]);
			}
		}
	}
	return dp[s.size()];
}