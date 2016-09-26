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

//��Ŀ����:����һ�����飬����ÿһ����������3�Σ�ֻ��һ��������1�Σ��ҵ����ֻ����1�ε���
//�ⷨ����:one��ʾ����ǰ����Ϊֹ����������1����1�ε�����Щλ��two��ʾ����ǰ����Ϊֹ����������1����2�ε�
//         ����Щλ

int singleNumber2(std::vector<int>& nums)
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

//��Ŀ����������һ�����飬������������ֻ����һ�Σ���������������Σ��ҵ���������
//�ⷨ�������ȶ����е����������������õ��Ľ������x��y�������Ľ��������x��y��������ȣ�����б�Ȼ��һλ
//         ����1,���ұ߿�ʼ�ң��ҵ�����1����һλ��Ȼ���Դ˰������е����ֳ��������֣�x��y�ֱ��������������У�
//         �����������ֵ���������򣬵õ�x��y

std::vector<int> singleNumber3(std::vector<int>& nums)
{
	std::vector<int> result(2, 0);
	int n = 0;
	for (int i = 0; i < nums.size(); ++i)//���е������������������Ľ��Ϊx��y�������Ľ��
		n ^= nums[i];

	int index = 0; //���ұ߿�ʼ�ҵ�һ��Ϊ1��λ
	while (n % 2 == 0)
	{
		n = n >> 1;
		++index;
	}
	for (int i = 0; i < nums.size(); ++i)//������һλ�Ƿ�Ϊ1������ֳ���������
	{
		if ((nums[i] >> index) % 2 == 0)
			result[0] ^= nums[i];
		else
			result[1] ^= nums[i];
	}
	return result;
}