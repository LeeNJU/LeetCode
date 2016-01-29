#include<vector>
#include<algorithm>

//��Ŀ����������һ��2d�����������0��1���ҳ���������ȫ��1��ɵ������ε����
//�ⷨ��������̬�滮 dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1
//         dp[i][j]��ʾ��i��jΪ���½�Ԫ�ص�ȫ1�������εı߳�
int maximalSquare(std::vector<std::vector<char>>& matrix)
{
	if (matrix.empty())
		return 0;

	int max_length = 0;
	std::vector<std::vector<int>> dp(matrix.size() + 1, std::vector<int>(matrix[0].size() + 1, 0));

	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j < matrix[0].size(); ++j)
		{
			if (matrix[i][j] == '1')
				dp[i + 1][j + 1] = std::min(std::min(dp[i][j], dp[i][j + 1]), dp[i + 1][j]) + 1;//ע��������±�
			else
				dp[i + 1][j + 1] = 0;
			max_length = std::max(dp[i + 1][j + 1], max_length);
		}
	}
	return max_length * max_length;
}