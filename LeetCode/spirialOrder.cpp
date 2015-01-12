#include<vector>
//����һ�����󣬰�������˳��ת����һά����
//�ⷨ�������������¼���ϽǺ����½ǣ������жϱ߽磬ѭ����������Ϊ����������С��1��ÿ��whileѭ���У���4��forѭ������ÿһ��ÿһ��
//ע��x1��x2��ȣ�y1��y2��ȵ��������array = {{2,3}}����array = {{2}�� {3}}

std::vector<int> spiralOrder(std::vector<std::vector<int> > &matrix)
{
	std::vector<int> result;
	if (matrix.empty())
		return result;

	int m = matrix.size();
	int n = matrix[0].size();
	int x1 = 0, y1 = 0, x2 = m - 1, y2 = n - 1;

	while (m >= 1 && n >= 1)//����������������ڵ���1
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
		m -= 2;//������������ȥ2
		n -= 2;
	}
	return result;
}