//��Ŀ��������һ��n��̨�ף�ÿ��ֻ��ǰ��һ������������һ���ж������������ķ�ʽ
//�ⷨ��������f(n)Ϊ��n��̨������ķ���������ôf(n) = f(n - 1) + 1,����f(n) = f(n - 2) + 1,������f(n) = f(n-1) + f(n-2)

int climbStairs(int n)
{
	int prev = 0, cur = 1;//cur������ʾ��ǰ̨������Ӧ�ķ�����
	for (int i = 1; i <= n; ++i)
	{
		int temp = cur;
		cur = prev + cur;
		prev = temp;
	}
	return cur;
}