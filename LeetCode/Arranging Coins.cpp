//题目描述:给n个硬币，摆成k行，使得每一行刚好有k个硬币，问最多可以摆多少行，例如n = 5，第一行摆1个，第二行摆
//        2个，第三行摆3个，只能摆2行
//解法描述:二分查找，算等差数列的和，注意溢出的处理

int arrangeCoins(int n) 
{
	if (n <= 1) 
		return n;
	
	long left = 0, right = n;
	while (left <= right)
	{
		long middle = left + (right - left) / 2;
		long sum = ((1 + middle) * middle) / 2;
		if (sum == n)
			return middle;
		else if (sum < n)
			left = middle + 1; 
		else  
			right = middle - 1; 
	}
	return left - 1;
}