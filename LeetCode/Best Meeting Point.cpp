#include<vector>
#include<algorithm>
//题目描述:给定一个二维矩阵，全部为0或者为1，在矩阵中找到一个点，使得这个点到其他为1的点的距离最短，距离是用曼哈顿距离，
//        |x1 - x2| + |y1 - y2|. 例如
//        1 - 0 - 0 - 0 - 1
//        |   |   |   |   |
//        0 - 0 - 0 - 0 - 0
//        |   |   |   |   |
//        0 - 0 - 1 - 0 - 0  最短距离的点是(0,2)，距离为2 + 2 + 2 = 6
//解法描述:二维上的最短距离点等于一维上的最短距离点。一维上的最短距离为中点。所以分别统计横坐标和纵坐标，找到中间的点
//        分别计算横坐标到中间点的距离之和，计算纵坐标到中间点的距离之和
int minTotalDistance(std::vector<std::vector<int>> grid) 
{
	std::vector<int> x;
	std::vector<int> y;
	// 统计出有哪些横纵坐标
	for (int i = 0; i < grid.size(); ++i)
	{
		for (int j = 0; j < grid[0].size(); ++j)
		{
			if (grid[i][j] == 1)
			{
				x.push_back(i);
				y.push_back(j);
			}
		}
	}
	int sum = 0;
	// 计算纵坐标到纵坐标中点的距离，这里不需要排序，因为之前统计时是按照i的顺序
	for (int i = 0; i < x.size(); ++i)
		sum += abs(x[i] - x[x.size() / 2]);

	// 计算横坐标到横坐标中点的距离，这里需要排序，因为统计不是按照j的顺序
	sort(y.begin(), y.end());
	for (int i = 0; i < y.size(); ++i)
		sum += abs(y[i] - y[y.size() / 2]);
	
	return sum;
}