#include<vector>
//题目描述:给定一个数组，求出上一个排列组合，例如给定[1,2,1],那么上一个排列是[1,1,2]
//解法描述:从右往左扫描，应该是递减序列，找到第一个比右边元素大的下标，然后从右往左扫描，找到第一个比这个元素
//        小的下标，然后交换这两个元素，最后对下标left + 1以及之后的元素进行反转

std::vector<int> previousPermuation(std::vector<int>& nums) 
{
	int left = nums.size() - 1;
	for (int i = nums.size() - 1; i > 0; --i)
	{
		if (nums[i] < nums[i - 1])
		{
			left = i - 1;
			break;
		}
	}


	if (left == nums.size() - 1)//全部是递减序列，直接反转
	{
		reverse(nums.begin(), nums.end());
		return nums;
	}

	int right = 0;
	for (int i = nums.size() - 1; i > left; --i)
	{
		if (nums[i] < nums[left])
		{
			right = i;
			break;
		}
	}

	std::swap(nums[left], nums[right]);
	std::reverse(nums.begin() + left + 1, nums.end());
	return nums;
}