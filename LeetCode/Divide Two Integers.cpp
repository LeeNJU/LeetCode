#include<string>

//题目描述:给定两个整数，进行除法操作，不能用乘法，除法或取模运算
//解法描述:排除一些特殊情况后，转换成long类型防止运算过程中出现溢出，将divisor向左移动n位，使得divisor小于
//        等于dividend，相当于divisor乘2的n次方,divident减去divisor，然后又移动divisor a位，直到divisor
//        小于等于divident，相当于divisor乘2的a次方，...把这些加起来就是结果。注意判断结果的溢出

int divide(int dividend, int divisor)
{
	if (divisor == 1)  //排除特殊情况
		return dividend;
	if (dividend == 0)
		return 0;

	int flag = 1;
	if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) //判断结果的符号
		flag = -1;

	long divide = static_cast<long>(dividend);  //强制类型转换，防止运算过程中出现溢出
	long divis = static_cast<long>(divisor);
	divide = abs(divide); // 转换成正数
	divis = abs(divis);

	int result = 0;
	while (divide >= divis)
	{
		int count = 1;
		long temp = divis;
		while ((temp <<= 1) <= divide) //temp逐渐向左移动
		{
			count = count << 1; //count向左移动，记录
		}
		result += count;
		divide -= (temp >> 1);
	}
	if (result < 0)  //判断结果是否溢出
		return INT_MAX;
	return flag * result;
}