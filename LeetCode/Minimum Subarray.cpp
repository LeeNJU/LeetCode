#include<vector>
#include<algorithm>
//��Ŀ����������һ�����飬�����ҵ������������飬ʹ��������ĺ���С
//�ⷨ��������̬�滮��ά�������������ֲ����ŽⱣ�������ǰԪ�ص����Ž⣬ȫ�����Ž��ʾ�ӳ�ʼλ�õ���ǰԪ�ص����Ž⡣

int minSubArray(std::vector<int> nums) 
{
	int global_sum = nums[0];
	int local_sum = nums[0];
	for (int i = 1; i < nums.size(); ++i)
	{
		local_sum = std::min(local_sum + nums[i], nums[i]);//�ֲ����ű��������ǰԪ�أ������������������ȡ��С
		global_sum = std::min(global_sum, local_sum);
	}
	return global_sum;
}