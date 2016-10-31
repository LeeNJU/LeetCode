#include<vector>
#include<algorithm>
#include"TreeNode.h"
//题目描述:给定一个组interval，删掉其中的一些interval，使得这些interval之间没有重叠，[1,2]和[2,3]不算重叠，
//        例如[ [1,2], [2,3], [3,4], [1,3] ]，只需要删除[1,3]，剩下的interval都是没有重叠的
//解法描述:先排序，扫描interval，如果发现相邻的interval有重叠，表示需要删除一个interval，注意prev的使用，
//        总是删除使interval之间的距离越大的interval

int eraseOverlapIntervals(std::vector<Interval>& intervals) 
{
	auto comp = [](const Interval& i1, const Interval& i2){ return i1.start < i2.start; };
	sort(intervals.begin(), intervals.end(), comp);
	
	int result = 0, prev = 0;
	for (int i = 1; i < intervals.size(); ++i)
	{
		if (intervals[i].start < intervals[prev].end)
		{
			++result;
			if (intervals[i].end < intervals[prev].end)//当前interval包含在prev的interval之间，删除prev 
				prev = i;
		}
		else 
			prev = i;
	}
	return result;
}