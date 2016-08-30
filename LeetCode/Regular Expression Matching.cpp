#include<string>
#include<vector>
//��Ŀ����:ƥ���ַ���.��*��.��ʾ���ⵥһ�ַ���*��ʾǰһ���ַ�����0�λ���,����s="aab", p="c*a*b",����true
//        ��Ϊbƥ��һ�Σ�aƥ�����Σ�cƥ��0��
//�ⷨ����:��̬�滮��dp[i][j]��ʾs��[0,i]�Ƿ�ƥ��p��[0,j],���p[j]���ַ�,��ôdp[i][j] = dp[i - 1][j - 1]
//        && s[i] == p[j],���p[j]��.,��ôdp[i][j] = dp[i - 1][j - 1],���p[j] == *,�ַּ�����������
//        p[j - 1] == .����p[j - 1] == s[i],��ôdp[i][j] = dp[i][j - 2](ƥ��0��) || dp[i][j - 1](ƥ��
//        1��) || dp[i - 1][j](ƥ����)

bool isMatch(std::string s, std::string p)
{
	int m = s.length(), n = p.length();
	std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));
	dp[0][0] = true;

	//��ʼ����0��,����[0][0]ȫΪfalse����ӹ���ɣ���Ϊ�մ�pֻ��ƥ��մ�������������ƥ��
	for (int i = 1; i < m + 1; i++)
		dp[i][0] = false;
	//��ʼ����0�У�ֻ��X*��ƥ��մ��������*��������ֵһ����p[0][j-2]����ͬ���Թ���֮ǰ�ķ��ţ�
	for (int j = 1; j < n + 1; j++)
		dp[0][j] = j > 1 && '*' == p[j - 1] && dp[0][j - 2];

	for (int i = 1; i < m + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (p[j - 1] == '*')
				dp[i][j] = dp[i][j - 2] || (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j];
			else   //ֻ�е�ǰ�ַ���ȫƥ�䣬�����ʸ񴫵�dp[i-1][j-1] ��ֵ
				dp[i][j] = (p[j - 1] == '.' || s[i - 1] == p[j - 1]) && dp[i - 1][j - 1];
		}
	}
	return dp[m][n];
}