#include<vector>
#include<unordered_map>

//��Ŀ����:����һ�����飬�ж������Ƿ�����ظ�Ԫ��
//�ⷨ��������hashtable
bool containsDuplicate(std::vector<int>& nums) {
	std::unordered_map<int, int> m;
	for (int i = 0; i < nums.size(); ++i)
	{
		++m[nums[i]];
		if (m[nums[i]] > 1)
			return true;
	}
	return false;
}