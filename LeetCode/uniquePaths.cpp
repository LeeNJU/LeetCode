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