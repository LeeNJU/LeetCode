#include<vector>
#include<unordered_map>

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