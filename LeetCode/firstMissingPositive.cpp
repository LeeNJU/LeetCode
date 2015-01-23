#include<algorithm>

int firstMissingPositive(int A [], int n)
{
	int index = 0;
	for (int i = 0; i < n; ++i)
	{
		if (A[i] != i + 1)
		{
			std::swap(A[i], A[++index]);
		}
	}
	return 0;
}