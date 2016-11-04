#include<vector>
#include<string>

//题目描述:给定一个字符串s,找出decode的方式，"1"对应A，"12"可以被decode为"AB"或者"L"，所以有2种方式
//解法描述:动态规划，s[i] == '0'的时候,不能被单独decode，必须前面是1或者2才能被decode.所以是dp[i + 2] = 
//        dp[i],如果s[i] != '0',可以被单独decode,dp[i + 2] = dp[i + 1], 这时还要看当前元素是不是能和前一
//        个元素构成合理的decode方式,所以还要再加上dp[i + 2] += dp[i]
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
			if (i > 0 && s[i - 1] <= '2' && s[i - 1] >= '1') //0前面必须是1或者2才能被decode
				dp[i + 2] = dp[i];
		}
		else
		{
			dp[i + 2] = dp[i + 1];
			if (i > 0 && s[i - 1] != '0' && s.substr(i - 1, 2) <= "26")//前面一个元素不能是0
				dp[i + 2] += dp[i];
		}
	}
	return dp[s.size() + 1];
}