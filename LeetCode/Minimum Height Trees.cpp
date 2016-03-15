#include<vector>
#include<queue>
//��Ŀ����:����һ��ֵn��һЩ�ߣ���ÿһ���ڵ㶼�����γ�һ������Ҫ���ҵ����еĵ㣬ʹ������Щ��Ϊ���ڵ�����ĸ߶���С��
//�ⷨ����:����������������ɾ��Ҷ�ӽڵ㣬��ȼ�1������ɾ��Ҷ�ӽڵ㣬ֱ���ڵ�ĸ���С�ڵ���2

std::vector<int> findMinHeightTrees(int n, std::vector<std::pair<int, int>>& edges)
{
	if (n == 1)
		return std::vector<int>{0};

	std::vector<std::vector<int>> graph(n, std::vector<int>());
	std::vector<int> indegree(n, 0);
	for (int i = 0; i < edges.size(); ++i)//����һ��ͼ���ö�ά�����ʾ��ͳ�����
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
		int size = q.size();//ע�����ֻ��һ��һ���ɾ���ڵ㣬������whileѭ����whileѭ��������нڵ�ӵ�������
		for (int i = 0; i < size; ++i)//�ó�һ���㣬�����ڵĵ����ȼ�1
		{
			int node = q.front();
			q.pop();
			--n;  //ɾ��һ����
			for (int j = 0; j < graph[node].size(); ++j)
			{
				--indegree[graph[node][j]];
				if (indegree[graph[node][j]] == 1)
					q.push(graph[node][j]);
			}
		}
	}

	std::vector<int> result;
	while (!q.empty())//�����ڶ�����
	{
		result.push_back(q.front());
		q.pop();
	}
	return result;
}