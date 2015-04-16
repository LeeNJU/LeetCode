#include<vector>
//��Ŀ����������һ��m*n�ľ��󣬴ӣ�0,0��������ÿ��ֻ�����һ��������ƶ�һ�������ܹ��ж����ֵ���λ��(m,n)���߷�
//�ⷨ��������̬�滮 ״̬ת�Ʒ�����v[i][j] = v[i - 1][j] + v[i][j - 1]

int uniquePaths(int m, int n)
{
	std::vector<std::vector<int>> v(m, std::vector<int>(n, 1));
	for (int i = 1; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			v[i][j] = v[i - 1][j] + v[i][j - 1];
		}
	}
	return v[m - 1][n - 1];
}