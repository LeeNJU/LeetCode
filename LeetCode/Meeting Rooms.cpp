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
