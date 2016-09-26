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

//��Ŀ����:����һ�����飬�ҵ��������ص��������飬ʹ������������ĺ����
//�ⷨ����:����������left��right��left��ʾ��0��i�����������ĺͣ�right��ʾ��n-1��i�����������ĺͣ������
//        left���ٷ���ɨ�����right��ɨ�������������������������
int maxTwoSubArrays(std::vector<int> nums)
{
	if (nums.size() < 2)
		return 0;

	std::vector<int> left(nums.size(), 0);
	left[0] = nums[0];

	int local = nums[0];
	for (int i = 1; i < nums.size(); ++i)
	{
		local = std::max(nums[i], nums[i] + local);
		left[i] = std::max(left[i - 1], local);
	}

	local = nums[nums.size() - 1];
	int sum = left[nums.size() - 2] + nums[nums.size() - 1];
	int right_max = nums.back();
	for (int i = nums.size() - 2; i > 0; --i)
	{
		local = std::max(nums[i], nums[i] + local);
		right_max = std::max(local, right_max);
		sum = std::max(sum, left[i - 1] + right_max);
	}
	return sum;
}