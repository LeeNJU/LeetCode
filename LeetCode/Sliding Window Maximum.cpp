#include<vector>

//��Ŀ����������һ�������һ�����ڣ���СΪk���ô������������ƶ�һ���õ�һ���µĴ�СΪk�Ĵ��ڣ���¼ÿ�����ڵ����ֵ
//�ⷨ������
std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k)
{
	std::vector<int> result;
	int max_position = 0, int max = 0;
	for (int i = 0; i < k; ++i)
	{
		if (nums[i] > max)
		{
			max_position = i;
			max = nums[i];
		}
	}
	result.push_back(max);

	int left = 0, right = k - 1;
	for (int i = k; i < nums.size(); ++i)
	{

	}
}