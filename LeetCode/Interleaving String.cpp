#include<vector>
#include<string>

//题目描述：给定三个字符串s1,s2和s3，判断是否能够交叉组合s1和s2的字符得到s3，例如s1="aabcc",s2="dbbca",
//         s3="aadbbcbcac",结果为true
//解法描述：动态规划，dp[i][j] = (s1[i - 1] == s3[i + j - 1] && dp[i - 1][j]) || (s2[j - 1] == 
//         s3[i + j - 1] && dp[i][j - 1]);

bool isInterleave(std::string s1, std::string s2, std::string s3)
{
	if (s1.size() + s2.size() != s3.size())
		return false;

	int m = s1.size();
	int n = s2.size();
	std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, true));
	for (int i = 1; i < n + 1; ++i) //注意下标运算
		dp[0][i] = s2[i - 1] == s3[i - 1] && dp[0][i - 1];
	for (int i = 1; i < m + 1; ++i)
		dp[i][0] = s1[i - 1] == s3[i - 1] && dp[i - 1][0];

	for (int i = 1; i < m + 1; ++i)
	{
		for (int j = 1; j < n + 1; ++j)
		{
			dp[i][j] = (s1[i - 1] == s3[i + j - 1] && dp[i - 1][j])
				|| (s2[j - 1] == s3[i + j - 1] && dp[i][j - 1]);
		}
	}
	return dp[m][n];
}