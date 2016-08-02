#include<vector>
#include<algorithm>
//题目描述:给定一个正整数数组和一个值target，要求找到数字的组合，使得它们的和是target，每个数字可以重复使用
//解法描述:不能用深搜，会超时。动态规划dp[i] += dp[i - dp[i - nums[j]]],dp[i]表示和为i的组合数，如果i比当前
//        元素nums[j]大，组合数加上dp[i - nums[j]]

int combinationSum4(std::vector<int>& nums, int target) 
{
	std::vector<int> dp(target + 1, 0);
	dp[0] = 1;

	for (int i = 1; i < dp.size(); ++i) 
	{
		for (int j = 0; j < nums.size(); ++j) 
		{
			if (i - nums[j] >= 0) 
				dp[i] += dp[i - nums[j]];
		}
	}
	return dp[target];
}