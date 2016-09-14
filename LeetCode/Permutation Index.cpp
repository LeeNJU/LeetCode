#include<vector>
//题目描述:给定一个整数数组，求出permutation index，例如[1,2,4]，返回1，[1,4,2],返回2
//解法描述:确定第一个元素，那么剩下的有(n - 1)!中组合方式
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
		for (int j = i; j < n; ++j)//剩下的元素中，比当前元素小的个数
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