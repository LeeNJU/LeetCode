#include<vector>
#include<algorithm>

//��Ŀ����������һ����ά���飬��ʾһ�������ε�һ�����֣�����ϵ���һ��·����ʹ��·��֮����С������ÿ��ֻ��ѡ����һ����ڽ�Ԫ�أ���������һ������Ԫ��
//�ⷨ��������̬�滮�����µ��Ͻ��м��㣬dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j]

int minimumTotal(std::vector<std::vector<int>> &triangle)
{
	for (int i = triangle.size() - 2; i >= 0; --i)//�ӵ����ڶ��п�ʼ����
	{
		for (int j = 0; j < i + 1; ++j)
		{
			triangle[i][j] += std::min(triangle[i + 1][j], triangle[i + 1][j + 1]);
		}
	}
	return triangle[0][0];
}