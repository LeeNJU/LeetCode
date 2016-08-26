#include<vector>
//��Ŀ��������һ���������飬ɾ�����е��ظ�Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Σ����������鳤��
//�ⷨ��index��ʾ���±꣬i=1��ʼ�������飬���A[index]������A[i]
int removeDuplicates(std::vector<int>& nums)
{
	if (nums.empty())
		return 0;

	int index = 0;
	for (int i = 1; i < nums.size(); ++i)
	{
		if (nums[i] != nums[i - 1])
			nums[++index] = nums[i];
	}

	return index + 1;
}

//�汾��������һ���������飬ɾ�����е��ظ�Ԫ�أ�ʹ��ÿ��Ԫ�����������Σ������س���
//�ⷨ�����������ƣ���һ��������¼����
int removeDuplicates2(std::vector<int>& nums) 
{
	if (nums.size() <= 2)
		return nums.size();

	int count = 1;
	int index = 0;
	for (int i = 1; i < nums.size(); ++i)
	{
		if (nums[i] == nums[i - 1])
		{
			++count;
			if (count <= 2)
				nums[++index] = nums[i];
		}
		else
		{
			nums[++index] = nums[i];
			count = 1;
		}
	}
	return index + 1;
}