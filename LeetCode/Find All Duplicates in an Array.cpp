#include<vector>
//题目描述:给定一个数组，里面的元素范围是1到n，n是数组大小，有的元素出现一次，有的元素出现两次，找到出现两次
//        的所有元素，例如[4,3,2,7,8,2,3,1]，出现两次的元素是2和3
//解法描述:类似于first missing positive number的解法

std::vector<int> findDuplicates(std::vector<int>& nums) 
{
	std::vector<int> result;
	for (int i = 0; i < nums.size(); ++i)
	{
		while (nums[i] != i + 1 && nums[nums[i] - 1] != nums[i])
			std::swap(nums[i], nums[nums[i] - 1]);
	}

	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] != i + 1)
			result.push_back(nums[i]);
	}

	return result;
}