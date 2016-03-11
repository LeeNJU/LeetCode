#include<vector>
#include<deque>
//题目描述：给定一个数组和一个窗口，大小为k，该窗口依次向右移动一步得到一个新的大小为k的窗口，记录每个窗口的最大值
//解法描述：用一个双端队列保存滑动窗口元素，保持队首元素是滑动窗口中的最大值，每加一个元素，与队尾元素比较，如果
//         队尾元素小，删除队尾元素，类似于插入排序，队列中的元素是降序排列。
std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k)
{
	std::vector<int> res;
	std::deque<int> q;
	for (int i = 0; i < nums.size(); ++i) 
	{
		if (!q.empty() && q.front() == i - k)//移动滑动窗口，弹出队首元素 
			q.pop_front();
		while (!q.empty() && nums[q.back()] < nums[i]) 
			q.pop_back();
		q.push_back(i);
		if (i >= k - 1) 
			res.push_back(nums[q.front()]);
	}
	return res;
}
