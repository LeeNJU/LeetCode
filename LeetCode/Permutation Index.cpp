#include<vector>
//��Ŀ����:����һ���������飬���permutation index������[1,2,4]������1��[1,4,2],����2
//�ⷨ����:ȷ����һ��Ԫ�أ���ôʣ�µ���(n - 1)!����Ϸ�ʽ
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
		for (int j = i; j < n; ++j)//ʣ�µ�Ԫ���У��ȵ�ǰԪ��С�ĸ���
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