#include<vector>
#include<algorithm>
//��Ŀ����:����һ��û���ظ�Ԫ�ص����������ϣ���������Ӽ���ʹ���Ӽ��е�Ԫ���ܹ�������������������[1,2,4,8],
//        ����[1,2,4,8],��Ϊ���������Ԫ�ض��ܹ���������������[1,2,3],����[1,2]����[1,3]
//�ⷨ����:��̬�滮�����ҵ�����Ӽ��Ĵ�С��Ȼ��������յĽ���Ӽ���dp[i] = max(dp[j] + 1, dp[i]), 0 <= j < i,
//        ��parent�����¼ÿ���������ż����е�ǰһ��Ԫ�ء�
std::vector<int> largestDivisibleSubset(std::vector<int>& nums) 
{
	if (nums.size() < 2)
		return nums;

	sort(nums.begin(), nums.end()); //������

	int max_length = 1;
	int max_index = 0;
	std::vector<int> dp(nums.size(), 1);
	std::vector<int> parent(nums.size(), 0);
	for (int i = 1; i < nums.size(); ++i)
	{
		int index = i; //index��ʾ�ֲ����Ž��ǰһ��Ԫ�ص��±�
		for (int j = 0; j < i; ++j)
		{
			if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i])
			{
				index = j;
				dp[i] = dp[j] + 1;
			}
		}
		if (dp[i] > max_length)//����ȫ�����Ž��Լ�ȫ�����Ž������һ��Ԫ�ص��±�
		{
			max_length = dp[i];
			max_index = i;
		}
		parent[i] = index;
	}

	std::vector<int> result;
	while (parent[max_index] != max_index) //�������Ž�
	{
		result.push_back(nums[max_index]);
		max_index = parent[max_index];
	}
	result.push_back(nums[max_index]);
	return result;
}