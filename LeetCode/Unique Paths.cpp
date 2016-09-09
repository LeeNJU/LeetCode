#include<vector>
//题目描述：给定一个m*n的矩阵，从（0,0）出发，每次只能向右或者向下移动一步，求总共有多少种到达位置(m,n)的走法
//解法描述：动态规划 状态转移方程是v[i][j] = v[i - 1][j] + v[i][j - 1]

int uniquePaths(int m, int n)
{
	std::vector<std::vector<int>> v(m, std::vector<int>(n, 1));
	for (int i = 1; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			v[i][j] = v[i - 1][j] + v[i][j - 1];
		}
	}
	return v[m - 1][n - 1];
}

//题目描述:给定一个m*n的二维数组，其中的值有的为0， 有的为1,1代表障碍，现在求从(0,0)到(m,n)一共有多少种路线
//        (不能跨越障碍)
//解法描述:动态规划  转移方程 如果obstacleGrid[i][j] == 1，那么dp[i][j] = 0, 如果不等于1， 那么
//         dp[i][j] = dp[i - 1][j] + dp[i][j - 1]

int uniquePathsWithObstacles(std::vector<std::vector<int> > &obstacleGrid)
{
	int row = obstacleGrid.size();
	int col = obstacleGrid[0].size();
	std::vector<std::vector<int>> result(obstacleGrid.size(), std::vector<int>(col));

	result[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
	for (int i = 1; i < row; ++i)//初始化第一行
		result[i][0] = obstacleGrid[i][0] == 1 ? 0 : result[i - 1][0];

	for (int j = 1; j < col; ++j)//初始化第一列
		result[0][j] = obstacleGrid[0][j] == 1 ? 0 : result[0][j - 1];

	for (int i = 1; i < row; ++i)
	for (int j = 1; j < col; ++j)
		result[i][j] = obstacleGrid[i][j] == 1 ? 0 : result[i - 1][j] + result[i][j - 1];

	return result[row - 1][col - 1];
}