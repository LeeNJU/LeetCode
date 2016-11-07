#include<vector>

//��Ŀ����:����һ�����󣬰�������˳��ת����һά����
//�ⷨ����:�����������¼���ϽǺ����½ǣ������жϱ߽磬ѭ����������Ϊ����������С��1��ÿ��whileѭ���У���4��
//        forѭ������ÿһ��ÿһ��,ע��x1��x2��ȣ�y1��y2��ȵ��������array = {{2,3}}��
//        ��array = {{2}�� {3}}

std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix)
{
	std::vector<int> result;
	if (matrix.empty())
		return result;

	int m = matrix.size();
	int n = matrix[0].size();
	int x1 = 0, y1 = 0, x2 = m - 1, y2 = n - 1;

	while (result.size() < m * n)//������Ĵ�С�������m * n
	{
		for (int i = y1; i <= y2; ++i)//��������һ��
			result.push_back(matrix[x1][i]);

		for (int i = x1 + 1; i <= x2; ++i)//�����ұ�һ��
			result.push_back(matrix[i][y2]);

		if (x2 > x1)//�ж�x2�Ƿ��x1��ȣ���array = {{2,3}}
		{
			for (int i = y2 - 1; i >= y1; --i)//��������һ��
				result.push_back(matrix[x2][i]);
		}

		if (y2 > y1)//�ж�y1��y2�Ƿ���ȣ���array = {{2}�� {3}}
		{
			for (int i = x2 - 1; i > x1; --i)//�������һ��
				result.push_back(matrix[i][y1]);
		}

		++x1;
		++y1;
		--x2;
		--y2;
	}
	return result;
}

//��Ŀ����:����һ������n����������ʽת����һ��n*n�Ķ�ά���飬����n=3��ת����array={{1,2,3}��{8,9,4}��{7,6,5}}
//�ⷨ����:���ĸ�forѭ���ֱ�����������У�����Ҫ�������½Ǻ����½���ȵ��������array={{1,2,3}}

std::vector<std::vector<int> > generateMatrix(int n)
{
	std::vector<int> temp(n, 0);
	std::vector<std::vector<int>> result(n, temp);

	int leftCorner = 0, rightCorner = n - 1;//�����������Σ��������½Ǻ����½�ֻ��Ҫһ��������¼
	for (int i = 1; i <= n * n;)
	{
		for (int j = leftCorner; j <= rightCorner; ++j)//�������һ��
			result[leftCorner][j] = i++;
		for (int j = leftCorner + 1; j <= rightCorner; ++j)//����ұ�һ��
			result[j][rightCorner] = i++;
		for (int j = rightCorner - 1; j >= leftCorner; --j)//�������һ��
			result[rightCorner][j] = i++;
		for (int j = rightCorner - 1; j > leftCorner; --j)//������һ��
			result[j][leftCorner] = i++;

		++leftCorner;
		--rightCorner;
	}

	return result;
}
