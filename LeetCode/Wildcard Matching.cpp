#include<string>
#include<vector>
//��Ŀ����:ƥ���ַ���������ʾƥ���κε�һ���ַ���*��ʾƥ���������е��ַ�
//�ⷨ����:��̬�滮��dp[i][j]��ʾ���ַ���s��0��i���ܷ�ƥ���ַ���p��0��j�����p[j]����*����?,��ôdp[i][j] = 
//        dp[i - 1][j - 1] && s[i] == p[j],���p[j]����?,��ôdp[i][j] = dp[i - 1][j - 1],���p[j] == *,
//        ��ôdp[i][j] = dp[i][j - 1] || dp[i - 1][j - 1] || dp[i - 2][j - 1] ||...dp[0][j - 1].
//        ��Ϊdp[i - 1][j] = dp[i - 1][j - 1] || dp[i - 2][j - 1] || dp[i - 3][j - 1]...���Կ��Լ�Ϊ
//        dp[i][j] = dp[i][j - 1] || dp[i - 1][j]

bool isMatch(std::string s, std::string p) 
{
	if (s.empty() && p.empty())
		return true;

	int n = s.size();
	int m = p.size();
	std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(m + 1, false));

	dp[0][0] = true;
	for (int i = 1; i < n + 1; i++)//�ַ���pΪ0����ʼ��Ϊfalse
		dp[i][0] = false;

	for (int i = 1; i < m + 1; i++)
		dp[0][i] = p[i - 1] == '*' && dp[0][i - 1];


	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
		{
			if (p[j - 1] == '*')
				dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
			else if (p[j - 1] == '?')
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1]);
		}
	}

	return dp[n][m];
}