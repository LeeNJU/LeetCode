#include<algorithm>
#include<vector>
//��Ŀ����������һ���Ǹ����飬ÿ��Ԫ�ر�ʾ�ܹ���ǰ��Ծ�������������������һ��Ԫ�ص���С����
//�ⷨ������̰��  ��curRch < i��˵��count��jump�Ѿ������Ը��ǵ�ǰ��i��Ԫ�أ������Ҫ����һ��jump��ʹ֮�ﵽcurMax

int jump(std::vector<int>& nums)
{
	int count = 0;//��С����
	int curMax = 0;//��ǰ�ܹ���������Χ
	int curRch = 0;//��num[0]��Ծresult�κ��ܹ��ﵽ�����Χ
	for (int i = 0; i < nums.size(); i++)
	{
		if (curRch < i)
		{
			++count;
			curRch = curMax;
		}
		curMax = std::max(curMax, nums[i] + i);
	}
	return count;
}