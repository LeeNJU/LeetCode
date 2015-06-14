#include<vector>
#include<unordered_map>
//题目描述：给定一个数组，判断是否存在元素A[i]和A[j]，使得i与j的差不超过k，A[i]与A[j]的差不超过t
//解法描述：

bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int k, int t)
{
	std::unordered_map<int, int> m;
	int j = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (i - j > k)
		{

		}
		else
		{
			std::unordered_map<int, int>::iterator iter = m.lower_bound(nums[i] - t);
		}
		m[nums[i]] = i;
	}
}