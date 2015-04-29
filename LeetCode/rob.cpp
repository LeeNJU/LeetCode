#include<vector>
#include<algorithm>
//题目描述：给定一个整数数组代表每个家庭的钱，现在去抢劫，但是不能抢劫相连的两家，求最大能抢劫多少钱
//解法描述：动态规划  dp[i] = max(dp[i - 1], dp[i - 2] + n[i])

int rob(std::vector<int>& nums)
{
	if (nums.size() <= 1) 
		return nums.empty() ? 0 : nums[0];
	
	std::vector<int> dp = { nums[0], std::max(nums[0], nums[1]) };
	for (int i = 2; i < nums.size(); ++i) 
	{
		dp.push_back(std::max(nums[i] + dp[i - 2], dp[i - 1]));
	}
	return dp.back();
}