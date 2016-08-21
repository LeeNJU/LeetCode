#include<vector>
//题目描述:给定一个数字n,返回从0到n之间所有数的二进制表示中包含的1的个数，例如n = 5, 返回[0,1,1,2,1,2]
//解法描述:数字i的1个数，等于i & (i - 1)中1的个数加1，例如i = 0110，i - 1 = 0101，i & (i - 1) = 0100,
//        因为i & (i - 1)把i中最右边的1变成了0，所以要加1.

std::vector<int> countBits(int num) 
{
	std::vector<int> result(num + 1, 0);
	for (int i = 1; i <= num; ++i)
		result[i] = result[i & (i - 1)] + 1;
	return result;
}