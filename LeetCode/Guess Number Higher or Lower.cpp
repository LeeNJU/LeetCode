#include<vector>
#include<algorithm>
//题目描述:给定一个数字n，在1到n之间进行猜数游戏，每猜一个数字会给出高了还是低了的结果，直到最后猜中。但是每
//        猜错一次，就要给相应的钱，现在要求能够保重猜中的最少的钱数。例如1到10，正确数字是8，第一次猜5，低了
//        损失5，第二次猜7，低了，损失7， 第三次猜9，高了，损失9，第四次猜8，正确。最后一共付出5 + 7 + 9 = 21
//解法描述:动态规划，dp[i][j]表示要猜中区间[i,j]中的数字所需要的钱，遍历i到j中的所有可能性，例如猜k，有三种
//        情况，第一种猜中了，不用付钱，那么正确数字可能在[i, k - 1]或者[k + 1, j],那么猜k保证要赢的钱一共
//        是三种情况中的最大值，k + max(dp[i, k - 1], dp[k + 1, j])，对i到j中的每一个k进行遍历，取最小值。
//        dp[i][j] = min(dp[i][j], k + max(dp[i,k - 1], dp[k + 1, j])), i <= k <= j;

int getMoneyAmount(int n)
{
	std::vector<std::vector<int>> dp(n, std::vector<int>(n, INT_MAX));
	for (int i = 0; i < n; ++i)//这里要初始化为0
		dp[i][i] = 0;

	for (int len = 1; len < n; ++len)//必须从长度为1的区间遍历到长度为2的区间，长度为3的区间....
	{                                //否则dp数组中可能有些值是INT_MAX，参与计算之后会变成负数
		for (int i = 0; i + len < n; ++i)
		{
			int j = i + len;
			for (int k = i; k <= j; ++k)
			{
				if (k == i)
					dp[i][j] = std::min(dp[i][j], k + dp[k + 1][j] + 1); //注意这里要加1，因为用的是下标
				else if (k == j)
					dp[i][j] = std::min(dp[i][j], k + dp[i][k - 1] + 1);
				else
					dp[i][j] = std::min(dp[i][j], k + std::max(dp[i][k - 1], dp[k + 1][j]) + 1);
			}
		}
	}
	return dp[0][n - 1];
}