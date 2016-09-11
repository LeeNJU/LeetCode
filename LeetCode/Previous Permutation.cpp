#include<vector>
//��Ŀ����:����һ�����飬�����һ��������ϣ��������[1,2,1],��ô��һ��������[1,1,2]
//�ⷨ����:��������ɨ�裬Ӧ���ǵݼ����У��ҵ���һ�����ұ�Ԫ�ش���±꣬Ȼ���������ɨ�裬�ҵ���һ�������Ԫ��
//        С���±꣬Ȼ�󽻻�������Ԫ�أ������±�left + 1�Լ�֮���Ԫ�ؽ��з�ת

std::vector<int> previousPermuation(std::vector<int>& nums) 
{
	int left = nums.size() - 1;
	for (int i = nums.size() - 1; i > 0; --i)
	{
		if (nums[i] < nums[i - 1])
		{
			left = i - 1;
			break;
		}
	}


	if (left == nums.size() - 1)//ȫ���ǵݼ����У�ֱ�ӷ�ת
	{
		reverse(nums.begin(), nums.end());
		return nums;
	}

	int right = 0;
	for (int i = nums.size() - 1; i > left; --i)
	{
		if (nums[i] < nums[left])
		{
			right = i;
			break;
		}
	}

	std::swap(nums[left], nums[right]);
	std::reverse(nums.begin() + left + 1, nums.end());
	return nums;
}