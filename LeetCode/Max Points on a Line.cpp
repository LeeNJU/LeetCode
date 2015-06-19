#include<vector>
#include<unordered_map>
#include<algorithm>
#include"TreeNode.h"
//题目描述：给定一个点的数组，找到一条直线，使得直线上的点最多，返回最多的点数
//解法描述：以点为中心，求出与剩下的点所组成的斜率，斜率相同，则在同一条直线上，记录点的数量

int maxPoints(std::vector<Point>& points)
{
	if (points.size() < 3) 
		return points.size();
	
	int result = 0;
	std::unordered_map<double, int> slope_count;
	for (int i = 0; i < points.size() - 1; ++i) 
	{
		slope_count.clear();
		int samePoint = 0;
		for (int j = i + 1; j < points.size(); ++j) 
		{
			double slope; // 斜率
			if (points[i].x == points[j].x)
			{
				slope = std::numeric_limits<double>::infinity(); // 斜率为无穷大的情况，即直线与x轴垂直
				if (points[i].y == points[j].y)  //相同的点必须跳过，在最后的结果里加上相同的点数
				{
					++samePoint;
					continue;
				}
			}
			else 
				slope = 1.0 * (points[i].y - points[j].y) / (points[i].x - points[j].x); //算斜率
			
			++slope_count[slope];
		}

		int max = 0;
		auto iter = slope_count.begin();
		while (iter != slope_count.end()) //找到该点对应的直线包含最多的点数
		{
			max = std::max(max, iter->second);
			++iter;
		}
		result = std::max(result, max + 1 + samePoint); //重合的点也算进去
	}
	return result;
}
