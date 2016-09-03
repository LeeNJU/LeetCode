#include<vector>
#include<algorithm>
#include"TreeNode.h"
//��Ŀ����:����һ���Ǹ���������������ÿһ������val���������һ��[val, val]���䣬����б�Ҫ�����ڵ�������к�
//        ��������1,3,7,2,6,...,���εõ���������[[1,1]], [[1,1],[3,3]], [[1,3], [7,7]], [[1,3], [6,7]]
//�ⷨ����:������insert merge��û��ȡһ�����֣�����һ�����䣬Ȼ���������뵽��Ҫ��λ�ã��п��ܽ��кϲ�
class SummaryRanges 
{
private:
	std::vector<Interval> v;
public:
	/** Initialize your data structure here. */
	SummaryRanges() 
	{

	}

	void addNum(int val) 
	{
		Interval interval(val, val);
		std::vector<Interval> result;
		for (int i = 0; i < v.size(); ++i)
		{
			if (v[i].end + 1 < interval.start)//û�н���
				result.push_back(v[i]);
			else if (v[i].start > interval.end + 1)//û�н���
			{
				result.push_back(interval);
				result.insert(result.end(), v.begin() + i, v.end());
				v = result;
				return;
			}
			else
			{
				interval.start = std::min(interval.start, v[i].start);
				interval.end = std::max(interval.end, v[i].end);
			}
		}
		result.push_back(interval);
		v = result;
	}

	std::vector<Interval> getIntervals() 
	{
		return v;
	}
};