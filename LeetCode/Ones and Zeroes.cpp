#include<vector>
#include<string>
#include<algorithm>
//题目描述:给定一个字符串数组，每个字符串都有0和1组成，给定m个0和n个1，求用这m个0和n个1能组成多少个字符串数组
//        中的字符串，例如{"10", "0001", "111001", "1", "0"}, m = 5, n = 3， 只能组成"10","0001","1","0",
//        4个字符串，返回4
//解法描述:背包问题，扫描字符串数组，统计当前字符串中0和1的个数，dp[i][j] = max(dp[i - zero][j - one] + 1,
//         dp[i][j]),dp[i][j]为不考虑当前字符串的情况，dp[i - zero][j - zero] + 1是考虑当前字符串的情况

int findMaxForm(std::vector<std::string>& strs, int m, int n) 
{
	std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

	for (const std::string& s : strs) 
	{
		int numZeroes = 0;
		int numOnes = 0;
		for (const int& c : s) 
		{
			if (c == '0')
				++numZeroes;
			else if (c == '1')
				++numOnes;
		}

		for (int i = m; i >= numZeroes; --i) //注意这里要从后往前更新dp数组
		{
			for (int j = n; j >= numOnes; --j) 
			{
				dp[i][j] = std::max(dp[i][j], dp[i - numZeroes][j - numOnes] + 1);
			}
		}
	}

	return dp[m][n];
}