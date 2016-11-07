#include<vector>
#include<unordered_map>
//��Ŀ����:����һ��㣬�ҵ�����������tuple(i, j, k)��ʹ��i��j�ľ������i��k�ľ��룬����[[0,0],[1,0],[2,0]]��
//        ����2�� ��Ϊ��2������������tuple��[[1,0],[0,0],[2,0]]��[[1,0],[2,0],[0,0]]��˳��ͬҲ��
//�ⷨ����:hashtable������ÿ���㣬�Ծ���Ϊkey���ҵ�������ȵĵ�ĸ���

int numberOfBoomerangs(std::vector<std::pair<int, int>>& points) 
{
	int count = 0;
	std::unordered_map<int, int> map;

	for (int i = 0; i < points.size(); ++i)
	{
		for (int j = 0; j < points.size(); ++j)
		{
			if (i != j)
			{
				int distance = (points[i].first - points[j].first) * (points[i].first - points[j].first)
					+ (points[i].second - points[j].second) * (points[i].second - points[j].second);
				++map[distance];
			}
		}

		auto iter = map.begin();
		while (iter != map.end())
		{
			count += iter->second * (iter->second - 1);
			++iter;
		}

		map.clear();
	}
	return count;
}