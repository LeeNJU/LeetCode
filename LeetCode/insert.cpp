#include<vector>
#include"TreeNode.h"
//��Ŀ����������һ���Ѿ��ź�����������䣬�����в���һ���������䣬����б�Ҫ��������ϲ����������[1,2],[3,5],[6,7],[8,10],[12,16]������[4,9]��
//���Ϊ[1,2],[3,10],[12,16]
//�ⷨ����:�����������䣬�ж�newInterval�뵱ǰ����Ĺ�ϵ������뵱ǰ�������غϲ��־ͽ��кϲ�����ɾ����ǰ���䣬�ټ����ж��µ�newInterval������Ĺ�ϵ


//bugs
std::vector<Interval> insert(std::vector<Interval> &intervals, Interval newInterval)
{
	std::vector<Interval>::iterator it = intervals.begin();
	while (it != intervals.end()) 
	{
		if (newInterval.end < it->start) //newInterval�ڵ�ǰ�����ǰ��
		{
			intervals.insert(it, newInterval);
			return intervals;
		}
		else if (newInterval.start > it->end) //newInterval�����ڵ�ǰ����ĺ���
		{
			it++;
		}
		else//newInterval�뵱ǰ�������ظ�����newInterval�͵�ǰ����ϲ���ɾ����ǰ����
		{
			newInterval.start = std::min(newInterval.start, it->start);
			newInterval.end = std::max(newInterval.end, it->end);
			it = intervals.erase(it);
		}
	}
	intervals.insert(intervals.end(), newInterval);//�������

	return intervals;
}