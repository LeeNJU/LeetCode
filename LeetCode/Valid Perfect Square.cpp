//��Ŀ����:����һ�����������ж����ǲ���һ��ƽ�������������16������true
//�ⷨ����:���ֲ��ң�ע�����

bool isPerfectSquare(int num) 
{
	if (num <= 0)
		return false;

	long left = 1, right = num, middle = (left + right) / 2;
	while (left <= right)
	{
		middle = left + (right - left) / 2;
		if (middle * middle == num)
			return true;
		else if (middle * middle < num)
			left = middle + 1;
		else
			right = middle - 1;
	}
	return false;
}