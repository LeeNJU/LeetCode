#include<vector>
#include<algorithm>
//��Ŀ����������һ�����飬ÿ��Ԫ�ر�ʾ�ܹ���ǰ��Ծ�������������ܷ���Ծ�����һ��Ԫ��
//�ⷨ������̰�ģ���¼��ǰԪ���ܹ���Ծ����Զ���룬�ж���Զ�����Ƿ�������鳤��

bool canJump(std::vector<int>& nums) //��¼ÿһ���ܹ�ǰ�������maxIndex���ж�maxIndex�Ƿ�������һ��Ԫ��
{
	if (nums.empty())
		return false;

	if (nums[0] == 0 && nums.size() == 1)
		return true;

	int max_index = 0;
	for (int i = 0; i < nums.size() && i <= max_index; ++i)
	{
		max_index = std::max(max_index, i + nums[i]);
		if (max_index >= nums.size() - 1)
			return true;
	}
	return false;
}