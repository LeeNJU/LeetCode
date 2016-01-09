#include<vector>
#include<unordered_map>
//��Ŀ����������һ����ά����ֵΪ1����Ϊ0.�ҵ�����С���ĸ�����С���Ķ���Ϊ��0������1��С�����԰������1
//�ⷨ��������ÿһ��ֵΪ1�ĵ�������ѣ����ʹ��ĵ���б�ǣ�ÿ����һ��ֵΪ1����û�����ʹ��ĵ�ͱ�ʾ��һ��С�������Ѱ�
//         ��С���ϵĵ���б��
void dfs(std::vector<std::vector<char>>& grid, int i, int j, std::vector<std::vector<bool>>& visit)
{                             //���ѣ������ڵ�1���б��
	if (visit[i][j] || grid[i][j] == '0')
		return;

	visit[i][j] = true;
	if (i - 1 >= 0)
		dfs(grid, i - 1, j, visit);
	if (j - 1 >= 0)
		dfs(grid, i, j - 1, visit);
	if (j + 1 < grid[0].size())
		dfs(grid, i, j + 1, visit);
	if (i + 1 < grid.size())
		dfs(grid, i + 1, j, visit);

}
int numIslands(std::vector<std::vector<char>>& grid) 
{
	int count = 0;
	if (grid.empty())
		return count;

	std::vector<std::vector<bool>> visit(grid.size(), std::vector<bool>(grid[0].size(), false));
	for (int i = 0; i < grid.size(); ++i)
	{
		for (int j = 0; j < grid[0].size(); ++j)
		{
			if (grid[i][j] == '1' && !visit[i][j])//��ǰ�ĵ�Ϊ1������û�б����ʹ�
			{
				dfs(grid, i, j, visit);
				++count;
			}
		}
	}

	return count;
}

//version2:
//��Ŀ����:����һ����ά���飬ȫ��0����ʾˮ���ٸ�һ���������ʾ��(x,y)��ֵ��Ϊ1�����island������Ҫ���ÿһ������֮����
//        ���ٸ�island
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