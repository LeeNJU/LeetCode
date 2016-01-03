//问题描述:快速计算a的n次方对b进行取模的结果
//解法描述:利用取模运算的公式，(a * b) % p = (a % p * b % p) % p
int fastPower(int a, int b, int n) 
{
	if (n == 0)
		return 1 % b;

	if (n == 1)
		return a % b;

	long num = fastPower(a, b, n / 2); //这里要注意溢出的问题，所以用long
	num = num * num;

	num = num % b;
	if (n % 2 == 1)//考虑n的奇偶
		num = num * (a % b);

	return num % b;
}