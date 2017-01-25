//��Ŀ����:����һ��ֵn����ʾ0��10��n�η������Χ�ڵ������ҵ����з�unique digit����������n = 1��ʱ��0��9����
//        unique digit���������Է���10�� n = 2��ʱ��11,22,33��..,99��unique digit����������100 - 10 - 9
//        81
//�ⷨ����:��ѧ��ʽf(k) = 9 * 9 * 8 * ... * (11 - k)��ʾkλ���У��ж��ٸ���unique digit����,�������ÿһλ
//        �ù�ʽ�㣬������Ǿ���д����10�� 9 * 9�� 9 * 9 * 8�� 9 * 9 * 8 * 7��..

int countNumbersWithUniqueDigits(int n) 
{
	if (n == 0) 
		return 1;
	
	int result = 10, count = 9;
	for (int i = 2; i <= n; ++i) 
	{
		count *= (11 - i);
		result += count;
	}
	return result;
}