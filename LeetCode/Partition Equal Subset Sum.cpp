#include<vector>
#include<numeric>
//题目描述:给定一个非负数组，判断是否能够把数组分成两部分，使得这两部分的和相等，例如给定数组[1, 5, 11, 5]，
//        该数组可以被分成[1,5,5]和[11]两部分，返回true，如果不能分成相等的两部分，返回false
//解法描述:先求出数组的和sum，问题转换成能够从数组中找到元素使得元素的和等于sum的一半，成了背包问题。

bool canPartition(std::vector<int>& nums) 
{
	int sum = std::accumulate(nums.begin(), nums.end(), 0);
	if (sum % 2 == 1) //数组的和必须是偶数
		return false;
	
	int target = sum / 2;
	std::vector<bool> dp(target + 1, false);
	dp[0] = true;
	for (int i = 0; i < nums.size(); ++i)//注意这里，外循环必须是nums，因为每个元素只能用一次 
	{
		for (int j = target; j >= nums[i]; --j) 
			dp[j] = dp[j] || dp[j - nums[i]];
	}
	return dp.back();
}