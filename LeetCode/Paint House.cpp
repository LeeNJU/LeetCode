#include<vector>
#include<algorithm>
//题目描述:用3中颜色给n个房子涂漆，给定costs数组,costs[i][0]表示用0种颜色涂第i个房子，相邻房子的颜色不能一样，
//        求最小的cost
//解法描述:dp[i][j]表示用第j种颜色涂第i个房子的最小cost，公式为dp[i][0] = min(dp[i - 1][1],dp[i - 1][2]) +
//        costs[i][0],由于只需要上一步的数据，可以优化成常数空间
int minCost(std::vector<std::vector<int>>& costs) 
{
	if (costs.empty()) 
		return 0;
	
	int r = 0, g = 0, b = 0;//r，g，b分别表示上一步用r，g和b颜色涂房子的最小cost
	for (int i = 0; i < costs.size(); ++i) 
	{
		int rr = r, bb = b, gg = g;
		r = costs[i][0] + std::min(bb, gg);
		b = costs[i][1] + std::min(rr, gg);
		g = costs[i][2] + std::min(rr, bb);
	}
	return std::min(r, std::min(b, g));//最后在3中颜色的cost选择最小的
}