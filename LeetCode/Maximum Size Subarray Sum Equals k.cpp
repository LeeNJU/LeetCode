#include<vector>
#include<unordered_map>
#include<algorithm>
//��Ŀ����:����һ�������һ��ֵk�����������ҵ�һ����������飬ʹ�����������ĺ͵���k������:
//        nums = [1, -1, 5, -2, 3], k = 3,�����������[1, -1, 5, -2]
//�ⷨ����:��hashtable��¼����[0, i]֮���ֵ�Լ��±�

int maxSubArrayLen(std::vector<int>& nums, int k) 
{
	std::unordered_map<int, int> map;
	map[0] = -1;  //������Ϊ�˷�ֹ������Ϊk��������
	int sum = 0, max_length = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		sum += nums[i];
		if (map.find(sum - k) != map.end())
		{
			int preIndex = map[sum - k];
			max_length = std::max(max_length, i - preIndex);
		}
		if (map.find(sum) == map.end())
			map[sum] = i;
	}
	return max_length;
}
