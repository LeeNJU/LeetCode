#include<vector>
//题目描述:给定一个无向图，判断connected component的个数
//解法描述:union find
int root(std::vector<int>& vec, int i)
{
	int value = i;
	while (i != vec[i])//找到根节点
		i = vec[i];

	while (value != vec[value])//路径压缩，所有的点都指向根节点
	{
		int t = vec[value];
		vec[value] = i;
		value = t;
	}
	return i;
}

int countComponents(int n, std::vector<std::pair<int, int>>& edges)
{
	std::vector<int> vec(n, 0);
	for (int i = 0; i < n; ++i)
		vec[i] = i;

	int count = n;
	for (int i = 0; i < edges.size(); ++i)
	{
		int x = root(vec, edges[i].first);//找到根节点
		int y = root(vec, edges[i].second);
		if (x != y)//如果根节点不一样，进行union
		{
			--count;
			vec[x] = y;
		}
	}
	return count;
}