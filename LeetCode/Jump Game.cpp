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

//��Ŀ����:����һ���Ǹ����飬ÿ��Ԫ�ر�ʾ�ܹ���ǰ��Ծ�������������������һ��Ԫ�ص���С����
//�ⷨ����:̰��,��last < i��˵��count��jump�Ѿ������Ը��ǵ�ǰ��i��Ԫ�أ������Ҫ����һ��jump��ʹ֮�ﵽ
//        cur

int jump(std::vector<int>& nums)
{
	int count = 0;//��С����
	int last = 0;//��һ������ĸ��Ƿ�Χ
	int cur = 0;//Ŀǰ�ܹ���������Χ
	for (int i = 0; i < nums.size(); i++)
	{
		if (last < i)
		{
			++count;
			last = cur;
		}
		cur = std::max(cur, nums[i] + i);
	}
	return count;
}