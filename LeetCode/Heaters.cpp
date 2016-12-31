#include<vector>
#include<algorithm>
//题目描述:给定一个数组表示房子的位置，一个数组表示heater的位置，找到最小的半径，使得所有的房子都可以被heater
//        覆盖
//解法描述:对heater数组排序，对于每一个房子，利用二分查找，找到最接近的heater，求出半径，这些半径中最小的就是
//        答案

int findRadius(std::vector<int>& houses, std::vector<int>& heaters) 
{
	std::sort(heaters.begin(), heaters.end());
	int minRadius = 0;
	for (int i = 0; i < houses.size(); ++i)
	{
		auto larger = lower_bound(heaters.begin(), heaters.end(), houses[i]);//找到第一个大于等于val的
		int curRadius = INT_MAX;                           //位置
		if (larger != heaters.end())
			curRadius = *larger - houses[i];

		if (larger != heaters.begin())
		{
			auto smaller = larger - 1;//只要larger迭代器不是第一个，large - 1就是小于val的元素
			curRadius = std::min(curRadius, houses[i] - *smaller);
		}
		minRadius = std::max(minRadius, curRadius);
	}
	return minRadius;
}