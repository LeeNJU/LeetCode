#include<vector>
//题目描述:给定一个二维矩阵，再给一个矩形坐标，左上角坐标[row1, col1]和右下角[row2, col2],求这个矩形里元素的和
//解法描述:动态规划，用一个二维数组dp[i][j]表示矩形[0,0],[i,j]的和，那么结果就可以用矩形面积差来计算
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