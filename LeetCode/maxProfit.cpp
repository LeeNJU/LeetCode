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
	for (int i = 1; i < prices.size(); i++) {
		int diff = prices[i] - prices[i - 1];
		if (diff > 0) sum += diff;
	}
	return sum;
}