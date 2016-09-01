#include<vector>
#include<algorithm>

//题目描述:有n个硬币，两个人轮流拿硬币，每个人每次只能拿1个或者2个，拿走最后的硬币的人赢，问第一个人会不会赢
//解法描述:如果n是3的倍数，第一个人一定会输，否则，第一个人会赢
bool firstWillWin(int n) 
{
	return n % 3 != 0;
}

//题目描述:给定n个不同的硬币，两个选手轮流取最左边的硬币，每次只能取一个或者两个硬币，谁的硬币之和最大就赢了。
//解法描述:动态规划,dp[i]表示从i到n-1的范围内，选手能取得的最大的硬币和，如果选手取values[i],那么对手可能会
//        选values[i + 1],那么我们能得到的最大值就是dp[i + 2],如果对手选values[i + 1]和values[i + 2],那么
//        我们能得到的最大值是dp[i + 3], 因此，当我们只选values[i]的时候，能取得的最大值是values[i] + 
//        min(dp[i + 2], dp[i + 3]),注意这里是min，因为对手只会使得我们能选的值最小，同理可得如果我们选
//        values[i]和values[i + 1],能取得的最大值是values[i] + values[i + 1] + min(dp[i + 3], dp[i + 4])
//        二者取最大，就是当前dp[i]的值

bool firstWillWin(std::vector<int>& values)
{
	if (values.size() < 3)
		return true;

	int sum = 0;
	for (int value : values)
		sum += value;

	int n = values.size();
	std::vector<int> dp(n + 1, 0);//取n+1是因为会出现i + 4
	dp[n - 1] = values[n - 1];
	dp[n - 2] = values[n - 2] + values[n - 1];
	dp[n - 3] = values[n - 3] + values[n - 2];

	for (int i = n - 4; i >= 0; --i)
	{
		int first_choice = values[i] + std::min(dp[i + 2], dp[i + 3]);
		int second_choice = values[i] + values[i + 1] + std::min(dp[i + 3], dp[i + 4]);
		dp[i] = std::max(dp[i], std::max(first_choice, second_choice));
	}

	return dp[0] > sum - dp[0];
}