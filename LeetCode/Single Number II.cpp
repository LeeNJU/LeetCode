#include<vector>
//��Ŀ����������һ�����飬����ÿһ����������3�Σ�ֻ��һ��������1�Σ��ҵ����ֻ����1�ε���
//�ⷨ������one��ʾ����ǰ����Ϊֹ����������1����1�ε�����Щλ��two��ʾ����ǰ����Ϊֹ����������1����2�ε�����Щλ

int singleNumber(std::vector<int>& nums) 
{
	int one = 0, two = 0, three = 0;
	for (int i = 0; i < nums.size(); ++i) 
	{
		two |= (one & nums[i]);
		one ^= nums[i];
		three = ~(one & two);
		one &= three;
		two &= three;
	}
	return one;
}