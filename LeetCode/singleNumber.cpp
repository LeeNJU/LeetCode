#include<vector>
//��Ŀ����:����һ�����飬�����е�Ԫ�ض������2�Σ�ֻ������һ��Ԫ��ֻ����1�Σ��ҳ����Ԫ��
//�ⷨ�ⷨ:��ÿ��Ԫ�ؽ�������������Ϊ����2�ε�Ԫ�ؽ������֮��ÿһλ����0������ʣ�µ�Ԫ�ؽ������
//        ������䣬���ս��������

int singleNumber(std::vector<int>& nums) 
{
	int result = 0;
	for (int i = 0; i < nums.size(); ++i)
		result ^= nums[i];
	return result;
}