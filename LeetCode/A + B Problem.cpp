//题目描述:用位运算实现两个数的加法
//解法描述:关键在于处理进位，(a & b) << 1得到所有的进位，a ^ b得到加法结果(不考虑进位),再把(a & b) << 1和a ^ b进行相加，
//        直到进位为0
int aplusb(int a, int b) 
{
	while (b != 0)
	{
		int carry = a & b;
		a ^= b;
		b = carry << 1;
	}
	return a;
}