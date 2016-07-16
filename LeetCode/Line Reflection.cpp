#include<vector>
#include<unordered_map>
#include<set>
#include<algorithm>
//题目描述:给定一些点，要求判断是否存在一条与y轴平行的线，使得所有的点关于这条线对称
//解法描述:先找到这条对称的线，然后遍历每一个点是否存在关于这条线对称的点。

bool isReflected(std::vector<std::pair<int, int>>& points) 
{
	std::unordered_map<int, std::set<int>> m; //横坐标对应的纵坐标
	int mx = INT_MIN, mn = INT_MAX;
	for (auto point : points) //通过横坐标的最大值和最小值来找对称轴
	{
		mx = std::max(mx, point.first);
		mn = std::min(mn, point.first);
		m[point.first].insert(point.second);
	}

	double middle = (double) (mx + mn) / 2;
	for (auto point : points) 
	{
		int x = 2 * middle - point.first; //算出对应的横坐标
		if (!m.count(x) || !m[x].count(point.second)) //检查对应的纵坐标是否存在
			return false;
	}
	return true;
}