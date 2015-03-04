//题目描述：有一个n级台阶，每次只能前进一步或两步，求一共有多少种爬到顶的方式
//解法描述：设f(n)为爬n级台阶所需的方法数，那么f(n) = f(n - 1) + 1,或者f(n) = f(n - 2) + 1,所以有f(n) = f(n-1) + f(n-2)

int climbStairs(int n)
{
	int prev = 0, cur = 1;//cur用来表示当前台阶数对应的方法数
	for (int i = 1; i <= n; ++i)
	{
		int temp = cur;
		cur = prev + cur;
		prev = temp;
	}
	return cur;
}

//自己的版本：
/*
int climbStairs(int n)
{
	if (n == 1 || n == 2)
		return n;

	int prev = 1, cur = 2;
	for (int i = 3; i <= n; ++i)
	{
		int temp = cur;
		cur = prev + cur;
		prev = temp;
	}
	return cur;
}*/