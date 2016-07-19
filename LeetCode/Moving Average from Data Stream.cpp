#include<queue>
//��Ŀ����:���һ��MovingAverage�࣬ÿ�ε���next���������������һ�����ݣ����������k������ƽ��ֵ������
//        k��СΪ3��m.next(1) = 1, m.next(10) = (1 + 10) / 2, m.next(3) = (1 + 10 + 3) / 3
//        m.next(5) = (10 + 3 + 5) / 3
//�ⷨ����:��һ��˫�˶��У�ͬʱ��¼��ǰ���������ֵĺ͡�

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
		if (q.size() >= size) //���д�С����k
		{
			sum -= q.front(); 
			q.pop();
		}
			
		q.push(val);
		sum += val;
		return sum / q.size();
	}
};