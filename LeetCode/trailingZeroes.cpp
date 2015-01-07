int trailingZeroes(int n)//2的个数远多于5的个数，只需要找到5的个数，其中要注意25这种数，包含了2个5,125包含3个5，625一次类推
{
	int result = 0;
	while (n)
	{
		result += n / 5;
		n /= 5;
	}
	return result;
}