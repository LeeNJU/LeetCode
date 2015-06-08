#include"TreeNode.h"
#include<vector>
#include<algorithm>

//题目描述：给定一个Interval数组，将重复的合并，例如[1,3],[2,6],[8,10],[15,18],结果为[1,6],[8,10],[15,18]
//解法描述；构造结果集result，不断向result进行插入操作，但是插入的时候要注意多次合并的情况

void insert(std::vector<Interval>& result, Interval interval)
{
	std::vector<Interval>::iterator iter = result.begin();
	while (iter != result.end())
	{
		if (interval.start > iter->end)
			++iter;
		else if (interval.end < iter->start)
		{
			result.insert(iter, interval);
			return;
		}
		else//注意这里，当iter指向的interval与要插入的interval有重复区间的时候，要把这两个interval合并形成新的interval，然后把iter指向的interval
		{   //删除，继续进行插入操作,后面可能还需要合并，因为可能会出现这样的情况：[1,3],[4,5],[7,9],要插入[1,10],结果应为[1,10]
			interval.start = std::min(iter->start, interval.start);
			interval.end = std::max(iter->end, interval.end);
			iter = result.erase(iter);
		}
	}
	result.push_back(interval);
}

std::vector<Interval> merge(std::vector<Interval>& intervals)
{
	std::vector<Interval> result;
	for (int i = 0; i < intervals.size(); ++i)
		insert(result, intervals[i]);
	return result;
}