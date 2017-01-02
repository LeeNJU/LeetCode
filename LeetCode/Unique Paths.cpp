#include<vector>
//��Ŀ����������һ��m*n�ľ��󣬴ӣ�0,0��������ÿ��ֻ�����һ��������ƶ�һ�������ܹ��ж����ֵ���λ��(m,n)���߷�
//�ⷨ��������̬�滮 ״̬ת�Ʒ�����v[i][j] = v[i - 1][j] + v[i][j - 1]

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

//��Ŀ����:����һ��m*n�Ķ�ά���飬���е�ֵ�е�Ϊ0�� �е�Ϊ1,1�����ϰ����������(0,0)��(m,n)һ���ж�����·��
//        (���ܿ�Խ�ϰ�)
//�ⷨ����:��̬�滮  ת�Ʒ��� ���obstacleGrid[i][j] == 1����ôdp[i][j] = 0, ���������1�� ��ô
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