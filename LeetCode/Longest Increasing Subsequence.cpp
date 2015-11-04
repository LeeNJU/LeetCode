#include<vector>
#include<algorithm>
//题目描述:给定一个数组，找到最长的递增子序列，子序列不一定要连续
//解法描述:动态规划，dp[i] = max(dp[i], dp[j] + 1),其中nums[j]要比nums[i]小，表示找到一个可能的递增子序列

int lengthOfLIS(std::vector<int>& nums) 
{
	if (nums.empty())
		return 0;

	std::vector<int> dp(nums.size(), 1);
	int max_length = 1;
	for (int i = 1; i < nums.size(); ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (nums[j] < nums[i])
				dp[i] = std::max(dp[i], dp[j] + 1);
		}
		max_length = std::max(max_length, dp[i]);
	}
	return max_length;
}