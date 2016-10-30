#include<vector>
#include<unordered_map>
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

//��������ظ�Ԫ���أ���permutation index
//�ⷨ����:����n�����������ظ����֣���n�����������������n!/(A1! * A2! * A3! * ... * An!),A1��ʾ��һ������
//        ���ִ�����A2��ʾ�ڶ������ĳ��ִ���������һ�ⲻͬ����Ҫ��¼Ԫ�س��ֵĴ�����Ȼ��������ӵ�λ����λ��
//        
long long permutationIndexII(std::vector<int>& A) 
{
	if (A.empty()) 
		return 0;

	int n = A.size();
	std::unordered_map<int, int> map;

	long index = 0, fact = 1, mulFact = 1;
	for (int i = n - 1; i >= 0; --i) 
	{
		++map[A[i]];
		if(map[A[i]] > 1) 
			mulFact *= map[A[i]];//mulFact����(A1! * A2! * A3!...* An!)
	
		int count = 0;
		for (int j = i + 1; j < n; ++j) //�ȵ�ǰ����С�ĸ���
		{
			if (A[i] > A[j])
				++count;
		}

		index += count * fact / mulFact;//fact���ǽ׳�
		fact *= (n - i);
	}
	
	return index + 1;
}