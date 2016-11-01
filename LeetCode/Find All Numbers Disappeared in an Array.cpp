#include<vector>
//题目描述:给定一个数组，数组长度是n，每个元素都是属于[1,n]之间，有的元素出现两次，有的元素出现一次，从1到n
//        之间，找到哪些元素没有出现在这个数组中，例如[4,3,2,7,8,2,3,1]，返回[5,6]，因为5，6没有出现
//解法描述:扫描数组，把对应下标的元素设为负数，例如当前元素是4，把下标为3的元素设为它的负数，这样出现过的元素
//        对应的下标的值会是负数，然后扫描数组，如果某个值是正数，说明这个下标不存在这个数组中。

std::vector<int> findDisappearedNumbers(std::vector<int>& nums)
{
	for (int val : nums)
	{
		int index = abs(val) - 1;
		if (nums[index] > 0)//如果这个元素已经是负数，就跳过，因为有的元素出现2次
			nums[index] = -nums[index];
	}

	std::vector<int> result;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] > 0)//找到是正数的下标
			result.push_back(i + 1);
	}
	return result;
}