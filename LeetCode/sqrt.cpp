//��Ŀ����������һ��ֵx���������ƽ����
//�ⷨ���������ֲ��ң���1��x/2�ķ�Χ��ע��Ҫ��¼��һ��middle��ֵ����Ϊ��һ��middle��ֵ���ܲ���Ҫ����һ��middle��ֵ��������

int sqrt(int x) 
{
	int left = 1, right = x / 2;//��Χ��1��x/2
	int middle = (left + right) / 2;
	int last_mid = middle; // ��¼���һ��mid
	
	if (x < 2) 
		return x;
	
	while (left <= right) 
	{
		middle = (right + left) / 2;
		if (x / middle > middle) // ��Ҫ��x > mid * mid�������
		{
			left = middle + 1;
			last_mid = middle;
		}
		else if (x / middle < middle) 
		{
			right = middle - 1;
		}
		else 
		{
			return middle;
		}
	}
	return last_mid;
}