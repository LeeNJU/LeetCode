#include<vector>
//��Ŀ����������һ����СΪn�����飬ֻ����0,1,2��...,n������������һ����ȱʧ���ҵ�ȱʧ���Ǹ���
//�ⷨ������������first missing number����
int missingNumber(std::vector<int>& nums) 
{
	for (int i = 0; i < nums.size(); ++i)
	{
		while (nums[i] < nums.size() && i != nums[i])//ע������Ľ���������������һ�����Ĵ�С����������±�
		{
			std::swap(nums[i], nums[nums[i]]);
		}
	}

	for (int i = 0; i < nums.size(); ++i)//�ҵ���һ�����ȵ���
	{
		if (i != nums[i])
			return i;
	}
	return nums.size();
}