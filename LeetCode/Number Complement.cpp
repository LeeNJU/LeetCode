//题目描述:给定一个32位的整数，对其进行取反，例如5，二进制位101，取反之后得到010，也就是2，返回2，注意这里要
//        忽略之前的0，之前的0不用取反
//解法描述:其实就是异或操作，找到最高位的1，对于前面的leading 0不进行异或操作

int findComplement(int num) 
{
	int result = num ^ 0xffffffff;//先进行异或操作，再把前面的0还原成0
	int mask = 0;
	while (num != 0)
	{
		mask = (mask << 1) + 1;
		num = num >> 1;
	}

	return result & mask;
}