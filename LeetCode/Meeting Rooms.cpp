#include<vector>
#include<algorithm>
#include"TreeNode.h"

//题目描述:给定一个数组interval表示时间，判断这些interval有没有重复
//解法描述:先按照start进行排序，然后两两比较判断是否有重复

static bool compare(const Interval& interval1, const Interval& interval2) 
{
	return interval1.start < interval2.start;
}

bool canAttendMeetings(std::vector<Interval>& intervals) 
{
	sort(intervals.begin(), intervals.end(), compare);
	int n = intervals.size();
	for (int i = 0; i < n - 1; i++)
	{
		if (intervals[i].end > intervals[i + 1].start)
			return false;
	}
	return true;
}
