//��Ŀ��������һ���������飬ɾ�����е��ظ�Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Σ����������鳤��
//�ⷨ��index��ʾ���±꣬i=1��ʼ�������飬���A[index]������A[i]
int removeDuplicate(int A [], int n)
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

//�汾��������һ���������飬ɾ�����е��ظ�Ԫ�أ�ʹ��ÿ��Ԫ�����������Σ������س���
//�ⷨ�����������ƣ���һ��������¼����
int removeDuplicates(int A [], int n)
{
	if (n == 0)
		return 0;

	int occur = 1, index = 0;
	for (int i = 1; i < n; ++i)//��i=1��ʼ
	{
		if (A[index] == A[i])//�ж��Ƿ����
		{
			if (occur < 2)//�жϳ��ֵĴ���
			{
				A[++index] = A[i];
				++occur;
			}
		}
		else
		{
			A[++index] = A[i];
			occur = 1;
		}
	}
	return index + 1;
}