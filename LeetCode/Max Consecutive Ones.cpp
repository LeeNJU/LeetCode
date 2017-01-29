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

//�汾������������������е�һ��0���1������󳤶ȵ�1������[1,0,1,1,0]���ѵ�һ��0���1����󳤶Ⱦ���4
//�ⷨ����:˫ָ�룬[left, right]��ʾһ�����䣬��������������k��0��Ҳ��������k��0���1����¼�����������
//        ���Ⱦ��Ǵ�

int findMaxConsecutiveOnes(std::vector<int> nums) 
{
	int result = 0, zero = 0, k = 1; // flip at most k zero
	for (int left = 0, right = 0; right < nums.size(); ++right)
	{
		if (nums[right] == 0)
			++zero;
		while (zero > k)
		{
			if (nums[left--] == 0)
				--zero;
		}
		
		result = std::max(result, right - left + 1);
	}
	return result;
}