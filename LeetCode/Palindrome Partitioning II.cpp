#include<string>
#include<vector>
#include<algorithm>
//��Ŀ����������һ���ַ���s�����������иʹ��ÿ�����ֶ���palindrome������С���и���
//�ⷨ��������̬�滮��dp[i]��ʾ��0��i���ַ�������С�и�����dp[i] = min(dp[j] + 1, dp[i])���j + 1��i��palindrome�Ļ���
//         �ؼ����ж�j + 1��i�Ƿ���palindromeҲ��Ҫ��̬�滮������ʱ��matrix[j][i]��ʾ��j��i�Ƿ���palindrome��
//         �ж��Ƿ���palindrome:���s[i] == s[j]����i��j�Ĳ����1������matrix[j + 1][i - 1]Ϊtrue

int minCut(std::string s)
{
	std::vector<int> dp(s.size() + 1, s.length());
	dp[0] = -1;//��һ��Ԫ�س�ʼ��Ϊ-1
	std::vector<std::vector<bool>> matrix(s.length(), std::vector<bool>(s.length(), false));
	for (int i = 0; i < s.size(); ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			if ((s[i] == s[j] && i - j <= 1) || (s[i] == s[j] && matrix[j + 1][i - 1]))//j��iΪ���ģ���ʾ���Ը���
			{
				matrix[j][i] = true;
				dp[i + 1] = std::min(dp[j] + 1, dp[i + 1]);
			}
		}
	}
	return dp[s.size()];
}