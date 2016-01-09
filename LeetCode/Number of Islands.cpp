#include<vector>
#include<unordered_map>
//题目描述：给定一个二维矩阵，值为1或者为0.找到其中小岛的个数，小岛的定义为被0保卫的1，小岛可以包含多个1
//解法描述：对每一个值为1的点进行深搜，访问过的点进行标记，每遇到一个值为1并且没被访问过的点就表示有一个小岛，深搜把
//         该小岛上的点进行标记
void dfs(std::vector<std::vector<char>>& grid, int i, int j, std::vector<std::vector<bool>>& visit)
{                             //深搜，对相邻的1进行标记
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
			if (grid[i][j] == '1' && !visit[i][j])//当前的点为1，并且没有被访问过
			{
				dfs(grid, i, j, visit);
				++count;
			}
		}
	}

	return count;
}

//version2:
//题目描述:给定一个二维数组，全是0，表示水，再给一组操作，表示把(x,y)的值设为1，变成island，现在要求出每一个操作之后有
//        多少个island
//解法描述:用并查集，路径压缩，关键是把二维坐标映射成一维

int root(std::unordered_map<int, int>& map, int value)
{
	if (map.find(value) == map.end())
	{
		map[value] = value;
		return value;
	}

	int result = value, t;
	while (result != map[result])//找到根节点
	{
		result = map[result];
	}

	while (value != map[value]) //路径压缩，把所有的点都指向根节点
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
		int pos = x * m + y; //把二维坐标映射到一维
		int pos_root = root(map, pos);//算出root
		if (pos_root == pos)//root等于自己，表示多了一个island
			++count;

		std::vector<int> dx = { 1, 0, 0, -1 };//上下左右4个点
		std::vector<int> dy = { 0, 1, -1, 0 };
		for (int j = 0; j < dx.size(); ++j)
		{
			int new_pos = (x + dx[j]) * m + y + dy[j];
			if (x + dx[j] < 0 || x + dx[j] >= m || y + dy[j] < 0 || y + dy[j] >= n)//判断坐标的合法性
				continue;

			if (map.find(new_pos) != map.end())//周围的点也在集合中
			{
				int new_pos_root = root(map, new_pos);
				if (new_pos_root != pos_root)//周围的点的root不一样，进行合并，island的数量减1
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