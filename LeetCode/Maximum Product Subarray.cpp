#include<vector>
#include<algorithm>
//题目描述：给定一个数组，求出最大子数组的乘积
//解法描述：最大值可能由负数乘以负数得到,维护两个局部变量，max_local和min_local表示局部的最大值和最小值
int maxProduct(std::vector<int>& nums) 
{
	if (nums.empty())
		return 0;

	int result = nums[0];
	int max_local = nums[0];
	int min_local = nums[0];
	for (int i = 1; i < nums.size(); ++i)
	{
		int t = max_local;//注意这里要保存max_local的值，下面一行代码会改变max_local的值
		max_local = std::max(std::max(nums[i] * max_local, nums[i] * min_local), nums[i]);
		min_local = std::min(std::min(nums[i] * min_local, nums[i] * t), nums[i]);
		result = std::max(result, max_local);
	}
	return result;
}