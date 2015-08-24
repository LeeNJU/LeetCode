#include<vector>

//题目描述：给定一个值k和n，从1到9中求出和为n的组合，组合的大小为k，数字不能重复，例如：k=3，n=7，输出为[[1,2,4]]
//解法描述：递归  0ms


void dfs(std::vector<std::vector<int>>& result, std::vector<int> t, int index, int k, int value)
{
	if (t.size() == k)
	{
		if (value == 0)
			result.push_back(t);
		return;
	}

	for (int i = index; i < 10; ++i)
	{
		if (i <= value)
		{
			t.push_back(i);
			dfs(result, t, i + 1, k, value - i);
			t.pop_back();//注意这里， 要弹出一个元素
		}
	}
}

std::vector<std::vector<int>> combinationSum3(int k, int n)
{
	std::vector<std::vector<int>> result;
	std::vector<int> t;
	dfs(result, t, 1, k, n);
	return result;
}