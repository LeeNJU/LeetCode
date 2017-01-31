#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<map>

//��Ŀ����:����һ�����飬�ж������Ƿ�����ظ�Ԫ��
//�ⷨ��������hashtable
bool containsDuplicate(std::vector<int>& nums) 
{
	std::unordered_map<int, int> m;
	for (int i = 0; i < nums.size(); ++i)
	{
		++m[nums[i]];
		if (m[nums[i]] > 1)
			return true;
	}
	return false;
}

//��Ŀ����������һ�������һ��ֵk���ж��Ƿ�����ظ���Ԫ�أ������ظ�Ԫ�ص��±�֮��ܳ���k
//�ⷨ������sliding window��˼·����hashtset����i��j֮���Ԫ�أ�i��j�Ĳ����k
bool containsNearbyDuplicate(std::vector<int>& nums, int k)
{
	std::unordered_set<int> set;
	for (int i = 0, j = 0; j < nums.size(); ++j)
	{
		if (j - i > k)
			set.erase(nums[i++]);
		if (set.find(nums[j]) != set.end())
			return true;
		set.insert(nums[j]);
	}
	return false;
}

//��Ŀ����������һ�����飬�ж��Ƿ����Ԫ��A[i]��A[j]��ʹ��i��j�Ĳ����k��A[i]��A[j]�Ĳ����t
//�ⷨ��������һ��map����i��j֮���Ԫ�أ�i��j�Ĳ����k������map��lower_bound�����ҵ�nums[i] - t���Ͻ磬��
//         �Ǵ��ڵ���nums[i] - t��Ԫ�صĵ�������С�������������Ԫ����nums[i] - t�Ĳ�һ������t�������������
//         ����Ԫ����nums[i] - t�Ĳһ������t�������жϡ�

bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int k, int t)
{
	std::map<int, int> m;
	int j = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (i - j > k)//�±�֮�����k��Ҫɾ��֮ǰ��Ԫ��
		{
			m.erase(nums[j]);
			++j;
		}
		std::map<int, int>::iterator iter = m.lower_bound(nums[i] - t);
		if (iter != m.end() && abs(iter->first - nums[i]) <= t)
			return true;
		m[nums[i]] = i;
	}
	return false;
}