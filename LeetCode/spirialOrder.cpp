#include<vector>
//给定一个矩阵，按照螺旋顺序转换成一维数组
//解法：用两个坐标记录左上角和右下角，用来判断边界，循环结束条件为行数或列数小于1，每个while循环中，用4个for循环处理每一行每一列
//注意x1与x2相等，y1与y2相等的情况，即array = {{2,3}}，或array = {{2}， {3}}

std::vector<int> spiralOrder(std::vector<std::vector<int> > &matrix)
{
	std::vector<int> result;
	if (matrix.empty())
		return result;

	int m = matrix.size();
	int n = matrix[0].size();
	int x1 = 0, y1 = 0, x2 = m - 1, y2 = n - 1;

	while (m >= 1 && n >= 1)//行数和列数必须大于等于1
	{
		for (int i = y1; i <= y2; ++i)//处理上面一行
			result.push_back(matrix[x1][i]);

		for (int i = x1 + 1; i <= x2; ++i)//处理右边一列
			result.push_back(matrix[i][y2]);

		if (x2 > x1)//判断x2是否和x1相等，即array = {{2,3}}
		{
			for (int i = y2 - 1; i >= y1; --i)//处理下面一行
				result.push_back(matrix[x2][i]);
		}

		if (y2 > y1)//判断y1与y2是否相等，即array = {{2}， {3}}
		{
			for (int i = x2 - 1; i > x1; --i)//处理左边一列
				result.push_back(matrix[i][y1]);
		}

		++x1;
		++y1;
		--x2;
		--y2;
		m -= 2;//行数和列数减去2
		n -= 2;
	}
	return result;
}