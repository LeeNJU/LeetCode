#include<vector>
//��Ŀ����������һ�����飬����ÿһ����������3�Σ�ֻ��һ��������1�Σ��ҵ����ֻ����1�ε���
//�ⷨ������one��ʾ����ǰ����Ϊֹ����������1����1�ε�����Щλ��two��ʾ����ǰ����Ϊֹ����������1����2�ε�����Щλ

int singleNumber(std::vector<int>& nums) 
{
	int one = 0, two = 0, three = 0;
	for (int i = 0; i < nums.size(); ++i) 
	{
		two |= (one & nums[i]);  //two����1����2�ε�ÿһλ
		one ^= nums[i]; // one����1����1�ε�ÿһλ
		three = ~(one & two);
		one &= three; //three�г���3�ε�λ����Ϊ0����one��two����ЩλҲӦ�ñ���Ϊ0
		two &= three;
	}
	return one;
}