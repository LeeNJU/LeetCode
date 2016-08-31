#include<vector>
//��Ŀ����:����n�����ӣ�Ͷ����n�����ӣ���õ���ͬ��ֵ���Լ�ֵ�ĺ�S����õ�ÿһ��S�Ŀ����ԣ�����n = 1��ÿ��Ͷ��
//        ֻ��һ�ֽ����1��2��3��4��5��6�������Զ���1/6������(1, 0.17), (2, 0.17), (3, 0.17)
//�ⷨ����:��̬�滮��dp[i][j]��ʾi�����ӵĺ���j�Ĵ�������ôdp[i][j] += dp[i - 1][j - k], ����1<= k <=6,Ȼ��
//        ͳ�����еĴ�����������

std::vector<std::pair<int, double>> dicesSum(int n) 
{
	std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(6 * n + 1, 0));
	dp[0][0] = 1; //ע�������ʼ��Ϊ1

	for (int i = 1; i < n + 1; ++i)
	{
		for (int j = 1; j < 6 * n + 1; ++j)
		{
			for (int k = 1; k <= 6; ++k)
			{
				if (j >= k)
					dp[i][j] += dp[i - 1][j - k];
			}
		}
	}

	long long sum = 0; //ͳ�ƴ���
	for (int i = 0; i < 6 * n + 1; ++i)
	{
		if (dp[n][i] > 0)
			sum += dp[n][i];
	}

	std::vector<std::pair<int, double>> result;
	for (int i = 1; i < 6 * n + 1; ++i)
	{
		if (dp[n][i] > 0)
			result.push_back(std::pair<int, double>(i, dp[n][i] / (double) sum));
	}

	return result;
}