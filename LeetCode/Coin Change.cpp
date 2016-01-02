#include<vector>
#include<algorithm>
//��Ŀ����:����һ�������ʾӲ�ҵ�ֵ���ٸ�һ��ֵ��Ҫ��������������Ӳ�Ҵճ����ֵ
//�ⷨ����:��̬�滮 dp[i] = min(dp[i], dp[i - coins[j]] + 1)
int coinChange(std::vector<int>& coins, int amount) 
{
	if (amount == 0)
		return 0;

	const int MAX = 1000; //��һ���ܴ��ֵ��ʼ��
	std::vector<int> dp(amount + 1, MAX);
	for (int i = 0; i < coins.size(); ++i)
	{
		if (coins[i] < dp.size()) //��ʼ��
			dp[coins[i]] = 1;
	}
	dp[0] = 0;

	for (int i = 1; i <= amount; ++i)
	{
		for (int j = 0; j < coins.size(); ++j)
		{
			if (i - coins[j] >= 0)
				dp[i] = std::min(dp[i], dp[i - coins[j]] + 1);
		}
	}

	return dp[amount] == MAX ? -1 : dp[amount];
}