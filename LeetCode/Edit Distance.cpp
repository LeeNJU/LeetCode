#include<vector>
#include<string>
#include<algorithm>

//��Ŀ���������������ַ���word1��word2���������ֲ�����ɾ��һ���ַ����滻һ���ַ�������һ���ַ������ʰ�word1ת����word2������Ҫ���ٲ�����
//�ⷨ��������̬�滮�����word1[i] == word2[j],��ôdp[i][j] = dp[i - 1][j - 1], ���word1[i] != word2[j],dp[i][j]����dp[i - 1][j],dp[i][j - 1]
//dp[i - 1][j - 1]����Сֵ�ټ�1��������ֵ�ֱ�������ֲ���

int minDistance(std::string word1, std::string word2)
{
	int m = word1.size();
	int n = word2.size();
	std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
	for (int i = 0; i < dp.size(); ++i)
		dp[i][0] = i;
	for (int i = 0; i < n + 1; ++i)
		dp[0][i] = i;

	for (int i = 1; i < m + 1; ++i)
	{
		for (int j = 1; j < n + 1; ++j)
		{
			if (word1[i - 1] == word2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = std::min(std::min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
		}
	}
	return dp[m][n];
}