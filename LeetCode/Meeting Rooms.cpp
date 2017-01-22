#include<vector>
#include<algorithm>
#include"TreeNode.h"

//��Ŀ����:����һ������interval��ʾʱ�䣬�ж���Щinterval��û���ظ�
//�ⷨ����:�Ȱ���start��������Ȼ�������Ƚ��ж��Ƿ����ظ�

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
//��Ŀ����:����һ�鿪��Ŀ�ʼ�ͽ���ʱ�䣬������Ҫ����������
//�ⷨ����:�Ѳ��ص��Ļ��鰲����ͬһ�������ң��Ȱ��տ�ʼʱ�����򣬶�ÿһ��interval������֮ǰ��internval�����Ƿ�
//        �ظ���û���ظ����ͷŵ���Ӧ��rooms�����index�����ظ����ͼ���room
int findNonOverlapping(std::vector<Interval>& rooms, Interval& interval) 
{ //����room�е�internval���ҵ�û���غϵ�interval�����û�У��ͷ���-1
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
	priority_queue<int, vector<int>, greater<int>> q; // ������С��
	for (auto a : intervals) 
	{
		if (!q.empty() && q.top() <= a.start) 
			q.pop();
		q.push(a.end);
	}

	return q.size();
}*/