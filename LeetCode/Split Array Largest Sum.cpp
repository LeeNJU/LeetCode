#include<vector>
#include<algorithm>
//��Ŀ����:����һ�������һ��mֵ����ʾ�����黮�ֳ�m�������飬�������������ĺ͡�����[7,2,5,10,8]��m = 2��
//        �ֳ����������飬[7,2,5] and [10,8]�����ĺ���18
//�ⷨ����:���m = 1������������һ�������飬������������ĺͣ����m = nums.size(),��ôÿһ��������һ�������飬
//        ���ĺ;�����������ֵ����ô���մ�һ������������֮�䣬�ö��ֲ��ң��������к������С�ڵ���mid��
//        ������ĸ�����������������С��m��˵��midֵƫ��right = middle������������������mid��right =
//        mid,������������С��mid��˵��midֵ̫С����������mid��left = mid + 1

bool can_split(std::vector<int>& nums, int m, int sum) 
{
	int count = 1, cur_sum = 0;
	for (int i = 0; i < nums.size(); ++i) 
	{
		cur_sum += nums[i];
		if (cur_sum > sum) 
		{
			cur_sum = nums[i];
			++count;
			if (count > m) 
				return false;
		}
	}
	return true;
}

int splitArray(std::vector<int>& nums, int m)
{
	int left = 0, right = 0;
	for (int i = 0; i < nums.size(); ++i) 
	{
		left = std::max(left, nums[i]);
		right += nums[i];
	}

	while (left < right) 
	{
		long long mid = left + (right - left) / 2;
		if (can_split(nums, m, mid)) 
			right = mid;
		else 
			left = mid + 1;
	}
	return left;
}