#include<vector>
#include<algorithm>
//题目描述:给定一个数组和一个target，找到三个数的组合，使得这三个数的和小于target，求这种组合的个数
//解法描述:先排序，类似于3sum的解法
int threeSumSmaller(std::vector<int>& nums, int target) 
{
	sort(nums.begin(), nums.end());
	int count = 0;
	for (int i = 0; i < nums.size() - 1; ++i) 
	{
		int left = i + 1, right = nums.size() - 1;
		while (left < right) 
		{
			if (nums[i] + nums[left] + nums[right] >= target) 
				--right;
			else 
			{
				++left;
				++count;
			}
		}
	}
	return count;
}