#include<vector>
//��Ŀ����������һ������nums�����һ������output��ʹ��output[i]�����������г���nums[i]֮���Ԫ�صĳ˻��������ó���
//�ⷨ���������������飬����left[i]��ʾnums[0]��nums[i - 1]�ĳ˻�������right[i]��ʾ����nums[i + 1]��
//         nums[nums.size() - 1]�ĳ˻����������������������
std::vector<int> productExceptSelf(std::vector<int>& nums) 
{
	std::vector<int> result(nums.size(), 0);
	std::vector<int> left(nums.size(), 1);
	std::vector<int> right(nums.size(), 1);
	for (int i = 1; i < nums.size(); ++i)
		left[i] = left[i - 1] * nums[i - 1];
	for (int i = nums.size() - 2; i >= 0; --i)
		right[i] = right[i + 1] * nums[i + 1];
	for (int i = 0; i < nums.size(); ++i)
		result[i] = left[i] * right[i];
	return result;
}