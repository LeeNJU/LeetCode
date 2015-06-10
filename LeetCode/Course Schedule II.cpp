#include<vector>

//��Ŀ����������һ���γ�����n��һЩѡ�����������ط���ѡ��������һ��ѡ��˳��
//�ⷨ��������������

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
	std::vector<int> indegree(numCourses, 0);//����ÿ���ڵ�����
	for (int i = 0; i < prerequisites.size(); ++i)
		++indegree [prerequisites[i].first];

	for (int i = 0; i < numCourses; ++i)
	{
		int index = findZeroindegree(indegree);//�ҵ�һ�����Ϊ0�Ľڵ�
		if (index == -1) //���Ϊ0�Ľڵ㲻���ڣ�ֱ�ӷ��ؽ��
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