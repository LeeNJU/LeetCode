#include<vector>
#include<algorithm>
//��Ŀ����:����һ�����飬�ҵ��������Ԫ�أ�����[1, 5, 11, 5]���������Ԫ����1������������Ԫ�ز����ڣ�����
//        ���Ԫ��
//�ⷨ����:�������飬���α����һ�󣬵ڶ���͵������Ԫ��
int thirdMax(std::vector<int>& nums) 
{
	long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;//ע������Ҫ��LONG_MIN,��Ϊ���ܺ���INT_MIN
	for (int val : nums)
	{
		if (first < val)
		{
			third = std::max(third, second);
			second = std::max(second, first);
			first = val;
		}
		else if (second < val && val < first)
		{
			third = std::max(third, second);
			second = val;
		}
		else if (third < val && val < second)
			third = val;
	}

	return third == LONG_MIN ? first : third;
}