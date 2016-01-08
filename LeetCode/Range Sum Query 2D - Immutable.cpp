#include<vector>
//��Ŀ����:����һ����ά�����ٸ�һ���������꣬���Ͻ�����[row1, col1]�����½�[row2, col2],�����������Ԫ�صĺ�
//�ⷨ����:��̬�滮����һ����ά����dp[i][j]��ʾ����[0,0],[i,j]�ĺͣ���ô����Ϳ����þ��������������
class NumMatrix 
{
private:
	std::vector<std::vector<int>> dp;
public:
	NumMatrix(std::vector<std::vector<int>> &matrix) 
	{
		if (matrix.empty())
			return;

		dp.resize(matrix.size() + 1);
		dp[0].resize(matrix[0].size() + 1);
		for (int i = 0; i < matrix.size(); ++i)
		{
			dp[i + 1].resize(matrix[0].size() + 1);
			for (int j = 0; j < matrix[0].size(); ++j)
				dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j] + matrix[i][j] - dp[i][j];
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) 
	{
		return dp[row2 + 1][col2 + 1] - dp[row1][col2 + 1] - dp[row2 + 1][col1] + dp[row1][col1];
	}
};