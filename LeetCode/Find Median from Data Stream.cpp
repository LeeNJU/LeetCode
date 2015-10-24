#include<vector>
#include<algorithm>
#include<functional>

//题目描述:有一个连续的数据流，不停的加入元素(未排序)，要求立即返回这些元素的中位数，例如输入1,3,2,立即返回2
//解法描述:要知道元素的顺序才能得到中位数，用两个堆来实现，一个最大堆，一个最小堆，最大堆和最小堆的堆顶元素就是整个数据中
//        的中间元素，同时用一个median保存当前的中位数，每加入一个元素，分别放入对应的堆里，然后更新median
class MedianFinder
{
private:
	std::vector<int> min_heap;
	std::vector<int> max_heap;
	double median;
public:
	void addNum(int num)
	{
		if (min_heap.size() == max_heap.size())//两个堆大小相等
		{
			if (min_heap.empty() && max_heap.empty())//两个堆都为空，默认放入最大堆
			{
				max_heap.push_back(num);
				push_heap(max_heap.begin(), max_heap.end());
				median = static_cast<double>(num);
			}
			else if (min_heap[0] > num)//两个堆大小相等，如果num比最小堆的堆顶元素要小，那么放入最大堆
			{
				max_heap.push_back(num);
				push_heap(max_heap.begin(), max_heap.end());
				median = static_cast<double>(max_heap[0]);
			}
			else if (min_heap[0] <= num)//如果num比最小堆的堆顶元素要大，把num放入最小堆
			{                           
				min_heap.push_back(num);
				push_heap(min_heap.begin(), min_heap.end(), std::greater<int>());//注意这里，默认是创建最大堆，对最小堆
				median = static_cast<double>(min_heap[0]);                  //进行操作时，要加第三个参数
			}
		}
		else if (min_heap.size() > max_heap.size())//最小堆的大小比最大堆大
		{
			if (min_heap[0] >= num)//num比最小堆的堆顶元素要小，直接放入最大堆
			{
				max_heap.push_back(num);
				push_heap(max_heap.begin(), max_heap.end());
			}
			else//num比最小堆的堆顶元素要大，把最小堆的堆顶元素放入最大堆，把num放入最小堆
			{
				max_heap.push_back(min_heap[0]);
				push_heap(max_heap.begin(), max_heap.end());
				pop_heap(min_heap.begin(), min_heap.end(), std::greater<int>());
				min_heap.pop_back();
				min_heap.push_back(num);
				push_heap(min_heap.begin(), min_heap.end(), std::greater<int>());
			}
			median = (static_cast<double>(min_heap[0]) + static_cast<double>(max_heap[0])) / 2;

		}
		else if (max_heap.size() > min_heap.size())//最大堆
		{
			if (num > max_heap[0])
			{
				min_heap.push_back(num);
				push_heap(min_heap.begin(), min_heap.end(), std::greater<int>());
			}
			else
			{
				min_heap.push_back(max_heap[0]);
				push_heap(min_heap.begin(), min_heap.end(), std::greater<int>());
				pop_heap(max_heap.begin(), max_heap.end());
				max_heap.pop_back();
				max_heap.push_back(num);
				push_heap(max_heap.begin(), max_heap.end());
			}
			median = (static_cast<double>(min_heap[0]) + static_cast<double>(max_heap[0])) / 2;
		}
	}

	double findMedian()
	{
		return median;
	}
};