#include<vector>
#include<algorithm>
//题目描述:用3种颜色给n个房子涂漆，给定costs数组,costs[i][0]表示用0种颜色涂第i个房子，相邻房子的颜色不能一样，
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

//version 2
//如果有k种颜色，求最小的cost
//解法描述:如果用一格大小为k的数组表示当前房子用不同颜色涂色的最小cost，那么更新这个数组需要k平方的复杂度，因为
//        更新一个值需要和其他值进行比较。可以用两个变量保存上一步的最小cost和倒数第二小的cost，这样更新数组
//        的时候就不用遍历其他元素
int minCostII(std::vector<std::vector<int>>& costs)
{
	if (costs.size() == 0) 
		return 0;
	
	int n = costs.size();
	int k = costs[0].size();
	std::vector<int> vec(k, 0);//表示当前房子涂每种颜色的最小cost
	int min1 = 0;//上一步的最小cost
	int min2 = 0;//上一步的倒数第二小的cost
	for (int i = 0; i < n; ++i) 
	{
		int last_min1 = min1;
		int last_min2 = min2;
		min1 = INT_MAX;
		min2 = INT_MAX;
		for (int j = 0; j < k; ++j) 
		{
			vec[j] = (vec[j] == last_min1 ? last_min2 : last_min1) + costs[i][j];//颜色不同
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