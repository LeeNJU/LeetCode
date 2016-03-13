#include<vector>
#include<algorithm>
#include<limits.h>
#include<numeric>
//题目描述:给定一个数组和一个k值，表示复印每本书的时间，现在把这些书分给k个人去复印，每个人分到连续的几本书，
//        复印的时间为每本书的复印时间的和。现在要求复印书的最短时间
//解法描述:动态规划，dp[i][j]表示把下标0到j的书分给i个人去复印的最短时间。dp[i][j] = min(dp[i - 1][j - 1],
//        m),m表示把第j个元素加入之后的最优解。通常需要另一个循环来找到这个最优解。但是可以进行优化。

int copyBooks(std::vector<int>& pages, int k) 
{
	int n = pages.size();
	k = std::min(n, k); //k可能远大于n
	std::vector<int> sum_from_start(n, 0);//sum_from_start[i]表示数组从下标0到i的和
	partial_sum(pages.begin(), pages.end(), sum_from_start.begin());
	std::vector<std::vector<int> > minutes(k + 1, std::vector<int>(n, INT_MAX));
	
	for (int i = 0; i < n; ++i) //初始化
		minutes[1][i] = sum_from_start[i];
	
	for (int i = 2; i <= k; i++) 
	{
		minutes[i][0] = sum_from_start[1];
		int left = 0, right = 1;
		while (right < n) 
		{
			int curr = sum_from_start[right] - sum_from_start[left];
			minutes[i][right] = std::min(std::max(curr, minutes[i - 1][left]), minutes[i][right]);
			if (left < right && minutes[i - 1][left] < curr)//遍历可能的left，找到当前的最优解
				++left;
			else 
			{
				++right;//当前最优解找到，right向右移动
				if (left > 0) 
					--left;
			}
		}
	}
	return minutes[k][n - 1];
}
