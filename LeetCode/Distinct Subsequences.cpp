#include<vector>
#include<string>

//��Ŀ���������������ַ���s��t���ҵ�s���ж��ٸ���ͬ�������к�t���
//�ⷨ��������̬�滮  ���s[i] == t[j],��ôdp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j],���s[i] != t[j], ��ôdp[i][j] = dp[i - 1][j]

int numDistinct(std::string s, std::string t)
{
	int m = s.size();
	int n = t.size();
	std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
	for (int i = 0; i < m + 1; ++i)
		dp[i][0] = 1;

	for (int i = 1; i < m + 1; ++i)
	{
		for (int j = 1; j < n + 1; ++j)
		{
			if (s[i - 1] == t[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	return dp[m][n];
}
