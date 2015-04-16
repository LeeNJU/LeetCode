#include<vector>
//��Ŀ����������һ��m*n�Ķ�ά���飬���е�ֵ�е�Ϊ0�� �е�Ϊ1,1�����ϰ����������(0,0)��(m,n)һ���ж�����·�ߣ����ܿ�Խ�ϰ���
//�ⷨ��������̬�滮  ת�Ʒ��� ���obstacleGrid[i][j] == 1����ôdp[i][j] = 0, ���������1�� ��ôdp[i][j] = dp[i - 1][j] + dp[i][j - 1]

int uniquePathsWithObstacles(std::vector<std::vector<int> > &obstacleGrid)
{
	int row = obstacleGrid.size();
	int col = obstacleGrid[0].size();
	std::vector<std::vector<int>> result(obstacleGrid.size(), std::vector<int>(col));
	
	result[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
	for (int i = 1; i < row; ++i)//��ʼ����һ��
		result[i][0] = obstacleGrid[i][0] == 1 ? 0 : result[i - 1][0];

	for (int j = 1; j < col; ++j)//��ʼ����һ��
		result[0][j] = obstacleGrid[0][j] == 1 ? 0 : result[0][j - 1];
	
	for (int i = 1; i < row; ++i)
	    for (int j = 1; j < col; ++j)
		    result[i][j] = obstacleGrid[i][j] == 1 ? 0 : result[i - 1][j] + result[i][j - 1];

	return result[row - 1][col - 1];
}