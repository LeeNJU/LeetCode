int trailingZeroes(int n)//2�ĸ���Զ����5�ĸ�����ֻ��Ҫ�ҵ�5�ĸ���������Ҫע��25��������������2��5,125����3��5��625һ������
{
	int result = 0;
	while (n)
	{
		result += n / 5;
		n /= 5;
	}
	return result;
}