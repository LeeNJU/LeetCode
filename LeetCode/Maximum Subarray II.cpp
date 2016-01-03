#include<vector>
#include<algorithm>
//题目描述:给定一个数组，找到两个不重叠的子数组，使得两个子数组的和最大
//解法描述:用两个数组left和right，left表示从0到i的最大子数组的和，right表示从n-1到i的最大子数组的和，先求出left，再反向
//        扫描求出right，扫描过程中求出两个子数组的最大和
int maxTwoSubArrays(std::vector<int> nums) 
{
	if (nums.size() < 2)
		return 0;

	std::vector<int> left(nums.size(), 0), right(nums.size(), 0);
	left[0] = nums[0];
	right[right.size() - 1] = nums[nums.size() - 1];

	int local = nums[0];
	for (int i = 1; i < nums.size(); ++i)//求出left
	{
		local = std::max(nums[i], nums[i] + local);
		left[i] = std::max(left[i - 1], local);
	}

	local = nums[nums.size() - 1];
	int sum = left[nums.size() - 2] + nums[nums.size() - 1];
	for (int i = nums.size() - 2; i > 0; --i)//求出right，并求出子数组的最大和
	{
		local = std::max(nums[i], nums[i] + local);
		right[i] = std::max(local, right[i + 1]);
		sum = std::max(sum, left[i - 1] + right[i]);
	}
	return sum;
}