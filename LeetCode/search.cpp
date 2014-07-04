#include<iostream>

using namespace std;

int binarySearch(int A[], int first, int last, int target)
{
	int middle = 0;
	while (first <= last)
	{
		middle = (first + last) / 2;
		if (A[middle] == target)
			return middle;
		else if (A[middle] < target)
		{
			first = middle + 1;
		}
		else
			last = middle - 1;
	}

	return -1;
}

int search(int A[], int n, int target)
{
	int index = 0, result = -1;
	for (; index < n - 1; ++index)
	{
		if (A[index] > A[index + 1])
			break;
	}

	result = binarySearch(A, 0, index, target);
	if (result != -1)
		return result;

	return  binarySearch(A, index + 1, n - 1, target);
}