#include"TreeNode.h"
#include<vector>
#include<algorithm>

//��Ŀ����:����һ��Interval���飬���ظ��ĺϲ�������[1,3],[2,6],[8,10],[15,18],���Ϊ[1,6],[8,10],[15,18]
//�ⷨ����:�Ȱ���interval��start��������Ȼ��0��i��ʾ�Ѿ��ϲ��õ����interval��j��ʾҪ�ϲ���ǰinterval���Ƚ�
//        end��ֵ��������ظ�����intervals[j]�ϲ���intervals[i]�����û���ظ���i����ƶ�����intervals[j]��
//        ֵ����i

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
		if (intervals[j].start <= intervals[i].end)//���ص����ϲ���i
			intervals[i].end = std::max(intervals[j].end, intervals[i].end);
		else//û���ص���i����ƶ�
		{
			++i;
			intervals[i].start = intervals[j].start;
			intervals[i].end = intervals[j].end;
		}
	}
	intervals.resize(i + 1);
	return intervals;
}