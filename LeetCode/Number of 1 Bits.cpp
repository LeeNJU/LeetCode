#include<STDINT.h>
//��Ŀ����������һ��32λ�޷����������������1�ĸ���
//�ⷨ������ѭ����λ

int hammingWeight(uint32_t n)
{
	int result = 0;
	for (int i = 0; i < 32; ++i)
	{
		if (n % 2 != 0)
			++result;
		n = n >> 1;
	}
	return result;
}