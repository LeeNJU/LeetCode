#include<vector>
#include<algorithm>
//题目描述：给定一个m*n的二位数组，其中每个值非负，现在找到从左上到右下的一条路径，使得路径和最小，每次只能向
//         右或向下移动
//解法描述：动态规划 转移方程为dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j]

int minPathSum(std::vector<std::vector<int> > &grid)
{
	const int row = grid.size();
	const int col = grid[0].size();
	std::vector<std::vector<int>> result(row, std::vector<int>(col));

	result[0][0] = grid[0][0];
	for (int i = 1; i < col; ++i)//初始化第一行
		result[0][i] = result[0][i - 1] + grid[0][i];
	
	for (int j = 1; j < row; ++j)//初始化第一列
		result[j][0] = result[j - 1][0] + grid[j][0];

	for (int i = 1; i < row; ++i)
	{
		for (int j = 1; j < col; ++j)
			result[i][j] = std::min(result[i][j - 1], result[i - 1][j]) + grid[i][j];
	}

	return result[row - 1][col - 1];
}