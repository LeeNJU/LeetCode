#include<vector>
#include<numeric>
//��Ŀ����:����һ���Ǹ����飬�ж��Ƿ��ܹ�������ֳ������֣�ʹ���������ֵĺ���ȣ������������[1, 5, 11, 5]��
//        ��������Ա��ֳ�[1,5,5]��[11]�����֣�����true��������ֳܷ���ȵ������֣�����false
//�ⷨ����:���������ĺ�sum������ת�����ܹ����������ҵ�Ԫ��ʹ��Ԫ�صĺ͵���sum��һ�룬���˱������⡣

bool canPartition(std::vector<int>& nums) 
{
	int sum = std::accumulate(nums.begin(), nums.end(), 0);
	if (sum % 2 == 1) //����ĺͱ�����ż��
		return false;
	
	int target = sum / 2;
	std::vector<bool> dp(target + 1, false);
	dp[0] = true;
	for (int i = 0; i < nums.size(); ++i)//ע�������ѭ��������nums����Ϊÿ��Ԫ��ֻ����һ�� 
	{
		for (int j = target; j >= nums[i]; --j) 
			dp[j] = dp[j] || dp[j - nums[i]];
	}
	return dp.back();
}