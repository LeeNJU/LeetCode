#include<vector>
#include<unordered_map>
#include<unordered_set>
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
//解法描述：sliding window的思路，用hashtset保存i到j之间的元素，i到j的差不超过k
bool containsNearbyDuplicate(std::vector<int>& nums, int k)
{
	std::unordered_set<int> set;
	for (int i = 0, j = 0; j < nums.size(); ++j)
	{
		if (j - i > k)
			set.erase(nums[i++]);
		if (set.find(nums[j]) != set.end())
			return true;
		set.insert(nums[j]);
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