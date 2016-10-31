#include<vector>
#include<map>
#include"TreeNode.h"
//题目描述:给定一组interval，interval j被称作是interval i的右边，如果interval j的起始位置大于等于interval i
//        的结束位置，对每个interval，找到最接近的"right"interval的下标，例如[ [3,4], [2,3], [1,2] ]， 那
//        么返回[-1, 0, 1]，某个interval不存在"right" interval，就是-1
//解法描述:记录每个interval起始位置以及下标，对于每个interval的结束位置，找到最接近的起始位置，二分查找，

std::vector<int> findRightInterval(std::vector<Interval>& intervals) 
{
	std::map<int, int> map;
	for (int i = 0; i < intervals.size(); ++i)//保存起始位置以及下标
		map[intervals[i].start] = i;

	std::vector<int> result(intervals.size(), -1);
	for (int i = 0; i < intervals.size(); ++i)
	{
		auto iter = map.upper_bound(intervals[i].end - 1);//注意这里要减1
		if (iter != map.end())
			result[i] = iter->second;
	}

	return result;
}