#include<vector>

//给定一个数字n，用螺旋方式转换成一个n*n的二维数组，例如n=3，转换成array={{1,2,3}，{8,9,4}，{7,6,5}}
//解法：用四个for循环分别填充两行两列，不需要考虑左下角和右下角相等的情况，即array={{1,2,3}}

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
