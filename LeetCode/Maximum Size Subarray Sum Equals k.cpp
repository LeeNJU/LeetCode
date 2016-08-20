#include<vector>
#include<unordered_map>
#include<algorithm>
//题目描述:给定一个数组和一个值k，从数组中找到一个最长的子数组，使得这个子数组的和等于k，例如:
//        nums = [1, -1, 5, -2, 3], k = 3,最长的子树组是[1, -1, 5, -2]
//解法描述:用hashtable记录区间[0, i]之间的值以及下标

int maxSubArrayLen(std::vector<int>& nums, int k) 
{
	std::unordered_map<int, int> map;
	map[0] = -1;  //这里是为了防止碰到和为k的子数组
	int sum = 0, max_length = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		sum += nums[i];
		if (map.find(sum - k) != map.end())
		{
			int preIndex = map[sum - k];
			max_length = std::max(max_length, i - preIndex);
		}
		if (map.find(sum) == map.end())
			map[sum] = i;
	}
	return max_length;
}
