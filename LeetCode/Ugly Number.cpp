//��Ŀ������ugly number��ָֻ�ܱ�2��3��5�����������ж�һ�����ǲ���ugly number��1��ugly number
//�ⷨ��������ͣ����2��3��5ȥ����������ֳ���2��3��5��Լ�����Ͳ���ugly number
bool isUgly(int num) {
	if (num <= 0)
		return false;

	while (num > 1)
	{
		if (num % 2 == 0)
			num /= 2;
		if (num % 3 == 0)
			num /= 3;
		if (num % 5 == 0)
			num /= 5;
		if (num != 1 && num % 2 != 0 && num % 3 != 0 && num % 5 != 0)
			return false;
	}
	return true;
}