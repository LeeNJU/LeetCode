#include<vector>
#include<algorithm>
//��Ŀ����:��3����ɫ��n������Ϳ�ᣬ����costs����,costs[i][0]��ʾ��0����ɫͿ��i�����ӣ����ڷ��ӵ���ɫ����һ����
//        ����С��cost
//�ⷨ����:dp[i][j]��ʾ�õ�j����ɫͿ��i�����ӵ���Сcost����ʽΪdp[i][0] = min(dp[i - 1][1],dp[i - 1][2]) +
//        costs[i][0],����ֻ��Ҫ��һ�������ݣ������Ż��ɳ����ռ�
int minCost(std::vector<std::vector<int>>& costs) 
{
	if (costs.empty()) 
		return 0;
	
	int r = 0, g = 0, b = 0;//r��g��b�ֱ��ʾ��һ����r��g��b��ɫͿ���ӵ���Сcost
	for (int i = 0; i < costs.size(); ++i) 
	{
		int rr = r, bb = b, gg = g;
		r = costs[i][0] + std::min(bb, gg);
		b = costs[i][1] + std::min(rr, gg);
		g = costs[i][2] + std::min(rr, bb);
	}
	return std::min(r, std::min(b, g));//�����3����ɫ��costѡ����С��
}

//version 2
//�����k����ɫ������С��cost
//�ⷨ����:�����һ���СΪk�������ʾ��ǰ�����ò�ͬ��ɫͿɫ����Сcost����ô�������������Ҫkƽ���ĸ��Ӷȣ���Ϊ
//        ����һ��ֵ��Ҫ������ֵ���бȽϡ���������������������һ������Сcost�͵����ڶ�С��cost��������������
//        ��ʱ��Ͳ��ñ�������Ԫ��
int minCostII(std::vector<std::vector<int>>& costs)
{
	if (costs.size() == 0) 
		return 0;
	
	int n = costs.size();
	int k = costs[0].size();
	std::vector<int> vec(k, 0);//��ʾ��ǰ����Ϳÿ����ɫ����Сcost
	int min1 = 0;//��һ������Сcost
	int min2 = 0;//��һ���ĵ����ڶ�С��cost
	for (int i = 0; i < n; ++i) 
	{
		int last_min1 = min1;
		int last_min2 = min2;
		min1 = INT_MAX;
		min2 = INT_MAX;
		for (int j = 0; j < k; ++j) 
		{
			vec[j] = (vec[j] == last_min1 ? last_min2 : last_min1) + costs[i][j];//��ɫ��ͬ
			if (min1 <= vec[j]) 
				min2 = std::min(min2, vec[j]);
			else 
			{
				min2 = min1;
				min1 = vec[j];
			}
		}
	}
	return min1;
}