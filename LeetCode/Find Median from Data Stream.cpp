#include<queue>
#include<algorithm>
#include<functional>

//题目描述:有一个连续的数据流，不停的加入元素(未排序)，要求立即返回这些元素的中位数，例如输入1,3,2,立即返回2
//解法描述:要知道元素的顺序才能得到中位数，用两个堆来实现，一个最大堆，一个最小堆，最大堆和最小堆的堆顶元素就是整个数据中
//        的中间元素，同时用一个median保存当前的中位数，每加入一个元素，分别放入对应的堆里，然后更新median
class MedianFinder
{
private:
	std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
	std::priority_queue<int, std::vector<int>> max_heap;
public:
	void addNum(int num)
	{
		min_heap.push(num);//默认总是放入最大堆，但是先放入最小堆，然后去最小堆堆顶元素放入最大堆
		max_heap.push(min_heap.top());
		min_heap.pop();
		if (min_heap.size() < max_heap.size()) //最大堆元素多余最小堆，把最小堆堆顶元素放入最大堆
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