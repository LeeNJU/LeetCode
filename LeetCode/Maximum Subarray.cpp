#include<vector>
#include<algorithm>
//题目描述：给定一个数组，从中找到连续的子数组，使得子数组的和最大
//解法描述：动态规划，维护两个变量，局部最优解保存包含当前元素的最优解，全局最优解表示从初始位置到当前元素的最优解。

int maxSubArray(std::vector<int>& nums) 
{
	if (nums.empty())
		return 0;

	int local_max = nums[0], global_max = nums[0];
	for (int i = 1; i < nums.size(); ++i)
	{
		local_max = std::max(local_max + nums[i], nums[i]);//局部最优必须包含当前元素，所有在这两种情况中取最大
		global_max = std::max(local_max, global_max); //全局最优从上一个元素的全局最优和当前的局部最优取最大
	}
	return global_max;
}

//题目描述:给定一个数组，找到两个不重叠的子数组，使得两个子数组的和最大
//解法描述:用两个数组left和right，left表示从0到i的最大子数组的和，right表示从n-1到i的最大子数组的和，先求出
//        left，再反向扫描求出right，扫描过程中求出两个子数组的最大和
int maxTwoSubArrays(std::vector<int> nums)
{
	if (nums.size() < 2)
		return 0;

	std::vector<int> left(nums.size(), 0);
	left[0] = nums[0];

	int local = nums[0];
	for (int i = 1; i < nums.size(); ++i)
	{
		local = std::max(nums[i], nums[i] + local);
		left[i] = std::max(left[i - 1], local);
	}

	local = nums[nums.size() - 1];
	int sum = left[nums.size() - 2] + nums[nums.size() - 1];
	int right_max = nums.back();
	for (int i = nums.size() - 2; i > 0; --i)
	{
		local = std::max(nums[i], nums[i] + local);
		right_max = std::max(local, right_max);
		sum = std::max(sum, left[i - 1] + right_max);
	}
	return sum;
}