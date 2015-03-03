#include<vector>
#include<algorithm>
//题目描述：给定一个整数集合，{1,2,3}，输出所有的子集，其中每个子集的元素以递增顺序，结果：{{3},{2},{1},{1,3},{2,3},{1,2},{1,2,3},{}}，别忘了空集
//解法：递归

std::vector<std::vector<int> > subsets(std::vector<int> &S)
{
	sort(S.begin(), S.end());
	std::vector<std::vector<int>> result;
	std::vector<int> path;
	subset(S, result, path, 0);
	return result;
}

void subset(const std::vector<int>& S, std::vector<std::vector<int>>& result, std::vector<int>& path, int depth)
{
	if (depth == result.size())
	{

	}
}
