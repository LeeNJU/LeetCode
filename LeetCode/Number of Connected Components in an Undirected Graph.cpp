#include<vector>
//��Ŀ����:����һ������ͼ���ж�connected component�ĸ���
//�ⷨ����:union find
int root(std::vector<int>& vec, int i)
{
	int value = i;
	while (i != vec[i])//�ҵ����ڵ�
		i = vec[i];

	while (value != vec[value])//·��ѹ�������еĵ㶼ָ����ڵ�
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
		int x = root(vec, edges[i].first);//�ҵ����ڵ�
		int y = root(vec, edges[i].second);
		if (x != y)//������ڵ㲻һ��������union
		{
			--count;
			vec[x] = y;
		}
	}
	return count;
}