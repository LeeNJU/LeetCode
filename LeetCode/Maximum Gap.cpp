#include<vector>
#include<algorithm>

//题目描述：给定一个未排序的数组，找到排序后的相邻元素中最大的差值
//解法描述：桶排序，先计算数组中的最大和最小元素，然后算出桶的大小，再算出桶的个数（要加1），记录每个桶的最大和最小元素，其中结果一定存在于每个桶的
//最小元素和上一个桶的最大元素的差之间

int maximumGap(std::vector<int>& nums)
{
	if (nums.size() < 2)
		return 0;
	// 1. 算出用的桶数：取平均间隔，再用最大值和最小值之差除以间隔，得到桶数
	// 因为假设所有值都是平均分布的时候，如此取桶数可得时间复杂度是0(n)
	int maxVal = *max_element(nums.begin(), nums.end());
	int minVal = *min_element(nums.begin(), nums.end());
	int agGap = ceil((double) (maxVal - minVal) / (nums.size() - 1)); // 平均间隔  ceil为上取整函数，得到不小于给定值的最小整数，floor是下取整函数，得到不超过给定值的最大整数
	int bucketCount = (maxVal - minVal) / agGap + 1;  //注意这里计算桶的个数
	// 2. 记录每个桶的最大值和最小值
	std::vector<std::pair<int, int> > buckets(bucketCount, std::make_pair(INT_MIN, INT_MAX)); // 初始化桶
	for (int val : nums)
	{
		int bucketNum = (val - minVal) / agGap;
		if (val > buckets[bucketNum].first)
			buckets[bucketNum].first = val; // 存储最大值
		if (val < buckets[bucketNum].second)
			buckets[bucketNum].second = val; // 存储最小值
	}
	// 3. 算出最大间隔
	int maxGap = 0, lastMax = minVal;
	for (std::pair<int, int> bucket : buckets)
	{
		if (bucket.first == INT_MIN)
			continue; // 空桶
		int curMax = bucket.first, curMin = bucket.second;
		maxGap = std::max(maxGap, curMin - lastMax);
		lastMax = curMax;
	}
	return maxGap;
}