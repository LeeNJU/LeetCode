#include<algorithm>
#include<vector>
//题目描述：给定一个未排序的数组，从中找出第一个missing的正数，例如[3,4,-1,1]，那么第一个missing的正数是2。
//解法描述：思路就是把元素放入合适的位置，例如1放到0位置，2放到1位置...遍历数组，把元素都放到合适的位置，再遍历数组找到第一个没有放到合适位置的元素

int firstMissingPositive(std::vector<int>& nums)
{
	for (int i = 0; i < nums.size(); ++i) //遍历数组，尽量把元素都放入合适的位置
	{
		while (nums[i] != i + 1) //遇到某一个元素为放到合适的位置
		{
			if (nums[i] <= 0 || nums[i] > nums.size() || nums[i] == nums[nums[i] - 1])//当该元素是负数，或大于数组长度，或与合适位置上的元素相等
				break;
			std::swap(nums[i], nums[nums[i] - 1]);//把该元素放到合适的位置
		}
	}

	for (int i = 0; i < nums.size(); ++i)//遍历数组，找到第一个没有放到合适位置的元素，即nums[i] != i + 1
	{
		if (nums[i] != (i + 1))
			return i + 1;
	}
	
	return nums.size() + 1;
}