#include<vector>
#include<algorithm>
//��Ŀ����������һ��m*n�Ķ�λ���飬����ÿ��ֵ�Ǹ��������ҵ������ϵ����µ�һ��·����ʹ��·������С��ÿ��ֻ����
//         �һ������ƶ�
//�ⷨ��������̬�滮 ת�Ʒ���Ϊdp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j]

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