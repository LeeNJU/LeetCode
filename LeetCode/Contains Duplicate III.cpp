#include<vector>

//��Ŀ����������һ�����飬�ж��Ƿ����Ԫ��A[i]��A[j]��ʹ��i��j�Ĳ����k��A[i]��A[j]�Ĳ����t
//�ⷨ������

bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int k, int t)
{
	if (nums.size() < 2)
		return false;

	for (int i = 0; i + k < nums.size(); ++i)
	{
		for (int j = i; j <= i + k; ++j)
		{
			if (abs(nums[i] - nums[j]) <= t)
				return true;
		}
	}
	return false;
}