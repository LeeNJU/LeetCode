#include<vector>

//题目描述：给定一个数组，判断是否存在元素A[i]和A[j]，使得i与j的差不超过k，A[i]与A[j]的差不超过t
//解法描述：

bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int k, int t)
{
	if (nums.size() < 2)
		return false;

	for (int i = 0; i + k < nums.size(); ++i)
	{
		for (int j = i; j <= i + k; ++j)
		{
			if (abs(nums[i] - nums[j]) <= t)
				return true;
		}
	}
	return false;
}