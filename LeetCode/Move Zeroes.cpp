#include<vector>
//��Ŀ����������һ�����飬���а������ɸ�0��Ҫ������е�0�ŵ�����ĩβ�����ұ��ַ�0Ԫ�ص����˳�򲻱�
//�ⷨ�������������飬����һ��0�����ҵ�����Ԫ���еķ�0Ԫ�ز���֮����
void moveZeroes(std::vector<int>& nums) 
{
	for (int i = -1, j = 0; j < nums.size(); ++j)
	{
		if (nums[j] != 0)
			std::swap(nums[++i], nums[j]);
	}
}