//����һ�������һ��target�����������ҵ�target���������±꣬��������в�����target���򷵻ؿ��Բ����Ԫ�ص�λ�õ��±�
//�ⷨ�����ַ����ҽ���������ҵ���Ԫ����ɹ����أ����û���ҵ���Ԫ�أ�firstָ��ò����λ��

int searchInsert(int A[], int n, int target)
{
	int first = 0, last = n - 1, middle = 0;
	while (first <= last)
	{
		middle = (first + last) / 2;
		if (A[middle] == target)
			return middle;
		else if (A[middle] < target)
			first = middle + 1;
		else
			last = middle - 1;
	}
	return first;
}
