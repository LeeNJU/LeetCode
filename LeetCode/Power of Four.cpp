//题目描述:判断一个数是不是4的幂
//解法描述:必须是2的幂，必须是正数，从二进制表示来看，奇数位是1，例如4,0100，16是1000000,所以用0x55555555掩码

bool isPowerOfFour(int num) 
{
	int mask = 0x55555555;
	return (((num - 1) & num) == 0) && ((mask & num) == num) && num > 0;
}