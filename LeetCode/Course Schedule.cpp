#include<vector>

//��Ŀ����������һЩѡ�������Ϳγ���������0��n-1��ʾ�γ̣�ѡ������Ϊ��0��1������ʾҪ���Ͽγ�1�����Ͽγ�0�����ܲ�������ѡ�����������ѡ��
//�ⷨ������ͼ������������ѣ���¼ÿ���γ̵���ȣ�����ѭ����ÿ���ҵ�һ�����Ϊ0�Ŀγ̣�����Ҳ������Ϊ0�Ŀγ̣���ʾ�л�������ѡ�Σ�Ȼ��Ѹõ��ȥ
//���ڽ������ȷֱ��ȥ1���Ѹõ�ɾ��

int findZeroIndegree(std::vector<int>& vec)//�ҵ����Ϊ0�Ľڵ�
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
	if (prerequisites.empty())//���û��ѡ��������ֱ�ӷ���true
		return true;

	std::vector<int> indegree(numCourses, 0);//����ÿ���ڵ�����
	for (int i = 0; i < prerequisites.size(); ++i)
		++indegree[prerequisites[i].first];

	for (int i = 0; i < numCourses; ++i)
	{
		int index = findZeroIndegree(indegree);
		if (index == -1)//���������Ϊ0�ĵ㣬˵���л������ܽ�����������
			return false;

		indegree[index] = -1;//���������Ϊ-1����ʾɾ��
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