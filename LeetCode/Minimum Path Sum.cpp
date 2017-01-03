#include<vector>
#include<algorithm>
//题目描述：给定一个m*n的二位数组，其中每个值非负，现在找到从左上到右下的一条路径，使得路径和最小，每次只能向
//         右或向下移动
//解法描述：动态规划 转移方程为dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j]

int minPathSum(std::vector<std::vector<int>>& grid) 
{
	if (grid.empty())
		return 0;

	int m = grid.size(), n = grid[0].size();
	std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, INT_MAX));
	dp[0][1] = 0;
	dp[1][0] = 0;

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			dp[i + 1][j + 1] = std::min(dp[i][j + 1], dp[i + 1][j]) + grid[i][j];
		}
	}
	return dp[m][n];
}