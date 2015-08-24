#include <vector>
//题目描述：给定一个值n和k，n表示1到n个数字，求出1到n中大小为k的组合，例如n = 4 and k = 2, 解为[[2, 4],[3, 4],
//         [2, 3],[1, 2],[1, 3],[1, 4],]
//解法描述：递归
void dfs(std::vector<std::vector<int>>& result, std::vector<int> intermediate, int index, int k, int n)
{
	if (intermediate.size() == k)
	{
		result.push_back(intermediate);
		return;
	}

	for (int i = index; i <= n; ++i)
	{
		intermediate.push_back(i);
		dfs(result, intermediate, i + 1, k, n);
		intermediate.pop_back();
	}
}
std::vector<std::vector<int>> combine(int n, int k) {
	std::vector<std::vector<int>> result;
	std::vector<int> t;
	dfs(result, t, 1, k, n);
	return result;
}