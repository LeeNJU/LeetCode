#include<vector>
#include<unordered_map>
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

//如果包含重复元素呢，求permutation index
//解法描述:给定n个数，包含重复数字，这n个数的排列组合数是n!/(A1! * A2! * A3! * ... * An!),A1表示第一个数的
//        出现次数，A2表示第二个数的出现次数。与上一题不同的是要记录元素出现的次数，然后相除。从低位到高位，
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
			mulFact *= map[A[i]];//mulFact就是(A1! * A2! * A3!...* An!)
	
		int count = 0;
		for (int j = i + 1; j < n; ++j) //比当前数字小的个数
		{
			if (A[i] > A[j])
				++count;
		}

		index += count * fact / mulFact;//fact就是阶乘
		fact *= (n - i);
	}
	
	return index + 1;
}