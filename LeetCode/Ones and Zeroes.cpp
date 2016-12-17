#include<vector>
#include<string>
#include<algorithm>
//��Ŀ����:����һ���ַ������飬ÿ���ַ�������0��1��ɣ�����m��0��n��1��������m��0��n��1����ɶ��ٸ��ַ�������
//        �е��ַ���������{"10", "0001", "111001", "1", "0"}, m = 5, n = 3�� ֻ�����"10","0001","1","0",
//        4���ַ���������4
//�ⷨ����:�������⣬ɨ���ַ������飬ͳ�Ƶ�ǰ�ַ�����0��1�ĸ�����dp[i][j] = max(dp[i - zero][j - one] + 1,
//         dp[i][j]),dp[i][j]Ϊ�����ǵ�ǰ�ַ����������dp[i - zero][j - zero] + 1�ǿ��ǵ�ǰ�ַ��������

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

		for (int i = m; i >= numZeroes; --i) //ע������Ҫ�Ӻ���ǰ����dp����
		{
			for (int j = n; j >= numOnes; --j) 
			{
				dp[i][j] = std::max(dp[i][j], dp[i - numZeroes][j - numOnes] + 1);
			}
		}
	}

	return dp[m][n];
}