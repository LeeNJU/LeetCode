#include<vector>

//题目描述：给定一个课程总数n和一些选课条件，返回符合选课条件的一种选课顺序
//解法描述：拓扑排序

int findZeroindegree(const std::vector<int>& indegree)
{
	for (int i = 0; i < indegree.size(); ++i)
	{
		if (indegree[i] == 0)
			return i;
	}
	return -1;
}

std::vector<int> findOrder(int numCourses, std::vector<std::pair<int, int>>& prerequisites)
{
	std::vector<int> result;
	std::vector<int> indegree(numCourses, 0);//保存每个节点的入度
	for (int i = 0; i < prerequisites.size(); ++i)
		++indegree [prerequisites[i].first];

	for (int i = 0; i < numCourses; ++i)
	{
		int index = findZeroindegree(indegree);//找到一个入度为0的节点
		if (index == -1) //入度为0的节点不存在，直接返回结果
			return std::vector<int>();

		result.push_back(index);
		for (int j = 0; j < prerequisites.size(); ++j)
		{
			if (prerequisites[j].second == index)
				--indegree[prerequisites[j].first];
		}
		indegree[index] = -1;
	}
	return result;
}