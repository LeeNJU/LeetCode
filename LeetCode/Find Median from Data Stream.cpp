#include<queue>
#include<algorithm>
#include<functional>

//��Ŀ����:��һ������������������ͣ�ļ���Ԫ��(δ����)��Ҫ������������ЩԪ�ص���λ������������1,3,2,��������2
//�ⷨ����:Ҫ֪��Ԫ�ص�˳����ܵõ���λ��������������ʵ�֣�һ�����ѣ�һ����С�ѣ����Ѻ���С�ѵĶѶ�Ԫ�ؾ�������������
//        ���м�Ԫ�أ�ͬʱ��һ��median���浱ǰ����λ����ÿ����һ��Ԫ�أ��ֱ�����Ӧ�Ķ��Ȼ�����median
class MedianFinder
{
private:
	std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
	std::priority_queue<int, std::vector<int>> max_heap;
public:
	void addNum(int num)
	{
		min_heap.push(num);//Ĭ�����Ƿ������ѣ������ȷ�����С�ѣ�Ȼ��ȥ��С�ѶѶ�Ԫ�ط�������
		max_heap.push(min_heap.top());
		min_heap.pop();
		if (min_heap.size() < max_heap.size()) //����Ԫ�ض�����С�ѣ�����С�ѶѶ�Ԫ�ط�������
		{
			min_heap.push(max_heap.top());
			max_heap.pop();
		}
	}

	double findMedian()
	{
		return min_heap.size() > max_heap.size() ? min_heap.top() : (min_heap.top() + max_heap.top()) / 2.0;
	}
};