#include<vector>
#include<unordered_map>
//题目描述:给定一组点，找到符合条件的tuple(i, j, k)，使得i和j的距离等于i和k的距离，例如[[0,0],[1,0],[2,0]]，
//        返回2， 因为有2个符合条件的tuple，[[1,0],[0,0],[2,0]]和[[1,0],[2,0],[0,0]]，顺序不同也算
//解法描述:hashtable，对于每个点，以距离为key，找到距离相等的点的个数

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