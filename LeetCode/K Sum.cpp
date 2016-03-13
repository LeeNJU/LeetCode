#include<vector>
//��Ŀ����:����һ�����飬Ҫ���ҳ�k������ʹ�����ǵĺ͵���ĳ��������ֵ���������ֽ�ĸ���
//�ⷨ����:��̬�滮��dp[i][j][t]��ʾ��0��j��i�����ĺ�Ϊt�Ľ�ĸ�����dp[i][j][t] = dp[i][j - 1][t] + 
//        dp[i - 1][j - 1][t - A[j - 1]]����Ҫ�ж�t - A[j]�Ƿ���ڵ���0

int kSum(std::vector<int> A, int k, int target) 
{
	std::vector<std::vector<std::vector<int>>> dp(k + 1, std::vector<std::vector<int>>(A.size() + 1, std::vector<int>(target + 1, 0)));
	for (int t = 0; t < target + 1; ++t)
	{
		for (int i = 0; i < k; ++i)
		{
			for (int j = 0; j < A.size(); ++j)
			{
				if (t == 0 && i == 0)
					dp[i][j][t] = 1;
				else
				{
					dp[i + 1][j + 1][t] = dp[i + 1][j][t];
					if (t - A[j] >= 0)
						dp[i + 1][j + 1][t] += dp[i][j][t - A[j]];
				}
			}
		}
	}
	return dp[k][A.size()][target];

}