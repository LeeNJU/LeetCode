#include<iostream>
#include<algorithm>
using namespace std;


void mergeSortedArray(int* a, int lenA, int* b, int lenB)
{
	if (a == nullptr || b == nullptr)
		return;

	int indexA = lenA - 1, indexB = lenB - 1, cur = lenA + lenB - 1;

	while (indexA >= 0 && indexB >= 0)
	{
		a[cur--] = a[indexA] <= b[indexB] ? b[indexB--] : a[indexA--];
	}

	copy(b, b + indexB + 1, a);
}

