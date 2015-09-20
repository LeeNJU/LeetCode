#include<vector>
#include<string>

//��Ŀ����������һ���ַ���s,�ҳ�decode�ķ�ʽ��"1"��ӦA��"12"���Ա�decodeΪ"AB"����"L"��������2�ַ�ʽ
//�ⷨ��������̬�滮��s[i] == 0��ʱ��,
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