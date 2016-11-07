#include<vector>

//题目描述:给定一个矩阵，按照螺旋顺序转换成一维数组
//解法描述:用两个坐标记录左上角和右下角，用来判断边界，循环结束条件为行数或列数小于1，每个while循环中，用4个
//        for循环处理每一行每一列,注意x1与x2相等，y1与y2相等的情况，即array = {{2,3}}，
//        或array = {{2}， {3}}

std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix)
{
	std::vector<int> result;
	if (matrix.empty())
		return result;

	int m = matrix.size();
	int n = matrix[0].size();
	int x1 = 0, y1 = 0, x2 = m - 1, y2 = n - 1;

	while (result.size() < m * n)//结果集的大小必须等于m * n
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
	}
	return result;
}

//题目描述:给定一个数字n，用螺旋方式转换成一个n*n的二维数组，例如n=3，转换成array={{1,2,3}，{8,9,4}，{7,6,5}}
//解法描述:用四个for循环分别填充两行两列，不需要考虑左下角和右下角相等的情况，即array={{1,2,3}}

std::vector<std::vector<int> > generateMatrix(int n)
{
	std::vector<int> temp(n, 0);
	std::vector<std::vector<int>> result(n, temp);

	int leftCorner = 0, rightCorner = n - 1;//由于是正矩形，所以左下角和右下角只需要一个变量记录
	for (int i = 1; i <= n * n;)
	{
		for (int j = leftCorner; j <= rightCorner; ++j)//填充上面一行
			result[leftCorner][j] = i++;
		for (int j = leftCorner + 1; j <= rightCorner; ++j)//填充右边一列
			result[j][rightCorner] = i++;
		for (int j = rightCorner - 1; j >= leftCorner; --j)//填充下面一行
			result[rightCorner][j] = i++;
		for (int j = rightCorner - 1; j > leftCorner; --j)//填充左边一列
			result[j][leftCorner] = i++;

		++leftCorner;
		--rightCorner;
	}

	return result;
}
