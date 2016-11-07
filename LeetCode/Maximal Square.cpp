#include<vector>
#include<algorithm>

//题目描述：给定一个2d矩阵，里面包含0和1，找出其中最大的全是1组成的正方形的面积
//解法描述：动态规划 dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1
//         dp[i][j]表示已i和j为右下角元素的全1的正方形的边长
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
				dp[i + 1][j + 1] = std::min(std::min(dp[i][j], dp[i][j + 1]), dp[i + 1][j]) + 1;//注意这里的下标
			max_length = std::max(dp[i + 1][j + 1], max_length);
		}
	}
	return max_length * max_length;
}