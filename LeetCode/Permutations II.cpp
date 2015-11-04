#include<vector>
#include<algorithm>

//题目描述：给定一个整数数组（包含重复元素），返回这些数字所有的组合
//解法描述：递归，先排序，用一个visited数组保存元素是否被保存过，遇到重复元素就跳过，

void dfs(std::vector<int>& num, std::vector<bool>& visited, std::vector<int>& solution, std::vector<std::vector<int>>& result)
{
	if (solution.size() == num.size())//找到一个解
	{
		result.push_back(solution);
		return;
	}
	for (int i = 0; i< num.size(); i++)//每次都是从0开始遍历
	{
		if (visited[i] == false)//元素没有被访问过才加入到solution中
		{
			if (i > 0 && num[i] == num[i - 1] && visited[i - 1] == false)//注意这里visited[i - 1]必须是false才能
				continue;                                                //continue
			visited[i] = true;
			solution.push_back(num[i]);
			dfs(num, visited, solution, result);
			solution.pop_back();
			visited[i] = false;
		}
	}
}

std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums)
{
	std::vector<std::vector<int> > result;
	std::vector<int> perm;
	std::vector<bool> visited(nums.size(), 0);
    std::sort(nums.begin(), nums.end());  //先进行排序，方便去重
	dfs(nums, visited, perm, result);
    return result;
}