#include<vector>
#include<algorithm>
//��Ŀ����:��������,����һ�������һ��ֵw����������ѡ������Ԫ�أ�ֵ��Ԫ��֮�;����ܽӽ�w
//�ⷨ����:dp[i][j]��ʾ��1����i��Ԫ��Ҫװ��j�Ŀռ䣬�ֳ����������dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 
//        A[i - 1]] + A[i - 1]).�����ѡ���i��Ԫ�أ���ôdp[i][j] = dp[i - 1][j],���ѡ���i��Ԫ��,��ô����
//        dp[i - 1][j - A[i - 1]]�����ڸ���dp[i][j]ֻ��Ҫ��һ�����Ϣ�������Ż��ռ䣬ֻ��Ҫһά����

int backPack(int m, std::vector<int> A) 
{
	std::vector<int> dp(m + 1, 0);
	for (int i = 1; i < A.size() + 1; ++i)
	{
		for (int j = m; j >= 1; --j)
		{
			if (j - A[i - 1] < 0)//Ҫ��֤j - A[i - 1] >= 0����װ����
				dp[j] = dp[j];
			else
				dp[j] = std::max(dp[j], dp[j - A[i - 1]] + A[i - 1]);
		}
	}
	return dp[m];
}