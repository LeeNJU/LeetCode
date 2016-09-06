#include<vector>
#include<algorithm>
//题目描述:给定一个数组，找到两个不重叠的子数组A和B，使得子数组A的和与子数组B的和的差最大，即|sum(A) - sum(B)|
//解法描述:尽量使A最大，B最小，但是不知道A在左边还是右边，如果A在左边，先找到最大的子数组和，然后从右向左扫描，
//        找到和最小的子数组，然后保存二者差的最大值，如果A在右边，那就要从左往右，先找到值最小的子数组，然后
//        从右往左扫描，得到和最大的子数组，同时保存二者之差的最大值
int maxDiffSubArrays(std::vector<int> nums) 
{
	if (nums.empty())
		return 0;

	std::vector<int> max_dp(nums.size(), INT_MIN); //保存从左往右的最大子数组和
	std::vector<int> min_dp(nums.size(), INT_MAX); //保存从左往右的最小子数组和
	max_dp[0] = nums[0];
	min_dp[0] = nums[0];

	int max_local = nums[0];
	int min_local = nums[0];
	for (int i = 1; i < nums.size(); ++i)  //计算最大和最小的子数组
	{
		max_local = std::max(max_local + nums[i], nums[i]);
		max_dp[i] = std::max(max_dp[i - 1], max_local);
		min_local = std::min(min_local + nums[i], nums[i]);
		min_dp[i] = std::min(min_dp[i - 1], min_local);
	}

	max_local = nums[nums.size() - 1];
	min_local = nums[nums.size() - 1];

	int result = std::max(max_dp[nums.size() - 2] - min_local, max_local - min_dp[nums.size() - 2]);
	for (int i = nums.size() - 2; i >= 1; --i) //从右往左扫描，得到最大和最小的子数组和，同时求最大差值
	{
		max_local = std::max(nums[i], max_local + nums[i]);
		min_local = std::min(nums[i], min_local + nums[i]);
		result = std::max(result, std::max(max_dp[i - 1] - min_local, max_local - min_dp[i - 1]));
	}
	return result;
}