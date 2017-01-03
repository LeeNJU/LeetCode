#include<vector>
//题目描述:给定一些选课条件和课程总数，用0到n-1表示课程，选课条件为（0，1），表示要先上课程1才能上课程0，
//         求能不能满足选课条件下完成选课
//解法描述:图的拓扑排序而已，记录每个课程的入度，进行循环，每次找到一个入度为0的课程，如果找不到入度为0的课程，
//         表示有环，则不能选课，然后把该点出去的邻近点的入度分别减去1，把该点删除

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

//题目描述：给定一个课程总数n和一些选课条件，返回符合选课条件的一种选课顺序
//解法描述：拓扑排序

std::vector<int> findOrder(int numCourses, std::vector<std::pair<int, int>>& prerequisites)
{
	std::vector<int> result;
	std::vector<int> indegree(numCourses, 0);//保存每个节点的入度
	for (int i = 0; i < prerequisites.size(); ++i)
		++indegree[prerequisites[i].first];

	for (int i = 0; i < numCourses; ++i)
	{
		int index = findZeroIndegree(indegree);//找到一个入度为0的节点
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