#include<vector>
#include<algorithm>
//题目描述:背包问题,给定一个数组和一个值w，从数组中选出几个元素，值得元素之和尽可能接近w
//解法描述:dp[i][j]表示从1到第i个元素要装满j的空间，分成两种情况，dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 
//        A[i - 1]] + A[i - 1]).如果不选择第i个元素，那么dp[i][j] = dp[i - 1][j],如果选择第i个元素,那么就是
//        dp[i - 1][j - A[i - 1]]，由于更新dp[i][j]只需要上一层的信息，可以优化空间，只需要一维数组

int backPack(int m, std::vector<int> A) 
{
	std::vector<int> dp(m + 1, 0);
	for (int i = 1; i < A.size() + 1; ++i)
	{
		for (int j = m; j >= 1; --j)
		{
			if (j - A[i - 1] < 0)//要保证j - A[i - 1] >= 0，即装得下
				dp[j] = dp[j];
			else
				dp[j] = std::max(dp[j], dp[j - A[i - 1]] + A[i - 1]);
		}
	}
	return dp[m];
}