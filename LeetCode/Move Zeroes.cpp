#include<vector>
//题目描述：给定一个数组，其中包含若干个0，要求把所有的0放到数组末尾，并且保持非0元素的相对顺序不变
//解法描述：遍历数组，碰到一个0，就找到后序元素中的非0元素并与之交换
void moveZeroes(std::vector<int>& nums) 
{
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] == 0)
		{
			int index = i + 1;
			while (index < nums.size() && nums[index] == 0) //寻找后序元素中的非0元素
				++index;

			if (index == nums.size()) //后序元素中没有非0元素，说明已经完成操作
				return;
			else
				std::swap(nums[i], nums[index]);
		}
	}
}