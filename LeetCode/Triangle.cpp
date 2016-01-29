#include<vector>
#include<algorithm>

//题目描述：给定一个二维数组，表示一个三角形的一组数字，求从上到下一条路径，使得路径之和最小，其中每次只能选择
//         下一层的邻近元素，而不是下一层所有元素
//解法描述：动态规划，从下到上进行计算，dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j]

int minimumTotal(std::vector<std::vector<int>> &triangle)
{
	for (int i = triangle.size() - 2; i >= 0; --i)//从倒数第二行开始计算
	{
		for (int j = 0; j < i + 1; ++j)
		{
			triangle[i][j] += std::min(triangle[i + 1][j], triangle[i + 1][j + 1]);
		}
	}
	return triangle[0][0];
}