#include<iostream>

using namespace std;

void swap(int* A, int indexOne, int indexTwo)
{
	int temp = A[indexOne];
	A[indexOne] = A[indexTwo];
	A[indexTwo] = temp;
}

void sortColors(int A[], int n)
{
	if (n <= 1)
		return;

	int indexOne = 0, indexTwo = n - 1;
	for (int i = 0; i < n && i <= indexTwo && indexTwo >= indexOne; ++i)
	{
		if (A[i] == 2)
		{
			if (i != indexTwo)
				swap(A, i, indexTwo--);
			else
				continue;
		}
		else if (A[i] == 0)
		{
			if (i != indexOne)
				swap(A, indexOne++, i);
			else
				continue;
		}
		else
			;
		if (A[i] != 1 && i >= indexOne && indexTwo >= i)
			--i;
	}
}
