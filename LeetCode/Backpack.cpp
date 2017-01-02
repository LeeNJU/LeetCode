#include<vector>
#include<algorithm>
//题目描述:背包问题,给定一个数组和一个值w，从数组中选出几个元素，值得元素之和尽可能接近w
//解法描述:dp[i][j]表示从1到第i个元素要装满j的空间，分成两种情况，dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 
//        A[i - 1]] + A[i - 1]).如果不选择第i个元素，那么dp[i][j] = dp[i - 1][j],如果选择第i个元素,那么就是
//        dp[i - 1][j - A[i - 1]]，由于更新dp[i][j]只需要上一层的信息，可以优化空间，只需要一维数组

int backPack(int m, std::vector<int> A) 
{
	std::vector<int> dp(m + 1, 0);
	for (int i = 1; i < A.size() + 1; ++i)
	{
		for (int j = m; j >= 1; --j)
		{
			if (j - A[i - 1] < 0)//要保证j - A[i - 1] >= 0，即装得下
				dp[j] = dp[j];
			else
				dp[j] = std::max(dp[j], dp[j - A[i - 1]] + A[i - 1]);
		}
	}
	return dp[m];
}

//变种：给定n个item，每个item有重量和价值，要求重量之和不超过m，使得价值之和最大化
//解法描述:与上题类似，只是加的值变成了value
int backPackII(int m, std::vector<int> A, std::vector<int> V) 
{
	std::vector<int> dp(m + 1, 0);
	for (int i = 1; i < A.size() + 1; ++i)
	{
		for (int j = m; j >= 1; --j)
		{
			if (j - A[i - 1] < 0)//要保证j - A[i - 1] >= 0，即装得下
				dp[j] = dp[j];
			else
				dp[j] = std::max(dp[j], dp[j - A[i - 1]] + V[i - 1]);
		}
	}
	return dp[m];
}

//变种:给定n个item，每个item都有重量和价值，背包的大小为m，每个item可以多次选择，使得价值最大
//    例如重量是A = [2, 3, 5, 7]，价值是V = [1, 5, 2, 4],背包大小为10，最大价值是15 = 3 + 5 + 5
//解法:dp[j]表示背包大小为j的时候能装的最大价值，dp[j] = max(dp[j], V[i] + dp[j - A[i]])

int backPackIII(std::vector<int> A, std::vector<int> V, int m) 
{
	std::vector<int> dp(m + 1, 0);
	for (int i = 0; i < A.size(); ++i) 
	{
		for (int j = 1; j <= m; j++) 
		{
			if (j >= A[i]) 
				dp[j] = std::max(dp[j], dp[j - A[i]] + V[i]);
		}
	}
	return dp[m];
}