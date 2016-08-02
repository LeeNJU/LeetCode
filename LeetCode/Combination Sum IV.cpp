#include<vector>
#include<algorithm>
//��Ŀ����:����һ�������������һ��ֵtarget��Ҫ���ҵ����ֵ���ϣ�ʹ�����ǵĺ���target��ÿ�����ֿ����ظ�ʹ��
//�ⷨ����:���������ѣ��ᳬʱ����̬�滮dp[i] += dp[i - dp[i - nums[j]]],dp[i]��ʾ��Ϊi������������i�ȵ�ǰ
//        Ԫ��nums[j]�����������dp[i - nums[j]]

int combinationSum4(std::vector<int>& nums, int target) 
{
	std::vector<int> dp(target + 1, 0);
	dp[0] = 1;

	for (int i = 1; i < dp.size(); ++i) 
	{
		for (int j = 0; j < nums.size(); ++j) 
		{
			if (i - nums[j] >= 0) 
				dp[i] += dp[i - nums[j]];
		}
	}
	return dp[target];
}