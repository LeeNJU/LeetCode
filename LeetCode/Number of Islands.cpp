#include<unordered_map>
//��Ŀ����������һ����ά����ֵΪ1����Ϊ0.�ҵ�����С���ĸ�����С���Ķ���Ϊ��0������1��С�����԰������1
//�ⷨ��������union find,�Ѷ�ά����ӳ�䵽һά����

int root(std::vector<int>& vec, int num)
{
	while (num != vec[num])
		num = vec[num];
	return num;
}

int numIslands(std::vector<std::vector<char>>& grid)
{
	std::vector<int> vec(grid.size() * grid[0].size(), 0);
	for (int i = 0; i < vec.size(); ++i)
		vec[i] = i;

	int count = 0;
	for (int i = 0; i < grid.size(); ++i)
	{
		for (int j = 0; j < grid[0].size(); ++j)
		{
			if (grid[i][j] == '1')
			{
				++count;
				int position = i * grid[0].size() + j;
				int root1 = root(vec, position);

				std::vector<int> dx = { 0, 0, -1, 1 };
				std::vector<int> dy = { 1, -1, 0, 0 };

				for (int k = 0; k < dx.size(); ++k)//�鿴�������ҵĵ�
				{
					if (i + dx[k] < 0 || i + dx[k] >= grid.size() ||
						j + dy[k] < 0 || j + dy[k] >= grid[0].size() ||
						grid[i + dx[k]][j + dy[k]] == '0')
						continue;

					int new_position = (i + dx[k]) * grid[0].size() + j + dy[k];
					int root2 = root(vec, new_position);
					if (root2 != root1)
					{
						--count;
						vec[root1] = root2;
					}
				}
			}
		}
	}
	return count;
}



//version2:
//��Ŀ����:����һ����ά���飬ȫ��0����ʾˮ���ٸ�һ���������ʾ��(x,y)��ֵ��Ϊ1�����island������Ҫ���ÿһ��
//        ����֮���ж��ٸ�island
//�ⷨ����:�ò��鼯��·��ѹ�����ؼ��ǰѶ�ά����ӳ���һά

int root(std::unordered_map<int, int>& map, int value)
{
	if (map.find(value) == map.end())
	{
		map[value] = value;
		return value;
	}

	int result = value, t;
	while (result != map[result])//�ҵ����ڵ�
	{
		result = map[result];
	}

	while (value != map[value]) //·��ѹ���������еĵ㶼ָ����ڵ�
	{
		t = map[value];
		map[value] = result;
		value = t;
	}
	return result;
}

std::vector<int> numIslands2(int m, int n, std::vector<std::pair<int, int>>& positions)
{
	std::vector<int> result;
	std::unordered_map<int, int> map;
	int count = 0;
	for (int i = 0; i < positions.size(); ++i)
	{
		int x = positions[i].first;
		int y = positions[i].second;
		int pos = x * m + y; //�Ѷ�ά����ӳ�䵽һά
		int pos_root = root(map, pos);//���root
		if (pos_root == pos)//root�����Լ�����ʾ����һ��island
			++count;

		std::vector<int> dx = { 1, 0, 0, -1 };//��������4����
		std::vector<int> dy = { 0, 1, -1, 0 };
		for (int j = 0; j < dx.size(); ++j)
		{
			int new_pos = (x + dx[j]) * m + y + dy[j];
			if (x + dx[j] < 0 || x + dx[j] >= m || y + dy[j] < 0 || y + dy[j] >= n)//�ж�����ĺϷ���
				continue;

			if (map.find(new_pos) != map.end())//��Χ�ĵ�Ҳ�ڼ�����
			{
				int new_pos_root = root(map, new_pos);
				if (new_pos_root != pos_root)//��Χ�ĵ��root��һ�������кϲ���island��������1
				{
					map[new_pos_root] = pos;
					--count;
				}
			}
		}
		result.push_back(count);
	}
	return result;
}