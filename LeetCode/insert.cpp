#include<vector>
#include<algorithm>
#include"TreeNode.h"
//题目描述：给定一组已经排好序的数字区间，向其中插入一个数字区间，如果有必要进行区间合并，例如给定[1,2],[3,5],
//         [6,7],[8,10],[12,16]，插入[4,9]，结果为[1,2],[3,10],[12,16]
//解法描述:构造一个新的结果数组result，把intervals和newInterval的结果相继加入到result中

std::vector<Interval> insert(std::vector<Interval> &intervals, Interval newInterval)
{
	std::vector<Interval> result;
	std::vector<Interval>::iterator iter = intervals.begin();
	while (iter != intervals.end())
	{
		if (iter->end < newInterval.start)
			result.push_back(*iter);
		else if (iter->start > newInterval.end)
		{
			result.push_back(newInterval);
			result.insert(result.end(), iter, intervals.end());
			return result;
		}
		else
		{
			newInterval.start = std::min(newInterval.start, iter->start);
			newInterval.end = std::max(newInterval.end, iter->end);
		}
		++iter;
	}
	result.push_back(newInterval);
	return result;
}