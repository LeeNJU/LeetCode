#include<vector>
#include<algorithm>
//��Ŀ����������һ��m*n�Ķ�λ���飬����ÿ��ֵ�Ǹ��������ҵ������ϵ����µ�һ��·����ʹ��·������С��ÿ��ֻ�����һ������ƶ�
//�ⷨ��������̬�滮 ת�Ʒ���Ϊdp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j]

int minPathSum(std::vector<std::vector<int> > &grid)
{
	const int row = grid.size();
	const int col = grid[0].size();
	std::vector<std::vector<int>> result(row, std::vector<int>(col));

	result[0][0] = grid[0][0];
	for (int i = 1; i < col; ++i)//��ʼ����һ��
		result[0][i] = result[0][i - 1] + grid[0][i];
	
	for (int j = 1; j < row; ++j)//��ʼ����һ��
		result[j][0] = result[j - 1][0] + grid[j][0];

	for (int i = 1; i < row; ++i)
	{
		for (int j = 1; j < col; ++j)
		{
			result[i][j] = std::min(result[i][j - 1], result[i - 1][j]) + grid[i][j];
		}
	}

	return result[row - 1][col - 1];
}