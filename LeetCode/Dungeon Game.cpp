#include<vector>
#include<algorithm>

int calculateMinimumHP(std::vector<std::vector<int>>& dungeon) 
{
	if (dungeon.empty())
		return 0;

	int m = dungeon.size(), n = dungeon[0].size();
	std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
	dp[m - 1][n - 1] = std::max(1, 1 - dungeon[m - 1][n - 1]);

	for (int i = dp.size() - 1; i >= 0; --i)
	{
		for (int j = dp[0].size() - 1; j >= 0; --j)
		{
			if (dungeon[i][j] < 0)
				dp[i][j] = std::min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
			else

		}
	}
}