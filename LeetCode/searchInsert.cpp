#include<iostream>

using namespace std;

int searchInsert(int A[], int n, int target)
{
	if (A[n - 1] < target)
		return n;
	if (A[0] > target)
		return 0;

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

	if (A[middle] > target)
		return middle;
	if (A[middle] < target)
		return middle + 1;
}
