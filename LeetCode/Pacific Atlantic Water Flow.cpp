#include<vector>
#include<queue>
//题目描述:给定一个N*N矩阵代表地势的高度，矩阵的上边和左边代表太平洋，下边和右边代表大西洋，如果下雨，雨水只能
//        流到相同地势或者低一点的地势。在矩阵中找出能够流到两大洋的点的下标
//解法描述:从上边和左边的点出发，广搜找到能流到太平洋的点，然后从右边和下标出发，广搜找到能流到大西洋的点，然后
//        二者求交集

void bfs(std::vector<std::vector<int>>& matrix, std::vector<std::vector<bool>>& visited, std::queue<std::pair<int, int>>& q) 
{
	int m = matrix.size(), n = matrix[0].size();
	std::vector<std::vector<int>> dirs{ { 0, -1 }, { -1, 0 }, { 0, 1 }, { 1, 0 } };
	while (!q.empty()) 
	{
		auto t = q.front(); 
		q.pop();
		for (auto dir : dirs) 
		{
			int x = t.first + dir[0], y = t.second + dir[1];
			if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || matrix[x][y] < matrix[t.first][t.second]) 
				continue;
			
			visited[x][y] = true;
			q.push({ x, y });
		}
	}
}

std::vector<std::pair<int, int>> pacificAtlantic(std::vector<std::vector<int>>& matrix) 
{
	if (matrix.empty() || matrix[0].empty()) 
		return{};
	
	std::vector<std::pair<int, int>> result;
	int m = matrix.size(), n = matrix[0].size();
	std::queue<std::pair<int, int>> q1, q2;
	std::vector<std::vector<bool>> pacific(m, std::vector<bool>(n, false)), atlantic = pacific;
	
	for (int i = 0; i < m; ++i) 
	{
		q1.push({ i, 0 });
		q2.push({ i, n - 1 });
		pacific[i][0] = true;
		atlantic[i][n - 1] = true;
	}
	
	for (int i = 0; i < n; ++i) 
	{
		q1.push({ 0, i });
		q2.push({ m - 1, i });
		pacific[0][i] = true;
		atlantic[m - 1][i] = true;
	}
	
	bfs(matrix, pacific, q1);
	bfs(matrix, atlantic, q2);
	
	for (int i = 0; i < m; ++i) //二者求交集
	{
		for (int j = 0; j < n; ++j) 
		{
			if (pacific[i][j] && atlantic[i][j]) 
				result.push_back({ i, j });
		}
	}

	return result;
}