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
	int m = obstacleGrid.size(), n = obstacleGrid[0].size();
	std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
	dp[0][1] = 1;

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (obstacleGrid[i][j] == 1)
				dp[i + 1][j + 1] = 0;
			else
				dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j];
		}
	}

	return dp[m][n];
}