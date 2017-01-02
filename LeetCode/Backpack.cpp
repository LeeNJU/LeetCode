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

//���֣�����n��item��ÿ��item�������ͼ�ֵ��Ҫ������֮�Ͳ�����m��ʹ�ü�ֵ֮�����
//�ⷨ����:���������ƣ�ֻ�Ǽӵ�ֵ�����value
int backPackII(int m, std::vector<int> A, std::vector<int> V) 
{
	std::vector<int> dp(m + 1, 0);
	for (int i = 1; i < A.size() + 1; ++i)
	{
		for (int j = m; j >= 1; --j)
		{
			if (j - A[i - 1] < 0)//Ҫ��֤j - A[i - 1] >= 0����װ����
				dp[j] = dp[j];
			else
				dp[j] = std::max(dp[j], dp[j - A[i - 1]] + V[i - 1]);
		}
	}
	return dp[m];
}

//����:����n��item��ÿ��item���������ͼ�ֵ�������Ĵ�СΪm��ÿ��item���Զ��ѡ��ʹ�ü�ֵ���
//    ����������A = [2, 3, 5, 7]����ֵ��V = [1, 5, 2, 4],������СΪ10������ֵ��15 = 3 + 5 + 5
//�ⷨ:dp[j]��ʾ������СΪj��ʱ����װ������ֵ��dp[j] = max(dp[j], V[i] + dp[j - A[i]])

int backPackIII(std::vector<int> A, std::vector<int> V, int m) 
{
	std::vector<int> dp(m + 1, 0);
	for (int i = 0; i < A.size(); ++i) 
	{
		for (int j = 1; j <= m; j++) 
		{
			if (j >= A[i]) 
				dp[j] = std::max(dp[j], dp[j - A[i]] + V[i]);
		}
	}
	return dp[m];
}