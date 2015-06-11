#include<stdint.h>
//题目描述：给定一个32位的无符号整数，把这个整数按位反转，即把这个数的二进制表示反转
//解法描述：每次取这个整数的最右一位，把这位加入到新生成的数的最右边
uint32_t reverseBits(uint32_t n)
{
	uint32_t result = 0;
	for (int i = 1; i <= 32; ++i)
	{
		result = (result << 1) + (n & 1);
		n = n >> 1;
	}
	return result;
}