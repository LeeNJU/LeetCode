#include<limits.h>
//题目描述：给定一个整数，把这个整数反转，123->321
//解法描述：依次去最后一位进行反转，注意两点：result可能会溢出，要进行判断，其次当x=INT_MIN时要单独处理
int reverse(int x)
{
	if (x == INT_MIN)//单独处理，因为-INT_MIN会溢出
		return 0;
	int result = 0;
	int value = x > 0 ? x : -x;
	while (value)
	{
		int temp = value % 10;
		if (result > INT_MAX / 10 || (result == INT_MAX / 10 && temp > INT_MAX % 10))//检查溢出
			return 0;
		result = result * 10 + temp;
		value /= 10;
	}
	return x > 0 ? result : -result;
}