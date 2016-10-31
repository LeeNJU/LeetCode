//��Ŀ����:��n��Ӳ�ң��ڳ�k�У�ʹ��ÿһ�иպ���k��Ӳ�ң��������԰ڶ����У�����n = 5����һ�а�1�����ڶ��а�
//        2���������а�3����ֻ�ܰ�2��
//�ⷨ����:���ֲ��ң���Ȳ����еĺͣ�ע������Ĵ���

int arrangeCoins(int n) 
{
	if (n <= 1) 
		return n;
	
	long left = 0, right = n;
	while (left <= right)
	{
		long middle = left + (right - left) / 2;
		long sum = ((1 + middle) * middle) / 2;
		if (sum <= n)
			left = middle + 1; 
		else  
			right = middle - 1; 
	}
	return left - 1;
}