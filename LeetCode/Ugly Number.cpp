#include<vector>
#include<algorithm>
//题目描述：ugly number是指只能被2，3和5整除的数，判断一个数是不是ugly number，1是ugly number
//解法描述：不停的用2，3和5去除，如果发现除了2，3和5的约数，就不是ugly number
bool isUgly(int num) 
{
	if (num <= 0)
		return false;

	while (num > 1)
	{
		if (num % 2 == 0)
			num /= 2;
		if (num % 3 == 0)
			num /= 3;
		if (num % 5 == 0)
			num /= 5;
		if (num != 1 && num % 2 != 0 && num % 3 != 0 && num % 5 != 0)
			return false;
	}
	return true;
}

//变种2:求出第n个ugly number
//解法描述:找出生成ugly number的规律，一个ugly number都是由一个较小的ugly number乘以2，3或5得到，index2，
//         index3和index5用来表示前一个较小的ugly number
int nthUglyNumber(int n) 
{
	std::vector<int> result(n, 0);
	int index2 = 0, index3 = 0, index5 = 0;
	result[0] = 1;
	for (int i = 1; i < n; i++)
	{
		result[i] = std::min(std::min(result[index2] * 2, result[index3] * 3), result[index5] * 5);
		if (result[i] == result[index2] * 2) //注意这里，不能用if else，因为当前最小的ugly number可能
			++index2;                        //乘以2，3或者5同时得到
		if (result[i] == result[index3] * 3) 
			++index3;
		if (result[i] == result[index5] * 5) 
			++index5;
	}
	return result[n - 1];
}

//version 3:super ugly number
//题目描述:给定一个因数数组，找到第n个以这些数字为因数的ugly number
//解法描述:解法相似，不过因数个数为k，需要用数组保存每一个因数的下标

int nthSuperUglyNumber(int n, std::vector<int>& primes)
{
	std::vector<int> index(primes.size(), 0);
	std::vector<int> result(n,1);

	for (int i = 1; i < n; ++i)
	{
		int num = INT_MAX;
		for (int j = 0; j < primes.size(); ++j)//找到最小值
			num = std::min(num, result[index[j]] * primes[j]);

		for (int j = 0; j < primes.size(); ++j)//更新得到最小值的下标
		{
			if (result[index[j]] * primes[j] == num)
				++index[j];
		}
		result[i] = num;
	}
	return result[n - 1];
}