#include<vector>
#include<algorithm>
//��Ŀ��������һ��������n���ҵ���С��ƽ������ʹ����Щƽ�����ĺ͵���n������n = 13, 13 = 4 + 9,���Է���2
//�ⷨ��������̬�滮������dp[i],����i֮ǰ��Ԫ�أ��±갴��ƽ�������еݼ���1,4,9
int numSquares(int n) 
{
	std::vector<int> dp(n, n);
	dp[0] = 1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 1; i - j * j >= -1; ++j)//ע��֮�����ֹ����
			dp[i] = std::min(dp[i - j * j] + 1, dp[i]);
	}
	return dp[n - 1];
}