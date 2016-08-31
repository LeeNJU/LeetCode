#include<vector>

//题目描述:给定一个值n，求出比1到n的质数的个数
//解法描述:思路是3是质数，那么3的所有倍数都不是质数，5是质数，那么5的所有倍数都不是质数

int countPrimes(int n) 
{
	std::vector<bool> isPrime(n, true); //构造一个大数组，初始化为true
	isPrime[0] = false;
	isPrime[1] = false;

	for (int i = 2; i * i < n; i++) 
	{
		if (!isPrime[i]) 
			continue;
		for (int j = i * i; j < n; j += i) //从i*i开始，例如i=5的时候，5*2,5*3,这些在前面已经计算过了，直接从i*i开始
			isPrime[j] = false;
	}

	int count = 0;
	for (int i = 2; i < n; i++) 
	{
		if (isPrime[i]) 
			count++;
	}

	return count;
}