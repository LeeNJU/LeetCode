#include<vector>

//题目：给定一个m*n的矩阵，如果某一个元素等于0，那么就把这一行和这一列的所有元素设为0
//解法：复杂度m*n,空间复杂度O(1)，先做标记，再设为0. 先扫描第一行和第一组，如果有元素等于0，就做标记，如果一个元素a[i][j]等于0，那么把a[0][j]和a[i][0]设为0作为标记，
//然后扫描整个矩阵，如果a[0][j]或者a[i][0]等于0，就把a[i][j]设为0

void setZeroes(std::vector<std::vector<int> > &matrix)
{
	const int row = matrix.size();
	const int col = matrix[0].size();
	bool row_has_zero = false;
	bool col_has_zero = false;

	for (int i = 0; i < col; ++i)//检测第一行是否存在0
	{
		if (matrix[0][i] == 0)
		{
			row_has_zero = true;
			break;
		}
	}

	for (int i = 0; i < row; ++i)//检测第一列是否存在0
	{
		if (matrix[i][0] == 0)
		{
			col_has_zero = true;
			break;
		}
	}

	for (int i = 1; i < row; ++i)//开始扫描矩阵，如果某个元素等于0，就把对应的第一个行和第一列设为0作为标记
	{
		for (int j = 1; j < col; ++j)
		{
			if (matrix[i][j] == 0)
			{
				matrix[0][j] = 0;
				matrix[i][0] = 0;
			}
		}
	}

	for (int i = 1; i < row; ++i)
	{
		for (int j = 1; j < col; ++j)
		{
			if (matrix[i][0] == 0 || matrix[0][j] == 0)
				matrix[i][j] = 0;
		}
	}

	if (row_has_zero)//如果第一行存在0，就把第一行所有元素设为0
	for (int j = 0; j < col; ++j)
		matrix[0][j] = 0;

	if (col_has_zero)//如果第一列存在0，就把第一列所有元素设为0
	for (int i = 0; i < row; ++i)
		matrix[i][0] = 0;
}