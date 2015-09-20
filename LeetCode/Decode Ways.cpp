#include<vector>
#include<string>

//题目描述：给定一个字符串s,找出decode的方式，"1"对应A，"12"可以被decode为"AB"或者"L"，所以有2种方式
//解法描述：动态规划，s[i] == 0的时候,
int numDecodings(std::string s) 
{
	if (s.empty())
		return 0;

	std::vector<int> dp(s.size() + 2, 0);
	dp[1] = 1;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '0')
		{
			if (i >= 0 && s[i - 1] <= '2' && s[i - 1] >= '1')
				dp[i + 2] = dp[i];
		}
		else
		{
			dp[i + 2] = dp[i + 1];
			if (i > 0 && s[i - 1] != '0' && s.substr(i - 1, 2) <= "26")
				dp[i + 2] += dp[i];
		}
	}
	return dp[s.size() + 1];
}