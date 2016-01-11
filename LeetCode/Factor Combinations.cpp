#include<vector>
//题目描述:给定一个数n，找到它所有的因数的组合，例如12，返回[[2, 6],[2, 2, 3],[3, 4]],因数必须大于1小于n
//解法描述:递归求解
void dfs(std::vector<std::vector<int>>& result, std::vector<int> t, int product, int last, int num)
{                             //last是上一步用的因数，product是到上一步所有因数的乘积
	if (product > num || last > num)//乘积比num大或者上一步用的因数比num大
		return;

	if (product == num)
	{
		result.push_back(t);
		return;
	}

	for (int i = last; i < num; ++i)
	{
		if (num % (i * product) == 0)//必须能整除
		{
			t.push_back(i);
			dfs(result, t, product * i, i, num);
			t.pop_back();
		}
	}
}

std::vector<std::vector<int>> getFactors(int n)
{
	std::vector<std::vector<int>> result;
	std::vector<int> t;
	dfs(result, t, 1, 2, n);
	return result;
}