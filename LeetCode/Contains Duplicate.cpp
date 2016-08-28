#include<vector>
#include<unordered_map>
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
//�ⷨ��������hashtable������ֵͬ���±꼯�ϣ������ü��ϣ��Ƚ��±�֮��
bool containsNearbyDuplicate(std::vector<int>& nums, int k)
{
	std::unordered_map<int, std::vector<int>> m;
	for (int i = 0; i < nums.size(); ++i)
		m[nums[i]].push_back(i);//������ͬԪ�ص��±�

	for (int i = 0; i < nums.size(); ++i)
	{
		if (m[nums[i]].size() >= 2)//�±꼯�ϴ���2
		{
			for (int j = 0; j < m[nums[i]].size() - 1; ++j)//�����±꼯�ϣ��ֱ�Ƚ������±�Ĳ�
			{
				if (m[nums[i]][j + 1] - m[nums[i]][j] <= k)
					return true;
			}
		}
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