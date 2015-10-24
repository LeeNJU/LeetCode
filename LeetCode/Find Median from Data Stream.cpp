#include<vector>
#include<algorithm>
#include<functional>

//��Ŀ����:��һ������������������ͣ�ļ���Ԫ��(δ����)��Ҫ������������ЩԪ�ص���λ������������1,3,2,��������2
//�ⷨ����:Ҫ֪��Ԫ�ص�˳����ܵõ���λ��������������ʵ�֣�һ�����ѣ�һ����С�ѣ����Ѻ���С�ѵĶѶ�Ԫ�ؾ�������������
//        ���м�Ԫ�أ�ͬʱ��һ��median���浱ǰ����λ����ÿ����һ��Ԫ�أ��ֱ�����Ӧ�Ķ��Ȼ�����median
class MedianFinder
{
private:
	std::vector<int> min_heap;
	std::vector<int> max_heap;
	double median;
public:
	void addNum(int num)
	{
		if (min_heap.size() == max_heap.size())//�����Ѵ�С���
		{
			if (min_heap.empty() && max_heap.empty())//�����Ѷ�Ϊ�գ�Ĭ�Ϸ�������
			{
				max_heap.push_back(num);
				push_heap(max_heap.begin(), max_heap.end());
				median = static_cast<double>(num);
			}
			else if (min_heap[0] > num)//�����Ѵ�С��ȣ����num����С�ѵĶѶ�Ԫ��ҪС����ô��������
			{
				max_heap.push_back(num);
				push_heap(max_heap.begin(), max_heap.end());
				median = static_cast<double>(max_heap[0]);
			}
			else if (min_heap[0] <= num)//���num����С�ѵĶѶ�Ԫ��Ҫ�󣬰�num������С��
			{                           
				min_heap.push_back(num);
				push_heap(min_heap.begin(), min_heap.end(), std::greater<int>());//ע�����Ĭ���Ǵ������ѣ�����С��
				median = static_cast<double>(min_heap[0]);                  //���в���ʱ��Ҫ�ӵ���������
			}
		}
		else if (min_heap.size() > max_heap.size())//��С�ѵĴ�С�����Ѵ�
		{
			if (min_heap[0] >= num)//num����С�ѵĶѶ�Ԫ��ҪС��ֱ�ӷ�������
			{
				max_heap.push_back(num);
				push_heap(max_heap.begin(), max_heap.end());
			}
			else//num����С�ѵĶѶ�Ԫ��Ҫ�󣬰���С�ѵĶѶ�Ԫ�ط������ѣ���num������С��
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
		else if (max_heap.size() > min_heap.size())//����
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