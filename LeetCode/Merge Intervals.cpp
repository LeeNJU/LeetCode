#include"TreeNode.h"
#include<vector>
#include<algorithm>

//题目描述:给定一个Interval数组，将重复的合并，例如[1,3],[2,6],[8,10],[15,18],结果为[1,6],[8,10],[15,18]
//解法描述:先按照interval的start进行排序，然后0到i表示已经合并好的最后interval，j表示要合并当前interval，比较
//        end的值，如果有重复，把intervals[j]合并到intervals[i]，如果没有重复，i向后移动，把intervals[j]的
//        值赋给i

static bool compares(const Interval& one, const Interval& two)
{
	return one.start < two.start;
}

std::vector<Interval> merge(std::vector<Interval>& intervals) 
{
	if (intervals.empty())
		return std::vector<Interval>();

	std::sort(intervals.begin(), intervals.end(), compares);

	int i = 0, j = 1;
	for (; j < intervals.size(); ++j)
	{
		if (intervals[j].start <= intervals[i].end)//有重叠，合并到i
			intervals[i].end = std::max(intervals[j].end, intervals[i].end);
		else//没有重叠，i向后移动
		{
			++i;
			intervals[i].start = intervals[j].start;
			intervals[i].end = intervals[j].end;
		}
	}
	intervals.resize(i + 1);
	return intervals;
}