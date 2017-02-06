#include<vector>
//题目描述:给定一个数组和一个值表示duration，例如[1,4], 2，表示从1开始攻击，时间长度是2，[1,2]这个区间是poison
//        状态，然后从4攻击，[4,5]是处于poison状态，求总共处于poison状态的时间，又例如[1,2],2,区间[1,2]是
//        poison状态，然后从2攻击，[2,3]处于poison状态，总共有3个时间处于poison状态
//解法描述:遍历数组，对于当前时间点，如果处于之前的poison状态范围之内，记录poison的开始时间，
//        [begin, beign + duration],如果当前时间点处于这个范围之内，只需要加上t - begin的时间，如果不处于这个
//        范围之内，就直接加上duration

int findPoisonedDuration(std::vector<int>& timeSeries, int duration)
{
	if (timeSeries.empty()) 
		return 0;

	int begin = timeSeries[0], total = 0;
	for (int t : timeSeries) 
	{
		total += t < begin + duration ? t - begin : duration;
		begin = t;
	}

	return total + duration;
}

/*
int findPoisonedDuration(std::vector<int>& timeSeries, int duration) 
{
	if (timeSeries.empty())
		return 0;
	if (timeSeries.size() == 1)
		return duration;

	int end = timeSeries[0] + duration - 1;
	int result = 0;
	for (int i = 1; i < timeSeries.size(); ++i)
	{
		if (timeSeries[i] > end)
		{
			result += duration;
			end = timeSeries[i] + duration - 1;
		}
		else
		{
			result += timeSeries[i] - timeSeries[i - 1];
			end = timeSeries[i] + duration - 1;
		}
	}

	return result + duration;
}*/