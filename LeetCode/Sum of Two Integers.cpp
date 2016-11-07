//题目描述:给定两个数a和b，计算他们的和，不能直接使用+和-
//解法描述:位运算

int getSum(int a, int b) 
{
	while (b != 0)
	{
		int carry = a & b;//先与操作，得到进位
		a ^= b; //异或操作
		b = carry << 1;
	}
	return a;
}