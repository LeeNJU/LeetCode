#include<vector>
#include<unordered_set>
//题目描述:给定一个数组，找到这个数组中所有的长度大于等于2的递增子序列，例如[4, 6, 7, 7]，返回
//        [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
//解法描述:递归求解，

void dfs(std::vector<std::vector<int>>& result, const std::vector<int>& nums, std::vector<int>& t, int index)
{
	if (t.size() >= 2)
		result.push_back(t);

	std::unordered_set<int> set;//由于没有排序，所以用set来去重
	for (int i = index; i < nums.size(); ++i)
	{
		if ((t.empty() || nums[i] >= t.back()) && set.find(nums[i]) == set.end())
		{         //必须是递增序列，且不能重复的加同一个元素
			set.insert(nums[i]);
			t.push_back(nums[i]);
			dfs(result, nums, t, i + 1);
			if (!t.empty())
				t.pop_back();
		}
	}
}


std::vector<std::vector<int>> findSubsequences(std::vector<int>& nums) 
{
	std::vector<std::vector<int>> result;
	std::vector<int> t;
	dfs(result, nums, t, 0);
	return result;
}