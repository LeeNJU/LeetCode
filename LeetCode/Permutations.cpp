#include<vector>
#include<algorithm>
//题目描述：给定一组数组，不包含重复元素，返回这组数组所有的组合情况。
//解法描述：递归回溯,用一个visited数组保存元素是否被访问过

void dfs(std::vector<std::vector<int>>& result, std::vector<int> temp, std::vector<bool>& visited, const std::vector<int>& num)
{
	if (temp.size() == num.size())
	{
		result.push_back(temp);
		return;
	}

	for (int i = 0; i < num.size(); ++i)//依次扫描，每一层递归只负责一个元素，所以要pop_back
	{
		if (!visited[i])
		{
			visited[i] = true;
			temp.push_back(num[i]);
			dfs(result, temp, visited,num);
			temp.pop_back();//一层递归只负责一个元素
			visited[i] = false;
		}
	}
}

std::vector<std::vector<int> > permute(std::vector<int>& num)
{
	std::vector<std::vector<int> > result;
	std::vector<int> temp;
	std::vector<bool> visited(num.size(), false);
	dfs(result, temp, visited, num);
	return result;
}
