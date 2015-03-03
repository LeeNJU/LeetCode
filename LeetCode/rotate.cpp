#include<vector>
#include<algorithm>
//��Ŀ����������һ��n*n�ľ��󣬽���˳ʱ����ת90��
//�ⷨ������/�Խ��߽��н������������߽��н���

void rotate(std::vector<std::vector<int> > &matrix)
{
	const int n = matrix.size();
	for (int i = 0; i < n; ++i)//�ضԽ��߽��н�����ע���±�����
	{
		for (int j = 0; j < n - i; ++j)
		{
			std::swap(matrix[i][j], matrix[n - j - 1][n - i - 1]);
		}
	}

	for (int i = 0; i < n / 2; ++i)//���м��߽��н�����ע���±�����
	{
		for (int j = 0; j < n; ++j)
		{
			std::swap(matrix[i][j], matrix[n - i - 1][j]);
		}
	}
}