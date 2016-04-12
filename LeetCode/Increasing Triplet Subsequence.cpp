#include<vector>
#include<algorithm>

bool increasingTriplet(std::vector<int>& nums) 
{
	std::vector<int> dp(nums.size(), 1);
	for(int i = 1; i < nums.size(); ++i)
	{
		for(int j = 0; j < i; ++j)
		{
			if(nums[i] > nums[j])
				dp[i] = std::max(dp[i], dp[j] + 1);
		}
		if(dp[i] >= 3)
			return true;
	}
	return false;
}