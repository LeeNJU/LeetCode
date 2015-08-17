#include<vector>
#include<algorithm>
//��Ŀ����������һ�����飬�����ҵ������������飬ʹ��������ĺ����
//�ⷨ��������̬�滮��ά�������������ֲ����ŽⱣ�������ǰԪ�ص����Ž⣬ȫ�����Ž��ʾ�ӳ�ʼλ�õ���ǰԪ�ص����Ž⡣

int maxSubArray(std::vector<int>& nums) 
{
	if (nums.empty())
		return 0;

	int local_max = nums[0], global_max = nums[0];
	for (int i = 1; i < nums.size(); ++i)
	{
		local_max = std::max(local_max + nums[i], nums[i]);//�ֲ����ű��������ǰԪ�أ������������������ȡ���
		global_max = std::max(local_max, global_max); //ȫ�����Ŵ���һ��Ԫ�ص�ȫ�����ź͵�ǰ�ľֲ�����ȡ���
	}
	return global_max;
}