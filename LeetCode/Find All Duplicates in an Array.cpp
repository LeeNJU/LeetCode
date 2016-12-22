#include<vector>
//题目描述:给定一个数组，里面的元素范围是1到n，n是数组大小，有的元素出现一次，有的元素出现两次，找到出现两次
//        的所有元素，例如[4,3,2,7,8,2,3,1]，出现两次的元素是2和3
//解法描述:扫描数组，把当前元素放到合适的位置，如果当前元素为val，应该把val放到下标为val - 1的位置，把val - 1
//        的元素设为负数，表示该元素已经出现过了

std::vector<int> findDuplicates(std::vector<int>& nums) 
{
	std::vector<int> result;
	for (int i = 0; i < nums.size(); ++i)
	{
		int index = abs(nums[i]) - 1;
		if (nums[index] < 0)//位置为负数，表示该元素已经出现过了，是重复元素
			result.push_back(index + 1);
		else//位置为正数，表示该元素第一次出现，将其设为负数
			nums[index] = -nums[index];
	}
	return result;
}