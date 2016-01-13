//题目描述:有k种颜色，对n个杆子进行涂色，最多两个相邻杆子的颜色可以相同，求总共有多少种涂法
//解法描述:S[i]表示第i个杆子与第i - 1个杆子颜色相同，有多少种涂法，D[i]表示第i个杆子与第i - 1个杆子颜色不同，
//        有多少种涂法，那么S[i] = D[i - 1],D[i] = (k - 1) * (D[i - 1] + S[i - 1]),由于只用到前一个变量的
//        值，所以可以只用两个变量
int numWays(int n, int k) 
{
	if (n == 0 || k == 0)
		return 0;
	if (n == 1)
		return k;

	int lastD = k * (k - 1);
	int lastS = k;
	for (int i = 2; i < n; i++) 
	{
		int tempD = (k - 1) * (lastD + lastS);//lastD + lastS是上一步总共的涂法
		lastS = lastD;
		lastD = tempD;
	}

	return lastS + lastD;
}