#include<vector>
#include<algorithm>
//��Ŀ��������һ��������n���ҵ���С��ƽ������ʹ����Щƽ�����ĺ͵���n������n = 13, 13 = 4 + 9,���Է���2
//�ⷨ��������̬�滮������dp[i],����i֮ǰ��Ԫ�أ��±갴��ƽ�������еݼ���1,4,9
int numSquares(int n) 
{
	std::vector<int> dp(n + 1, n + 1);
	dp[0] = 0;
	for (int i = 1; i < n + 1; ++i)
	{
		for (int j = 1; i - j * j >= 0; ++j)
		{
			dp[i] = std::min(dp[i - j * j] + 1, dp[i]);
		}
	}
	return dp[n];
}