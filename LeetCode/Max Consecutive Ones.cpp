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