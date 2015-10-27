#include<vector>
#include<map>
//题目描述：给定一个数组，判断是否存在元素A[i]和A[j]，使得i与j的差不超过k，A[i]与A[j]的差不超过t
//解法描述：用一个map保存i到j之间的元素，i和j的差不超过k，利用map的lower_bound方法找到nums[i] - t的上界，就是大于等于
//         nums[i] - t的元素的迭代器，小于这个迭代器的元素与nums[i] - t的差一定大于t，大于这个迭代器的元素与nums[i] - t
//         的差不一定大于t，必须判断。

bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int k, int t)
{
	std::map<int, int> m;
	int j = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (i - j > k)//下标之差大于k，要删除之前的元素
		{
			m.erase(nums[j]);
			++j;
		}
		std::map<int, int>::iterator iter = m.lower_bound(nums[i] - t);
		if (iter != m.end() && abs(iter->first - nums[i]) <= t)
			return true;
		m[nums[i]] = i;
	}
	return false;
}