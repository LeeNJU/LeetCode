//��Ŀ����������һ�������һ��ֵ��ɾ�������к͸�ֵ��ȵ�Ԫ�ز�����ɾ��������鳤��
//�ⷨ��index��¼�µ������±꣬i�������飬A[index]��A[i]������Ԫ���ǲ���Ҫɾ����Ԫ�أ�index++�������ȣ�i++��index����

int removeElement(int A [], int n, int elem)
{
	int index = 0;
	for (int i = 0; i < n; ++i)
	{
		if (A[i] != elem)
		{
			A[index++] = A[i];
		}
	}
	return index;
}