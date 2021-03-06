#include<vector>
#include<algorithm>
#include<numeric>

//题目描述：给定一个数组和一个值，找到数组中所有和等于该值的元素的组合，每个元素只能使用一次
//解法描述：先排序，再递归，注意避免重复
void dfs(std::vector<std::vector<int>>& result, const std::vector<int>& num, std::vector<int> temp, int index, int target)
{
	if (target == 0)
	{
		result.push_back(temp);
		return;
	}
	if (target < 0)
		return;

	for (int i = index; i < num.size(); ++i)
	{
		if (i > index && num[i] == num[i - 1])//去掉重复元素，这里的重复包含两种情况，注意注意！！
			continue;
		temp.push_back(num[i]);
		dfs(result, num, temp, i + 1, target - num[i]);
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