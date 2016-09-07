#include<vector>
#include<algorithm>
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