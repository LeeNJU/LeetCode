#include<vector>
#include<unordered_map>

//题目描述：给定一个数组和一个值k，判断是否存在重复的元素，并且重复元素的下标之差不能超过k
//解法描述：用hashtable保存相同值的下标集合，遍历该集合，比较下标之差
bool containsNearbyDuplicate(std::vector<int>& nums, int k)
{
	std::unordered_map<int, std::vector<int>> m;
	for (int i = 0; i < nums.size(); ++i)
	{
		m[nums[i]].push_back(i);//保存相同元素的下标
	}

	for (int i = 0; i < nums.size(); ++i)
	{
		if (m[nums[i]].size() >= 2)//下标集合大于2
		{
			for (int j = 0; j < m[nums[i]].size() - 1; ++j)//遍历下标集合，分别比较相邻下标的差
			{
				if (m[nums[i]][j + 1] - m[nums[i]][j] <= k)
					return true;
			}
		}
	}

	return false;
}