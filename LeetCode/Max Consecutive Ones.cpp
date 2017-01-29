#include<vector>
#include<algorithm>
//题目描述:给定一个数组，只包含1或者0，求最长的连续的1的个数，例如[1,1,0,1,1,1]，最长有3个连续的1
//解法描述:动态规划

int findMaxConsecutiveOnes(std::vector<int>& nums) 
{
	int result = 0;
	int count = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] == 1)
			++count;
		else
			count = 0;

		result = std::max(result, count);
	}
	return result;
}

//版本二，现在允许把数组中的一个0变成1，求最大长度的1，例如[1,0,1,1,0]，把第一个0变成1，最大长度就是4
//解法描述:双指针，[left, right]表示一个区间，这个区间里最多有k个0，也就是最多把k个0变成1，记录这个区间的最大
//        长度就是答案

int findMaxConsecutiveOnes(std::vector<int> nums) 
{
	int result = 0, zero = 0, k = 1; // flip at most k zero
	for (int left = 0, right = 0; right < nums.size(); ++right)
	{
		if (nums[right] == 0)
			++zero;
		while (zero > k)
		{
			if (nums[left--] == 0)
				--zero;
		}
		
		result = std::max(result, right - left + 1);
	}
	return result;
}