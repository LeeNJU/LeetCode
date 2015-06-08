#include"TreeNode.h"
#include<vector>
#include<algorithm>

//��Ŀ����������һ��Interval���飬���ظ��ĺϲ�������[1,3],[2,6],[8,10],[15,18],���Ϊ[1,6],[8,10],[15,18]
//�ⷨ��������������result��������result���в�����������ǲ����ʱ��Ҫע���κϲ������

void insert(std::vector<Interval>& result, Interval interval)
{
	std::vector<Interval>::iterator iter = result.begin();
	while (iter != result.end())
	{
		if (interval.start > iter->end)
			++iter;
		else if (interval.end < iter->start)
		{
			result.insert(iter, interval);
			return;
		}
		else//ע�������iterָ���interval��Ҫ�����interval���ظ������ʱ��Ҫ��������interval�ϲ��γ��µ�interval��Ȼ���iterָ���interval
		{   //ɾ�����������в������,������ܻ���Ҫ�ϲ�����Ϊ���ܻ���������������[1,3],[4,5],[7,9],Ҫ����[1,10],���ӦΪ[1,10]
			interval.start = std::min(iter->start, interval.start);
			interval.end = std::max(iter->end, interval.end);
			iter = result.erase(iter);
		}
	}
	result.push_back(interval);
}

std::vector<Interval> merge(std::vector<Interval>& intervals)
{
	std::vector<Interval> result;
	for (int i = 0; i < intervals.size(); ++i)
		insert(result, intervals[i]);
	return result;
}