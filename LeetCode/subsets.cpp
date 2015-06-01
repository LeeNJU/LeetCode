#include<vector>
#include<algorithm>
//题目描述：给定一个整数集合，{1,2,3}，输出所有的子集，其中每个子集的元素以递增顺序，结果：{{3},{2},{1},{1,3},{2,3},{1,2},{1,2,3},{}}，别忘了空集
//解法：递归，每一层递归加入一个元素到t中，并把t加入到result中

void dfs(std::vector<std::vector<int>>& result, std::vector<int> t, const std::vector<int>& nums, int index)//index表示开始的下标
{
	result.push_back(t);

	for (int i = index; i < nums.size(); ++i)
	{
		t.push_back(nums[i]);
		dfs(result, t, nums, i + 1);
		t.pop_back();
	}
}


std::vector<std::vector<int> > subsets(std::vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	std::vector<std::vector<int>> result;
	std::vector<int> path;
	dfs(result, path, nums, 0);
	return result;
}

