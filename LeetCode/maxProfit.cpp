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