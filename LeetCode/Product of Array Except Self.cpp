#include<vector>
//��Ŀ����:nums�����һ������output��ʹ��output[i]�����������г���nums[i]֮���Ԫ�صĳ˻��������ó���
//�ⷨ����:����result[i]��ʾnums[0]��nums[i - 1]�ĳ˻���Ȼ�����ɨ�裬right��¼nums[i]��nums[n - 1]�ĳ˻���
//        
std::vector<int> productExceptSelf(std::vector<int>& nums)
{
	std::vector<int> result(nums.size(), 1);
	for (int i = 1; i < nums.size(); ++i)
		result[i] = result[i - 1] * nums[i - 1];

	int right = 1;
	for (int i = nums.size() - 1; i >= 0; --i)
	{
		result[i] *= right;
		right *= nums[i];
	}
	return result;
}