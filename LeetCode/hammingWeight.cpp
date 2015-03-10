#include<STDINT.h>
//题目描述：给定一个32位无符号整数，算出其中1的个数
//解法描述：循环移位

int hammingWeight(uint32_t n)
{
	int result = 0;
	for (int i = 0; i < 32; ++i)
	{
		if (n % 2 != 0)
			++result;
		n = n >> 1;
	}
	return result;
}