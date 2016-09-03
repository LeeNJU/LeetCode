#include<vector>
#include<algorithm>
#include"TreeNode.h"
//题目描述:给定一串非负的整数数字流，每一个数组val，都会产生一个[val, val]区间，如果有必要对相邻的区间进行合
//        并，例如1,3,7,2,6,...,依次得到的区间是[[1,1]], [[1,1],[3,3]], [[1,3], [7,7]], [[1,3], [6,7]]
//解法描述:类似于insert merge，没读取一个数字，生成一个区间，然后把区间插入到需要的位置，有可能进行合并
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
			if (v[i].end + 1 < interval.start)//没有交集
				result.push_back(v[i]);
			else if (v[i].start > interval.end + 1)//没有交集
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