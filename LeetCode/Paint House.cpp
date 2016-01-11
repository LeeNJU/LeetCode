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