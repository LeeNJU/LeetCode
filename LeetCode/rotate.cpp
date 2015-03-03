#include<vector>
#include<algorithm>
//题目描述：给定一个n*n的矩阵，将其顺时针旋转90度
//解法：先沿/对角线进行交换，再沿中线进行交换

void rotate(std::vector<std::vector<int> > &matrix)
{
	const int n = matrix.size();
	for (int i = 0; i < n; ++i)//沿对角线进行交换，注意下标运算
	{
		for (int j = 0; j < n - i; ++j)
		{
			std::swap(matrix[i][j], matrix[n - j - 1][n - i - 1]);
		}
	}

	for (int i = 0; i < n / 2; ++i)//沿中间线进行交换，注意下标运算
	{
		for (int j = 0; j < n; ++j)
		{
			std::swap(matrix[i][j], matrix[n - i - 1][j]);
		}
	}
}