#include<vector>
#include<algorithm>
//题目描述:给定一个数组表示硬币的值，再给一个值，要求用最少数量的硬币凑成这个值
//解法描述:动态规划 dp[i] = min(dp[i], dp[i - coins[j]] + 1)
int coinChange(std::vector<int>& coins, int amount) 
{
	if (amount == 0)
		return 0;

	const int MAX = 1000; //用一个很大的值初始化
	std::vector<int> dp(amount + 1, MAX);
	for (int i = 0; i < coins.size(); ++i)
	{
		if (coins[i] < dp.size()) //初始化
			dp[coins[i]] = 1;
	}
	dp[0] = 0;

	for (int i = 1; i <= amount; ++i)
	{
		for (int j = 0; j < coins.size(); ++j)
		{
			if (i - coins[j] >= 0)
				dp[i] = std::min(dp[i], dp[i - coins[j]] + 1);
		}
	}

	return dp[amount] == MAX ? -1 : dp[amount];
}