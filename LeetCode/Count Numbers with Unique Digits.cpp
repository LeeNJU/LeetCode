//题目描述:给定一个值n，表示0到10的n次方这个范围内的数，找到所有非unique digit的数，例如n = 1的时候，0到9都是
//        unique digit的数，所以返回10， n = 2的时候，11,22,33，..,99是unique digit的树，返回100 - 10 - 9
//        81
//解法描述:数学公式f(k) = 9 * 9 * 8 * ... * (11 - k)表示k位数中，有多少个飞unique digit的数,可以针对每一位
//        用公式算，下面的是精简写法：10， 9 * 9， 9 * 9 * 8， 9 * 9 * 8 * 7，..

int countNumbersWithUniqueDigits(int n) 
{
	if (n == 0) 
		return 1;
	
	int result = 10, count = 9;
	for (int i = 2; i <= n; ++i) 
	{
		count *= (11 - i);
		result += count;
	}
	return result;
}