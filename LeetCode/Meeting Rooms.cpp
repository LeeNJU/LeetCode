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

//version2
//题目描述:给定一组开会的开始和结束时间，最少需要几个会议室
//解法描述:把不重叠的会议安排在同一个会议室，先按照开始时间排序，对每一个interval，遍历之前的internval，看是否
//        重复，没有重复，就放到相应的rooms数组的index，有重复，就加入room
int findNonOverlapping(std::vector<Interval>& rooms, Interval& interval) 
{ //遍历room中的internval，找到没有重合的interval，如果没有，就返回-1
	for (int i = 0; i < rooms.size(); ++i)
		if (interval.start >= rooms[i].end)
		    return i;
	return -1;
}

int minMeetingRooms(std::vector<Interval>& intervals) 
{
	sort(intervals.begin(), intervals.end(), compare);
	std::vector<Interval> rooms;
	for (int i = 0; i < intervals.size(); ++i) 
	{
		int idx = findNonOverlapping(rooms, intervals[i]);
		if (rooms.empty() || idx == -1)
			rooms.push_back(intervals[i]);
		else 
			rooms[idx] = intervals[i];
	}
	return rooms.size();
}

/*
int minMeetingRooms(vector<Interval>& intervals) 
{
	sort(intervals.begin(), intervals.end(), compare);
	priority_queue<int, vector<int>, greater<int>> q; // 建立最小堆
	for (auto a : intervals) 
	{
		if (!q.empty() && q.top() <= a.start) 
			q.pop();
		q.push(a.end);
	}

	return q.size();
}*/