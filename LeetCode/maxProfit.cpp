#include<vector>
#include<algorithm>

//题目描述：给定一个数组表示每个股票的价钱，找到其中两个数，使他们的差最大，返回这个差值
//解法描述：贪心，假设当前第一个元素是最小值，

int maxProfit(std::vector<int> &prices)
{
	if (prices.size() < 2) 
		return 0;

	int profit = 0; // 差价，也就是利润
	int cur_min = prices[0]; // 假设当前最小
	for (int i = 1; i < prices.size(); i++) {//遍历数组，更新最小值和利润
		profit = std::max(profit, prices[i] - cur_min);//注意这两行代码的顺序，不能调换
		cur_min = std::min(cur_min, prices[i]);
	}
	return profit;
}

//version 2
//题目描述：同样的数组，可以做多次交易，买进卖出，但是一天只能买或卖
//解法描述：

int maxProfitTwo(std::vector<int> &prices)
{
	int sum = 0;
	for (int i = 1; i < prices.size(); i++) 
	{
		int diff = prices[i] - prices[i - 1];
		if (diff > 0) 
			sum += diff;
	}
	return sum;
}

//version 3
//题目描述：同样的数组，最多只能两次交易，求最大的profit，一天可以同时卖出和买进
//解法描述：两次交易必然在两个区间，所以可以以每个元素进行划分，区间0 - i和(i + 1) - (n - 1)，最后的结果应该是二者和的
//         最大值。用动态规划dp[i]表示0 - i的最大profit，先扫描一遍得到0到n的最大值，然后从右往左扫描，保存最大值，
//         求出i到n的最大值，也就是第二个交易的最大值，最后的结果是二者之和
int maxProfit(std::vector<int>& prices) 
{
	if (prices.size() <= 1)
		return 0;
	std::vector<int> dp(prices.size(), 0);//每个初始化为0

	int min_price = prices[0];
	for (int i = 1; i < prices.size(); ++i)
	{
		dp[i] = std::max(dp[i - 1], prices[i] - min_price);
		min_price = std::min(min_price, prices[i]);
	}

	int max_profit = 0;
	int max_price = prices[prices.size() - 1];
	for (int i = prices.size() - 2; i >= 0; --i)
	{
		max_profit = std::max(max_profit, dp[i] + max_price - prices[i]);//i点求和
		max_price = std::max(max_price, prices[i]);
	}
	return max_profit;
}