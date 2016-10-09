#include<vector>
#include<algorithm>
//题目描述:给定一个数组和一个m值，表示把数组划分成m个子数组，求子数组中最大的和。例如[7,2,5,10,8]，m = 2，
//        分成两个子数组，[7,2,5] and [10,8]，最大的和是18
//解法描述:如果m = 1，整个数组是一个子数组，和是整个数组的和，如果m = nums.size(),那么每一个数都是一个子数组，
//        最大的和就是数组的最大值，那么最终答案一定在这两个数之间，用二分查找，看数组中和最大且小于等于mid的
//        子数组的个数，如果子数组个数小于m，说明mid值偏大，right = middle，如果子数组个数等于mid，right =
//        mid,如果子数组个数小于mid，说明mid值太小，必须增大mid，left = mid + 1

bool can_split(std::vector<int>& nums, int m, int sum) 
{
	int count = 1, cur_sum = 0;
	for (int i = 0; i < nums.size(); ++i) 
	{
		cur_sum += nums[i];
		if (cur_sum > sum) 
		{
			cur_sum = nums[i];
			++count;
			if (count > m) 
				return false;
		}
	}
	return true;
}

int splitArray(std::vector<int>& nums, int m)
{
	int left = 0, right = 0;
	for (int i = 0; i < nums.size(); ++i) 
	{
		left = std::max(left, nums[i]);
		right += nums[i];
	}

	while (left < right) 
	{
		long long mid = left + (right - left) / 2;
		if (can_split(nums, m, mid)) 
			right = mid;
		else 
			left = mid + 1;
	}
	return left;
}