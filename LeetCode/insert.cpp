#include<iostream>
#include<vector>
#include"TreeNode.h"


std::vector<Interval> insert(std::vector<Interval> &intervals, Interval newInterval)
{
	int first = -1, last = -1; //��¼�����λ�ã�firstΪż��˵�������λ��Ϊһ������֮�ڣ�firstΪ������˵�������λ��Ϊ����֮�䣬lastͬ��
	for (size_t i = 0; i < intervals.size(); ++i)
	{
		if (intervals[i].start <= newInterval.start && intervals[i].end >= newInterval.start)
			first = i * 2;
		if (newInterval.start > intervals[i].end)
			first = i * 2 + 1;
		if (intervals[i].start <= newInterval.end && intervals[i].end >= newInterval.end)
			last = i * 2;
		if (newInterval.end > intervals[i].end)
			last = i * 2 + 1;
	}

	if (last == -1)
	{
		intervals.insert(intervals.begin(), newInterval);
	}
	else if (first == -1)
	{
		int index = last / 2;
		int temp = intervals[index].end;
		intervals.erase(intervals.begin(), intervals.begin() + index + 1);
		if (last % 2 == 0)
			newInterval.end = temp;
		intervals.insert(intervals.begin(), newInterval);
	}
	else if (first > intervals.size() * 2)
	{
		intervals.push_back(newInterval);
	}
	else
	{
		if (first % 2 == 0 && last % 2 == 1)//���������interval��ֵ
			newInterval.start = intervals[first / 2].start;
		if (first % 2 == 1 && last % 2 == 0)
			newInterval.end = intervals[last / 2].end;
		if (first % 2 == 0 && last % 2 == 0)
		{
			newInterval.start = intervals[first / 2].start;
			newInterval.end = intervals[last / 2].end;
		}
			
		intervals.erase(intervals.begin() + (first + 1) / 2, intervals.begin() + last / 2 + 1);
		intervals.insert(intervals.begin() + (first + 1) / 2, newInterval);
	}
	return intervals;
}