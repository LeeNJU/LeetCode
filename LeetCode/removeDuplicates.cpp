//��Ŀ��������һ���������飬ɾ�����е��ظ�Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Σ����������鳤��
//�ⷨ��index��ʾ���±꣬i=1��ʼ�������飬���A[index]������A[i]
int removeDuplicates(int A [], int n)
{
	if (n == 0)
		return 0;

	int index = 0;
	for (int i = 1; i < n; ++i)//��i=1��ʼ����
	{
		if (A[index] != A[i])
		{
			A[++index] = A[i];//ע����++index
		}
	}
	return index + 1;
}