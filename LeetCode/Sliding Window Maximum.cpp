#include<vector>

//题目描述：给定一个数组和一个窗口，大小为k，该窗口依次向右移动一步得到一个新的大小为k的窗口，记录每个窗口的最大值
//解法描述：
std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k)
{
	std::vector<int> result;
	int max_position = 0, int max = 0;
	for (int i = 0; i < k; ++i)
	{
		if (nums[i] > max)
		{
			max_position = i;
			max = nums[i];
		}
	}
	result.push_back(max);

	int left = 0, right = k - 1;
	for (int i = k; i < nums.size(); ++i)
	{

	}
}