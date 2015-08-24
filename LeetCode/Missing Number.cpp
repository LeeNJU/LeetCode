#include<vector>
//题目描述：给定一个大小为n的数组，只包含0,1,2，...,n的数，其中有一个数缺失，找到缺失的那个数
//解法描述：类似于first missing number那题
int missingNumber(std::vector<int>& nums) 
{
	for (int i = 0; i < nums.size(); ++i)
	{
		while (nums[i] < nums.size() && i != nums[i])//注意这里的结束条件，可能有一个数的大小超过数组的下标
		{
			std::swap(nums[i], nums[nums[i]]);
		}
	}

	for (int i = 0; i < nums.size(); ++i)//找到第一个不等的数
	{
		if (i != nums[i])
			return i;
	}
	return nums.size();
}