#include<vector>
#include<algorithm>

//��Ŀ����������һ�������ʾÿ����Ʊ�ļ�Ǯ���ҵ�������������ʹ���ǵĲ���󣬷��������ֵ
//�ⷨ������̰�ģ����赱ǰ��һ��Ԫ������Сֵ��

int maxProfit(std::vector<int> &prices)
{
	if (prices.size() < 2) 
		return 0;

	int profit = 0; // ��ۣ�Ҳ��������
	int cur_min = prices[0]; // ���赱ǰ��С
	for (int i = 1; i < prices.size(); i++) {//�������飬������Сֵ������
		profit = std::max(profit, prices[i] - cur_min);//ע�������д����˳�򣬲��ܵ���
		cur_min = std::min(cur_min, prices[i]);
	}
	return profit;
}

//version 2
//��Ŀ������ͬ�������飬��������ν��ף��������������һ��ֻ�������
//�ⷨ������

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
//��Ŀ������ͬ�������飬���ֻ�����ν��ף�������profit��һ�����ͬʱ���������
//�ⷨ���������ν��ױ�Ȼ���������䣬���Կ�����ÿ��Ԫ�ؽ��л��֣�����0 - i��(i + 1) - (n - 1)�����Ľ��Ӧ��
//         �Ƕ��ߺ͵����ֵ���ö�̬�滮dp[i]��ʾ0 - i�����profit����ɨ��һ��õ�0��n�����ֵ��Ȼ���������
//         ɨ�裬�������ֵ�����i��n�����ֵ��Ҳ���ǵڶ������׵����ֵ�����Ľ���Ƕ���֮��
int maxProfit(std::vector<int>& prices) 
{
	if (prices.size() <= 1)
		return 0;
	std::vector<int> dp(prices.size(), 0);//ÿ����ʼ��Ϊ0

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
		max_profit = std::max(max_profit, dp[i] + max_price - prices[i]);//i�����
		max_price = std::max(max_price, prices[i]);
	}
	return max_profit;
}