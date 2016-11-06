//��Ŀ����������һ��ֵx���������ƽ����
//�ⷨ���������ֲ���

int sqrt(int x) 
{
	if (x == 0)
		return 0;
	if (x == 1)
		return 1;

	int left = 1, right = x;
	while (left <= right)//ѭ��������leftָ����ȷ�����һ��Ԫ��
	{
		int middle = (left + right) / 2;
		if (middle == x / middle)
			return middle;
		else if (middle < x / middle)
			left = middle + 1;
		else
			right = middle - 1;
	}

	return left - 1;
}