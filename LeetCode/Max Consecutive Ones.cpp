#include<vector>
#include<algorithm>
//��Ŀ����:����һ�����飬ֻ����1����0�������������1�ĸ���������[1,1,0,1,1,1]�����3��������1
//�ⷨ����:��̬�滮

int findMaxConsecutiveOnes(std::vector<int>& nums) 
{
	int result = 0;
	int count = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] == 1)
			++count;
		else
			count = 0;

		result = std::max(result, count);
	}
	return result;
}