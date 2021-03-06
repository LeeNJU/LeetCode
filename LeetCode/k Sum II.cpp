#include<vector>
#include<algorithm>
//题目描述:给定一个unique的数组和一个k和一个target，要求找到所有k个元素的组合，使得它们的和等于target
//解法描述:就是k sum，先排序，再用递归
void dfs(int index, int k, std::vector<int>& num, std::vector<std::vector<int>>&result, 
	std::vector<int> intermediate, int target)
{
	if (k == 0)
	{
		if (target == 0)
			result.push_back(intermediate);
		return;
	}
	for (int i = index; i < num.size(); ++i)
	{
		if (target < num[i])
			break;

		intermediate.push_back(num[i]);
		dfs(i + 1, k - 1, num, result, intermediate, target - num[i]);
		intermediate.pop_back();
	}
}

std::vector<std::vector<int> > kSumII(std::vector<int> A, int k, int target) 
{
	sort(A.begin(), A.end());
	std::vector<std::vector<int>> result;
	std::vector<int> intermediate;
	dfs(0, k, A, result, intermediate, target);
	return result;
}