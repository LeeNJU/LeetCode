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