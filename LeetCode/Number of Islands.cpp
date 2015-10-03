#include<vector>
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