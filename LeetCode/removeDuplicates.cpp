#include<vector>
//题目描述：给一个已序数组，删除其中的重复元素，使得每个元素只出现一次，并返回数组长度
//解法：index表示新下标，i=1开始遍历数组，如果A[index]不等于A[i]
int removeDuplicates(std::vector<int>& nums)
{
	if (nums.empty())
		return 0;

	int index = 0;
	for (int i = 1; i < nums.size(); ++i)
	{
		if (nums[i] != nums[i - 1])
			nums[++index] = nums[i];
	}

	return index + 1;
}

//版本二：给定一个已序数组，删除其中的重复元素，使得每个元素最多出现两次，并返回长度
//解法：与上题类似，加一个变量记录次数
int removeDuplicates2(std::vector<int>& nums) 
{
	if (nums.size() <= 2)
		return nums.size();

	int count = 1;
	int index = 0;
	for (int i = 1; i < nums.size(); ++i)
	{
		if (nums[i] == nums[i - 1])
		{
			++count;
			if (count <= 2)
				nums[++index] = nums[i];
		}
		else
		{
			nums[++index] = nums[i];
			count = 1;
		}
	}
	return index + 1;
}