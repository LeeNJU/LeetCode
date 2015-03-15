#include<vector>
#include<algorithm>
#include<numeric>

//题目描述：给定一个数组和一个值，找到数组中所有和等于该值的元素
//解法描述：先排序，再递归，注意避免重复
void dfs(std::vector<std::vector<int>>& result, const std::vector<int>& num, std::vector<int> temp, int index, int target)
{
	int sum = std::accumulate(temp.begin(), temp.end(), 0);
	if (sum == target)
	{
		result.push_back(temp);
		return;
	}
	if (sum > target)
	{
		return;
	}

	int prev = -1;
	for (int i = index; i < num.size(); ++i)
	{
		if (prev == num[i])//去掉重复元素
			continue;
		prev = num[i];
		temp.push_back(num[i]);
		dfs(result, num, temp, i + 1, target);
		temp.pop_back();
	}
}

std::vector<std::vector<int> > combinationSum2(std::vector<int> &num, int target)
{
	sort(num.begin(), num.end());
	std::vector<std::vector<int>> result;
	std::vector<int> temp;
	dfs(result, num, temp, 0, target);
	return result;
}