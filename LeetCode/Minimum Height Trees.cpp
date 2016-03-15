#include<vector>
#include<queue>
//题目描述:给定一个值n和一些边，以每一个节点都可以形成一棵树，要求找到所有的点，使得以这些点为根节点的树的高度最小。
//解法描述:类似于拓扑排序，先删除叶子节点，入度减1，继续删除叶子节点，直到节点的个数小于等于2

std::vector<int> findMinHeightTrees(int n, std::vector<std::pair<int, int>>& edges)
{
	if (n == 1)
		return std::vector<int>{0};

	std::vector<std::vector<int>> graph(n, std::vector<int>());
	std::vector<int> indegree(n, 0);
	for (int i = 0; i < edges.size(); ++i)//生成一个图，用二维数组表示，统计入度
	{
		graph[edges[i].first].push_back(edges[i].second);
		graph[edges[i].second].push_back(edges[i].first);
		++indegree[edges[i].first];
		++indegree[edges[i].second];
	}

	std::queue<int> q;
	for (int i = 0; i < indegree.size(); ++i)
	{
		if (indegree[i] == 1)
			q.push(i);
	}

	while (n > 2)
	{
		int size = q.size();//注意这里，只能一层一层的删除节点，不能用while循环，while循环会把所有节点加到队列中
		for (int i = 0; i < size; ++i)//拿出一个点，把相邻的点的入度减1
		{
			int node = q.front();
			q.pop();
			--n;  //删除一个点
			for (int j = 0; j < graph[node].size(); ++j)
			{
				--indegree[graph[node][j]];
				if (indegree[graph[node][j]] == 1)
					q.push(graph[node][j]);
			}
		}
	}

	std::vector<int> result;
	while (!q.empty())//点已在队列中
	{
		result.push_back(q.front());
		q.pop();
	}
	return result;
}