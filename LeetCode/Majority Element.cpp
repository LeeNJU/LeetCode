#include<vector>

//题目描述：给定一个数组，其长度为n，找到其中出现次数大于n/2的元素，假设数组非空，并且一定存在这样的元素
//解法描述：用candidate表示最后的结果，count表示candidate出现的次数，遍历数组，如果count等于，那么candidate为nums[i]，count加1，如果count不等于0
//如果candidate等于nums[i]，那么count加1，如果candidate不等于nums[i]，就把count减1，如果candidate不是最后要找的元素，那么一定会碰到足够多的其他
//元素使得这个candidate的count为0，如果candidate就是最后要找的元素，那么candidate的count会减少，但不会等于0

int majorityElement(std::vector<int>& nums)
{
	int candidate = 0, count = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (count == 0)
		{
			candidate = nums[i];
			++count;
		}
		else
		{
			if (candidate == nums[i])
				++count;
			else
				--count;
		}
	}
	return candidate;
}