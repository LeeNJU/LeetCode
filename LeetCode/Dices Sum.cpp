#include<vector>
//题目描述:给定n个骰子，投掷这n个骰子，会得到不同的值，以及值的和S。求得到每一种S的可能性，例如n = 1，每次投掷
//        只有一种结果，1，2，3，4，5，6，可能性都是1/6，返回(1, 0.17), (2, 0.17), (3, 0.17)
//解法描述:动态规划，dp[i][j]表示i个骰子的和是j的次数，那么dp[i][j] += dp[i - 1][j - k], 其中1<= k <=6,然后
//        统计所有的次数，求解概率

std::vector<std::pair<int, double>> dicesSum(int n) 
{
	std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(6 * n + 1, 0));
	dp[0][0] = 1; //注意这里初始化为1

	for (int i = 1; i < n + 1; ++i)
	{
		for (int j = 1; j < 6 * n + 1; ++j)
		{
			for (int k = 1; k <= 6; ++k)
			{
				if (j >= k)
					dp[i][j] += dp[i - 1][j - k];
			}
		}
	}

	long long sum = 0; //统计次数
	for (int i = 0; i < 6 * n + 1; ++i)
	{
		if (dp[n][i] > 0)
			sum += dp[n][i];
	}

	std::vector<std::pair<int, double>> result;
	for (int i = 1; i < 6 * n + 1; ++i)
	{
		if (dp[n][i] > 0)
			result.push_back(std::pair<int, double>(i, dp[n][i] / (double) sum));
	}

	return result;
}