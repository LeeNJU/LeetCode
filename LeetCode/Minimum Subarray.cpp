#include<vector>
#include<algorithm>
//题目描述：给定一个数组，从中找到连续的子数组，使得子数组的和最小
//解法描述：动态规划，维护两个变量，局部最优解保存包含当前元素的最优解，全局最优解表示从初始位置到当前元素的最优解。

int minSubArray(std::vector<int> nums) 
{
	int global_sum = nums[0];
	int local_sum = nums[0];
	for (int i = 1; i < nums.size(); ++i)
	{
		local_sum = std::min(local_sum + nums[i], nums[i]);//局部最优必须包含当前元素，所有在这两种情况中取最小
		global_sum = std::min(global_sum, local_sum);
	}
	return global_sum;
}