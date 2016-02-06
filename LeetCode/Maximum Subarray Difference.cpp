#include<vector>
#include<algorithm>
//��Ŀ����:����һ�����飬�ҵ��������ص���������A��B��ʹ��������A�ĺ���������B�ĺ͵Ĳ���󣬼�|sum(A) - sum(B)|
//�ⷨ����:����ʹA���B��С�����ǲ�֪��A����߻����ұߣ����A����ߣ����ҵ�����������ͣ�Ȼ���������ɨ�裬
//        �ҵ�����С�������飬Ȼ�󱣴���߲�����ֵ�����A���ұߣ��Ǿ�Ҫ�������ң����ҵ�ֵ��С�������飬Ȼ��
//        ��������ɨ�裬�õ������������飬ͬʱ�������֮������ֵ
int maxDiffSubArrays(std::vector<int> nums) 
{
	if (nums.empty())
		return 0;

	std::vector<int> max_dp(nums.size(), INT_MIN); //����������ҵ�����������
	std::vector<int> min_dp(nums.size(), INT_MAX); //����������ҵ���С�������
	max_dp[0] = nums[0];
	min_dp[0] = nums[0];

	int max_local = nums[0];
	int min_local = nums[0];
	for (int i = 1; i < nums.size(); ++i)  //����������С��������
	{
		max_local = std::max(max_local + nums[i], nums[i]);
		max_dp[i] = std::max(max_dp[i], max_local);
		min_local = std::min(min_local + nums[i], nums[i]);
		min_dp[i] = std::min(min_dp[i], min_local);
	}

	max_local = nums[nums.size() - 1];
	min_local = nums[nums.size() - 1];

	int result = std::max(max_dp[nums.size() - 2] - min_local, max_local - min_dp[nums.size() - 2]);
	for (int i = nums.size() - 2; i >= 1; --i) //��������ɨ�裬�õ�������С��������ͣ�ͬʱ������ֵ
	{
		max_local = std::max(nums[i], max_local + nums[i]);
		min_local = std::min(nums[i], min_local + nums[i]);
		result = std::max(result, std::max(max_dp[i - 1] - min_local, max_local - min_dp[i - 1]));
	}
	return result;
}