#include<vector>
#include<algorithm>
//��Ŀ����:����һ�����飬�ҵ���ĵ��������У������в�һ��Ҫ����
//�ⷨ����:��̬�滮��dp[i] = max(dp[i], dp[j] + 1),����nums[j]Ҫ��nums[i]С����ʾ�ҵ�һ�����ܵĵ���������

int lengthOfLIS(std::vector<int>& nums) 
{
	if (nums.empty())
		return 0;

	std::vector<int> dp(nums.size(), 1);
	int max_length = 1;
	for (int i = 1; i < nums.size(); ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (nums[j] < nums[i])
				dp[i] = std::max(dp[i], dp[j] + 1);
		}
		max_length = std::max(max_length, dp[i]);
	}
	return max_length;
}