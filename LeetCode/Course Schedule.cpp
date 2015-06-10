#include<vector>

int findZeroIndegree(std::vector<int>& vec)//找到入度为0的节点
{
	for (int i = 0; i < vec.size(); ++i)
	{
		if (vec[i] == 0)
			return i;
	}
	return -1;
}
bool canFinish(int numCourses, std::vector<std::pair<int, int>>& prerequisites)
{
	if (prerequisites.empty())//如果没有选课条件，直接返回true
		return true;

	std::vector<int> indegree(numCourses, 0);//保存每个节点的入度
	for (int i = 0; i < prerequisites.size(); ++i)
		++indegree[prerequisites[i].first];

	for (int i = 0; i < numCourses; ++i)
	{
		int index = findZeroIndegree(indegree);
		if (index == -1)//不存在入度为0的点，说明有环，不能进行拓扑排序
			return false;

		indegree[index] = -1;//把这个点设为-1，表示删除
		for (int j = 0; j < prerequisites.size(); ++j)
		{
			if (prerequisites[j].second == index)
			{
				--indegree[prerequisites[j].first];
			}
		}
	}
	return true;
}