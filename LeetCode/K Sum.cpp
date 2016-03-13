#include<vector>
//题目描述:给定一个数组，要求找出k个数，使得它们的和等于某个给定的值，返回这种解的个数
//解法描述:动态规划，dp[i][j][t]表示从0到j，i个数的和为t的解的个数。dp[i][j][t] = dp[i][j - 1][t] + 
//        dp[i - 1][j - 1][t - A[j - 1]]其中要判断t - A[j]是否大于等于0

int kSum(std::vector<int> A, int k, int target) 
{
	std::vector<std::vector<std::vector<int>>> dp(k + 1, std::vector<std::vector<int>>(A.size() + 1, std::vector<int>(target + 1, 0)));
	for (int t = 0; t < target + 1; ++t)
	{
		for (int i = 0; i < k; ++i)
		{
			for (int j = 0; j < A.size(); ++j)
			{
				if (t == 0 && i == 0)
					dp[i][j][t] = 1;
				else
				{
					dp[i + 1][j + 1][t] = dp[i + 1][j][t];
					if (t - A[j] >= 0)
						dp[i + 1][j + 1][t] += dp[i][j][t - A[j]];
				}
			}
		}
	}
	return dp[k][A.size()][target];

}