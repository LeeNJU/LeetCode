//��Ŀ���������������������飬�����Ǻϲ�
//�ⷨ���ֱ���������������飬���ΰ����ķŵ����棬ע�����������Ҫ�ж��Ƿ���ʣ���Ԫ��

void merge(int A [], int m, int B [], int n)
{
	int ia = m - 1, ib = n - 1, i = m + n - 1;
	while (ia >= 0 && ib >= 0)
		A[i--] = A[ia] >= B[ib] ? A[ia--] : B[ib--];

	while (ib >= 0)
		A[i--] = B[ib--];
}