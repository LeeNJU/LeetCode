#include<queue>
//题目描述:设计一个MovingAverage类，每次调用next方法，就往里插入一个数据，并返回最近k个数的平均值，例如
//        k大小为3，m.next(1) = 1, m.next(10) = (1 + 10) / 2, m.next(3) = (1 + 10 + 3) / 3
//        m.next(5) = (10 + 3 + 5) / 3
//解法描述:用一个双端队列，同时记录当前队列中数字的和。

class MovingAverage 
{
private:
	std::queue<int> q;
	int size;
	double sum;

public:
	MovingAverage(int size) 
	{
		this->size = size;
		sum = 0.0;
	}

	double next(int val) 
	{
		if (q.size() >= size) //队列大小超过k
		{
			sum -= q.front(); 
			q.pop();
		}
			
		q.push(val);
		sum += val;
		return sum / q.size();
	}
};