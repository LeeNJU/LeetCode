#include<vector>
#include<unordered_map>
#include<map>

//题目描述:给定一个数组，判断其中是否包含重复元素
//解法描述：用hashtable
bool containsDuplicate(std::vector<int>& nums) 
{
	std::unordered_map<int, int> m;
	for (int i = 0; i < nums.size(); ++i)
	{
		++m[nums[i]];
		if (m[nums[i]] > 1)
			return true;
	}
	return false;
}

//题目描述：给定一个数组和一个值k，判断是否存在重复的元素，并且重复元素的下标之差不能超过k
//解法描述：用hashtable保存相同值的下标集合，遍历该集合，比较下标之差
bool containsNearbyDuplicate(std::vector<int>& nums, int k)
{
	std::unordered_map<int, std::vector<int>> m;
	for (int i = 0; i < nums.size(); ++i)
		m[nums[i]].push_back(i);//保存相同元素的下标

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

//题目描述：给定一个数组，判断是否存在元素A[i]和A[j]，使得i与j的差不超过k，A[i]与A[j]的差不超过t
//解法描述：用一个map保存i到j之间的元素，i和j的差不超过k，利用map的lower_bound方法找到nums[i] - t的上界，就
//         是大于等于nums[i] - t的元素的迭代器，小于这个迭代器的元素与nums[i] - t的差一定大于t，大于这个迭代
//         器的元素与nums[i] - t的差不一定大于t，必须判断。

bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int k, int t)
{
	std::map<int, int> m;
	int j = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (i - j > k)//下标之差大于k，要删除之前的元素
		{
			m.erase(nums[j]);
			++j;
		}
		std::map<int, int>::iterator iter = m.lower_bound(nums[i] - t);
		if (iter != m.end() && abs(iter->first - nums[i]) <= t)
			return true;
		m[nums[i]] = i;
	}
	return false;
}