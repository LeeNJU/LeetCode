//��Ŀ����:����һ��32λ���������������ȡ��������5��������λ101��ȡ��֮��õ�010��Ҳ����2������2��ע������Ҫ
//        ����֮ǰ��0��֮ǰ��0����ȡ��
//�ⷨ����:��ʵ�������������ҵ����λ��1������ǰ���leading 0������������

int findComplement(int num) 
{
	int result = num ^ 0xffffffff;//�Ƚ������������ٰ�ǰ���0��ԭ��0
	int mask = 0;
	while (num != 0)
	{
		mask = (mask << 1) + 1;
		num = num >> 1;
	}

	return result & mask;
}