//��Ŀ����:����һ����n���ж�������ǲ���palindrome������121��palindrome
//�ⷨ����:��������ֵĳ��ȣ��Ա��������ߵ����֣�Ȼ������ȡ����ߺ����ұߵ����ֽ��бȽ�

bool isPalindrome(int x)//��ȡ�����ֵĳ��ȣ���һ��ȥ����ߺ����ұߵ����ֱȽϣ�Ȼ��ȡ������ߺ����ұߵ�����
{
	if (x < 0)
		return false;
	if (x == 0)
		return true;

	int length = 1;
	while (x / 10 >= length) //��x����10�ķ�ʽ���Ƚϣ���ֹlength��ֵԽ�磬  ע��x����10��100�ȵ����
		length *= 10;

	while (length > 1)
	{
		int left = x / length;
		int right = x % 10;
		if (left != right)
			return false;
		x %= length;
		x /= 10;
		length /= 100;
	}
	return true;
}
