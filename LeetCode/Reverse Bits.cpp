#include<stdint.h>
//��Ŀ����������һ��32λ���޷��������������������λ��ת������������Ķ����Ʊ�ʾ��ת
//�ⷨ������ÿ��ȡ�������������һλ������λ���뵽�����ɵ��������ұ�
uint32_t reverseBits(uint32_t n)
{
	uint32_t result = 0;
	for (int i = 1; i <= 32; ++i)
	{
		result = (result << 1) + (n & 1);
		n = n >> 1;
	}
	return result;
}