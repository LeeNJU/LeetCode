//����һ���������飬���Ǹ�������ĳһ��λ�ñ���ת�ˣ��ڸ������в���ָ����Ԫ�أ�����array={4,5,6,1,2,3}����2
//�ⷨ�����ַ�,ע��߽磡��������target��A[middle]��A[first]�ıȽϣ���

int search(int A[], int n, int target)
{
	int first = 0, last = n - 1, middle = 0;
	while (first <= last)
	{
		middle = (first + last) / 2;
		if (A[middle] == target)
			return middle;
		if (A[middle] >= A[first])//middle����first�Ƚ�
		{
			if (A[middle] > target && target >= A[first])//ȷ��target����middle��߻����ұ�
				last = middle - 1;
			else
				first = middle + 1;
		}
		else
		{
			if (A[middle] < target && target <= A[last])//ȷ��target����middle��߻����ұ�
				first = middle + 1;
			else
				last = middle - 1;
		}
	}
	return -1;
}