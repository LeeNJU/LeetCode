#include<vector>
#include<numeric>
//��Ŀ����:����һ��δ�������飬��������ʹ�������������:num[0]<=num[1]>=num[2]<=num[3]...
//�ⷨ����:ɨ��һ�飬�����ǰԪ�ز�������ɣ�����ǰһ��Ԫ�ؽ���������num[i]��num[i - 1]
void wiggleSort(std::vector<int>& nums) 
{
	int n = nums.size();
	for (int i = 1; i < n; ++i)
	{
		if (((i % 2 == 1) && nums[i] < nums[i - 1]) || ((i % 2 == 0) && nums[i] > nums[i - 1]))
			std::swap(nums[i], nums[i - 1]);
	}
}