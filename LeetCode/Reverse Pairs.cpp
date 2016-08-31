#include<vector>
//题目描述:给定一个数组，找到其中所有的逆序对，例如[2, 4, 1, 3, 5],那么所有的逆序对是(2, 1), (4, 1), (4, 3)
//解法描述:mergesort，在合并的过程中，如果左边子数组的元素大于右边子数组的元素，就是一个逆序对，要注意，
//        [3,4,1,2],在合并子数组[3,4]和[1,2]的时候，4比2大，产生(4,2)逆序对，同时(4,1)也是逆序对！
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
			count += indexB - middle;//indexB之后的元素与indexA也会形成逆序对
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