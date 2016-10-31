#include<vector>
#include<algorithm>
#include"TreeNode.h"
//��Ŀ����:����һ����interval��ɾ�����е�һЩinterval��ʹ����Щinterval֮��û���ص���[1,2]��[2,3]�����ص���
//        ����[ [1,2], [2,3], [3,4], [1,3] ]��ֻ��Ҫɾ��[1,3]��ʣ�µ�interval����û���ص���
//�ⷨ����:������ɨ��interval������������ڵ�interval���ص�����ʾ��Ҫɾ��һ��interval��ע��prev��ʹ�ã�
//        ����ɾ��ʹinterval֮��ľ���Խ���interval

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
			if (intervals[i].end < intervals[prev].end)//��ǰinterval������prev��interval֮�䣬ɾ��prev 
				prev = i;
		}
		else 
			prev = i;
	}
	return result;
}