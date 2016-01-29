#include<vector>
#include<algorithm>
#include"TreeNode.h"
//��Ŀ����������һ���Ѿ��ź�����������䣬�����в���һ���������䣬����б�Ҫ��������ϲ����������[1,2],[3,5],
//         [6,7],[8,10],[12,16]������[4,9]�����Ϊ[1,2],[3,10],[12,16]
//�ⷨ����:����һ���µĽ������result����intervals��newInterval�Ľ����̼��뵽result��

std::vector<Interval> insert(std::vector<Interval> &intervals, Interval newInterval)
{
	std::vector<Interval> result;
	std::vector<Interval>::iterator iter = intervals.begin();
	while (iter != intervals.end())
	{
		if (iter->end < newInterval.start)
			result.push_back(*iter);
		else if (iter->start > newInterval.end)
		{
			result.push_back(newInterval);
			result.insert(result.end(), iter, intervals.end());
			return result;
		}
		else
		{
			newInterval.start = std::min(newInterval.start, iter->start);
			newInterval.end = std::max(newInterval.end, iter->end);
		}
		++iter;
	}
	result.push_back(newInterval);
	return result;
}