#include<vector>
#include<algorithm>

//题目描述：给定一个数组，包含重复元素，求出该数组的所有子集，子集中不能包含重复的子集， 例如[1,2,2],子集为[[2],[1],[1, 2, 2],[2, 2],[1, 2],[]]
//解法描述：递归，注意去掉重复元素

void dfs(std::vector<std::vector<int>>& result, std::vector<int> t, const std::vector<int>& nums, int index)
{
	result.push_back(t);

	for (int i = index; i < nums.size(); ++i)
	{
		if (i > index && nums[i] == nums[i - 1])//判断是否与前一个元素重复，如果重复，则直接进行下一次循环
			continue;

		t.push_back(nums[i]);
		dfs(result, t, nums, i + 1);
		t.pop_back();//主要要弹出一个元素
	}
}

std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums)
{
	sort(nums.begin(), nums.end());//注意要排序
	std::vector<std::vector<int>> result;
	std::vector<int> t;
	dfs(result, t, nums, 0);
	return result;
}