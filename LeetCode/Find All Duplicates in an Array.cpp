#include<vector>
//��Ŀ����:����һ�����飬�����Ԫ�ط�Χ��1��n��n�������С���е�Ԫ�س���һ�Σ��е�Ԫ�س������Σ��ҵ���������
//        ������Ԫ�أ�����[4,3,2,7,8,2,3,1]���������ε�Ԫ����2��3
//�ⷨ����:������first missing positive number�Ľⷨ

std::vector<int> findDuplicates(std::vector<int>& nums) 
{
	std::vector<int> result;
	for (int i = 0; i < nums.size(); ++i)
	{
		while (nums[i] != i + 1 && nums[nums[i] - 1] != nums[i])
			std::swap(nums[i], nums[nums[i] - 1]);
	}

	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] != i + 1)
			result.push_back(nums[i]);
	}

	return result;
}