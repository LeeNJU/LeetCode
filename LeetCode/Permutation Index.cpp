#include<vector>

long long permutationIndex(std::vector<int>& A) 
{
	long result = 0;
	int n = A.size();
	long factorial = 1;
	for (int i = 1; i < n; ++i)
		factorial *= i;

	int initial = n - 1;
	for (int i = 0; i < n - 1; ++i)
	{
		long count = 0;
		for (int j = i; j < n; ++j)
		{
			if (A[j] < A[i])
				++count;
		}

		result += count * factorial;
		factorial /= initial;
		--initial;
	}

	return result + 1;
}