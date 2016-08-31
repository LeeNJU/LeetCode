#include<vector>
//��Ŀ����:����һ�����飬�ҵ��������е�����ԣ�����[2, 4, 1, 3, 5],��ô���е��������(2, 1), (4, 1), (4, 3)
//�ⷨ����:mergesort���ںϲ��Ĺ����У��������������Ԫ�ش����ұ��������Ԫ�أ�����һ������ԣ�Ҫע�⣬
//        [3,4,1,2],�ںϲ�������[3,4]��[1,2]��ʱ��4��2�󣬲���(4,2)����ԣ�ͬʱ(4,1)Ҳ������ԣ�
long long merge(std::vector<int>& A, int p, int middle, int q)
{
	long long count = 0;
	std::vector<int> vec(q - p + 1, 0);
	int index = vec.size() - 1;

	int indexA = middle, indexB = q;
	while (indexA >= p && indexB >= middle + 1)
	{
		if (A[indexA] > A[indexB])
		{
			count += indexB - middle;//indexB֮���Ԫ����indexAҲ���γ������
			vec[index--] = A[indexA--];
		}
		else
			vec[index--] = A[indexB--];
	}

	while (indexA >= p)
		vec[index--] = A[indexA--];

	while (indexB >= middle + 1)
		vec[index--] = A[indexB--];

	copy(vec.begin(), vec.end(), A.begin() + p);
	return count;
}
long long mergeSort(std::vector<int>& A, int p, int q)
{
	long long count = 0;
	if (p < q)
	{
		int middle = (p + q) / 2;
		count += mergeSort(A, p, middle);
		count += mergeSort(A, middle + 1, q);
		count += merge(A, p, middle, q);
	}
	return count;
}
long long reversePairs(std::vector<int>& A) 
{
	return mergeSort(A, 0, A.size() - 1);
}