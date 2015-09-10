#include<vector>
#include<algorithm>
//题目描述：给一个正整数n，找到最小的平方数，使得这些平方数的和等于n，例如n = 13, 13 = 4 + 9,所以返回2
//解法描述：动态规划，对于dp[i],遍历i之前的元素，下标按照平方数进行递减，1,4,9
int numSquares(int n) 
{
	std::vector<int> dp(n, n);
	dp[0] = 1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 1; i - j * j >= -1; ++j)//注意之类的终止条件
			dp[i] = std::min(dp[i - j * j] + 1, dp[i]);
	}
	return dp[n - 1];
}