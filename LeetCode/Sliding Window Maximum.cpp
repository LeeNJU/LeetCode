#include <vector>
#include <deque>
//题目描述：给定一个数组和一个窗口，大小为k，该窗口依次向右移动一步得到一个新的大小为k的窗口，记录每个窗口的最大值
//解法描述：
std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k)
{
	vector<int> res;
	deque<int> q;
	for (int i = 0; i < nums.size(); ++i) 
	{
		if (!q.empty() && q.front() == i - k) q.pop_front();
		while (!q.empty() && nums[q.back()] < nums[i]) 
			q.pop_back();
		q.push_back(i);
		if (i >= k - 1) 
			res.push_back(nums[q.front()]);
	}
	return res;
}
