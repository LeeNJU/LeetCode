#include<vector>
//题目描述:设计一个计数器，有两个函数hit和getHits，hit的参数为时间点，单位为秒，每调用hit函数就表示有一次hit，
//        每调用getHits函数，就返回300秒以内的hit数。注意可能会在同一时间调用hit函数
//解法描述:用两个大小为300的数组保存hit的时间和数量，每调用hit的时候，时间点timestamp对300取余，先检查times
//        数组，如果时间点的值与当前的时间点相同，表示是同一时间点多次调用，相应的hit加1，如果时间点不同，表示
//        时间点已经超过300了，把相应的hit数设为1。最后得到300秒以内的hit数的时候，遍历times数组，把时间在
//        300秒以内的hit进行相加。
class HitCounter 
{
private:
	std::vector<int> times, hits;

public:
	HitCounter() //初始化成300
	{
		times.resize(300);
		hits.resize(300);
	}

	void hit(int timestamp) 
	{
		int idx = timestamp % 300;
		if (times[idx] != timestamp)//与当前时间点不同，表示已经超过300秒了，设为1 
		{
			times[idx] = timestamp;
			hits[idx] = 1;
		}
		else 
			++hits[idx];
	}

	int getHits(int timestamp) 
	{
		int res = 0;
		for (int i = 0; i < 300; ++i)//遍历，与当前时间点相差少于300秒的hit数进行求和 
		{
			if (timestamp - times[i] < 300) 
				res += hits[i];
		}
		return res;
	}
};