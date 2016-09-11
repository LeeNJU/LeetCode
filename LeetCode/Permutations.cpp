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
			dfs(result, temp, visited, num);
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