#include<vector>
#include<unordered_map>
//��Ŀ����������һ�����飬�ж��Ƿ����Ԫ��A[i]��A[j]��ʹ��i��j�Ĳ����k��A[i]��A[j]�Ĳ����t
//�ⷨ������

bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int k, int t)
{
	std::unordered_map<int, int> m;
	int j = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (i - j > k)
		{

		}
		else
		{
			std::unordered_map<int, int>::iterator iter = m.lower_bound(nums[i] - t);
		}
		m[nums[i]] = i;
	}
}