#include<vector>
#include<algorithm>
//��Ŀ����������һ�������������ÿ����ͥ��Ǯ������ȥ���٣����ǲ����������������ң�����������ٶ���Ǯ
//�ⷨ��������̬�滮  dp[i] = max(dp[i - 1], dp[i - 2] + n[i])

int rob(std::vector<int>& nums)
{
	if (nums.size() <= 1) 
		return nums.empty() ? 0 : nums[0];
	
	std::vector<int> dp = { nums[0], std::max(nums[0], nums[1]) };
	for (int i = 2; i < nums.size(); ++i) 
	{
		dp.push_back(std::max(nums[i] + dp[i - 2], dp[i - 1]));
	}
	return dp.back();
}