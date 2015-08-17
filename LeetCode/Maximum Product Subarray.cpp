#include<vector>
#include<algorithm>
//题目描述：给定一个数组，求出最大子数组的乘积
//解法描述：
int maxProduct(std::vector<int>& nums) 
{
	if (nums.empty())
		return 0;

	int result = nums[0];
	int max_local = nums[0];
	int min_local = nums[0];
	for (int i = 1; i < nums.size(); ++i)
	{
		int t = max_local;
		max_local = std::max(std::max(nums[i] * max_local, nums[i] * min_local), nums[i]);
		min_local = std::min(std::min(nums[i] * min_local, nums[i] * t), nums[i]);
		result = std::max(result, max_local);
	}
	return result;
}