#include<vector>
#include<algorithm>

std::vector<int> maxNumber(std::vector<int>& nums1, std::vector<int>& nums2, int k) 
{
	std::vector<std::vector<std::vector<int>>> dp(nums1.size() + 1, std::vector<std::vector<int>>(nums2.size() + 1, std::vector<int>(k + 1, 0)));
	std::vector<int> index1(nums1.size(), 0);
	std::vector<int> index2(nums2.size(), 0);

	for (int i = 0; i < dp.size(); ++i)
	{
		for (int j = 0; j < dp[0].size(); ++j)
			dp[i][j][0] = 0;
	}

	for (int i = 1; i <= k; ++i)
	{
		for (int j = 0; j < nums1.size(); ++j)
		{
			dp[j + 1][0][i] = std::max(dp[j][0][i - 1] * 10 + nums1[j], dp[j][0][i]);
		}
	}

	for (int i = 1; i <= k; ++i)
	{
		for (int j = 0; j < nums2.size(); ++j)
		{
			dp[0][j + 1][i] = std::max(dp[0][j][i], dp[0][j][i - 1] * 10 + nums2[j]);
		}
	}

	for (int i = 0; i < nums1.size(); ++i)
	{
		for (int j = 0; j < nums2.size(); ++j)
		{
			for (int m = 1; m <= k; ++m)
			{
				dp[i + 1][j + 1][m] = std::max()
			}
		}
	}
}