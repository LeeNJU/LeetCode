#include<vector>
#include<algorithm>
//题目描述:给定一个整数数组，每次选择一个数字，例如[3, 1, 5, 8]，第一次选择1，我们得到3*1*5=15，数组变成
//        [3,5,8],然后选择5，我们得到15 + 3*5*8=135，数组变成[3,8],然后选择3，我们得到135 + 1*3*8 = 159，
//        数组变成[8],然后选择8，我们得到159 + 1*8*1 = 167. 两边如果没有元素就用1代替，现在要求得到的最大的
//        数是多少
//解法描述:动态规划，dp[i][j]表示打爆区间[i,j]之间的所有气球所能得到的金币。那么dp[i][j] = max(dp[i][j],
//        dp[i - 1] * dp[k] * dp[j + 1] + dp[i][k - 1] + dp[k + 1][j]), i<=k<=j.
int maxCoins(std::vector<int>& nums) 
{
	int n = nums.size();
	nums.insert(nums.begin(), 1);
	nums.push_back(1);
	std::vector<std::vector<int>> dp(nums.size(), std::vector<int>(nums.size(), 0));

	for (int length = 1; length <= n; ++length)
	{
		for (int i = 1; i + length - 1 < n + 1; ++i)
		{
			int j = i + length - 1;
			for (int k = i; k <= j; ++k)
				dp[i][j] = std::max(dp[i][j], nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k - 1] + dp[k + 1][j]);
		}
	}

	return dp[1][n];
}