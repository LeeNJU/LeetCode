#include<vector>
#include<algorithm>
//��Ŀ����:����һ���������飬ÿ��ѡ��һ�����֣�����[3, 1, 5, 8]����һ��ѡ��1�����ǵõ�3*1*5=15��������
//        [3,5,8],Ȼ��ѡ��5�����ǵõ�15 + 3*5*8=135��������[3,8],Ȼ��ѡ��3�����ǵõ�135 + 1*3*8 = 159��
//        ������[8],Ȼ��ѡ��8�����ǵõ�159 + 1*8*1 = 167. �������û��Ԫ�ؾ���1���棬����Ҫ��õ�������
//        ���Ƕ���
//�ⷨ����:��̬�滮��dp[i][j]��ʾ������[i,j]֮��������������ܵõ��Ľ�ҡ���ôdp[i][j] = max(dp[i][j],
//        dp[i - 1] * dp[k] * dp[j + 1] + dp[i][k - 1] + dp[k + 1][j]), i<=k<=j.
int maxCoins(std::vector<int>& nums) 
{
	int n = nums.size();
	nums.insert(nums.begin(), 1);
	nums.push_back(1);
	std::vector<std::vector<int>> dp(nums.size(), std::vector<int>(nums.size(), 0));

	for (int length = 1; length <= n; ++length)
	{
		for (int i = 1; i + length - 1 < n + 1; ++i)
		{
			int j = i + length - 1;
			for (int k = i; k <= j; ++k)
				dp[i][j] = std::max(dp[i][j], nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k - 1] + dp[k + 1][j]);
		}
	}

	return dp[1][n];
}