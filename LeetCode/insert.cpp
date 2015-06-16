#include<vector>
#include"TreeNode.h"
//题目描述：给定一组已经排好序的数字区间，向其中插入一个数字区间，如果有必要进行区间合并，例如给定[1,2],[3,5],[6,7],[8,10],[12,16]，插入[4,9]，
//结果为[1,2],[3,10],[12,16]
//解法描述:遍历数字区间，判断newInterval与当前区间的关系，如果与当前区间有重合部分就进行合并，再删除当前区间，再继续判断新的newInterval与区间的关系


//bugs
std::vector<Interval> insert(std::vector<Interval> &intervals, Interval newInterval)
{
	std::vector<Interval>::iterator it = intervals.begin();
	while (it != intervals.end()) 
	{
		if (newInterval.end < it->start) //newInterval在当前区间的前面
		{
			intervals.insert(it, newInterval);
			return intervals;
		}
		else if (newInterval.start > it->end) //newInterval区间在当前区间的后面
		{
			it++;
		}
		else//newInterval与当前区间有重复，把newInterval和当前区间合并，删除当前区间
		{
			newInterval.start = std::min(newInterval.start, it->start);
			newInterval.end = std::max(newInterval.end, it->end);
			it = intervals.erase(it);
		}
	}
	intervals.insert(intervals.end(), newInterval);//插入最后

	return intervals;
}