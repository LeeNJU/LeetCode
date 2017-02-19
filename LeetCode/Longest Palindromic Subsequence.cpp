#include<string>
#include<vector>
#include<algorithm>
//��Ŀ����:����һ���ַ������ҵ���Ļ��������еĳ��ȣ�����"bbbab"����Ļ�����������"bbbb"
//�ⷨ����:��̬�滮��dp[i][j]��ʾ����[i,j]֮����Ļ��������У����s[i] == s[j]����ô
//        dp[i][j] = dp[i + 1][j - 1] + 2.���s[i] != s[j],��ôdp[i][j] = max(dp[i + 1][j], dp[i][j - 1])
//        ����dp[i][i]��ʼ��Ϊ1

int longestPalindromeSubseq(std::string s) 
{
	int n = s.size();
	std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

	for (int length = 1; length <= n; ++length)
	{
		for (int i = 0; i + length - 1 < n; ++i)
		{
			int j = i + length - 1;
			if (i == j)
				dp[i][j] = 1;
			else if (s[i] == s[j])
				dp[i][j] = dp[i + 1][j - 1] + 2;
			else
				dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);
		}
	}
	return dp[0][n - 1];
}