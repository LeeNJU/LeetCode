#include<vector>
#include<algorithm>
//题目描述:给定一个没有重复元素的正整数集合，求出最大的子集，使得子集中的元素能够两两互相整除。例如[1,2,4,8],
//        返回[1,2,4,8],因为整个数组的元素都能够两两整除，例如[1,2,3],返回[1,2]或者[1,3]
//解法描述:动态规划，先找到最大子集的大小，然后产生最终的结果子集。dp[i] = max(dp[j] + 1, dp[i]), 0 <= j < i,
//        用parent数组记录每个点在最优集合中的前一个元素。
std::vector<int> largestDivisibleSubset(std::vector<int>& nums) 
{
	if (nums.size() < 2)
		return nums;

	sort(nums.begin(), nums.end()); //先排序

	int max_length = 1;
	int max_index = 0;
	std::vector<int> dp(nums.size(), 1);
	std::vector<int> parent(nums.size(), 0);
	for (int i = 1; i < nums.size(); ++i)
	{
		int index = i; //index表示局部最优解的前一个元素的下标
		for (int j = 0; j < i; ++j)
		{
			if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i])
			{
				index = j;
				dp[i] = dp[j] + 1;
			}
		}
		if (dp[i] > max_length)//保存全局最优解以及全局最优解中最后一个元素的下标
		{
			max_length = dp[i];
			max_index = i;
		}
		parent[i] = index;
	}

	std::vector<int> result;
	while (parent[max_index] != max_index) //产生最优解
	{
		result.push_back(nums[max_index]);
		max_index = parent[max_index];
	}
	result.push_back(nums[max_index]);
	return result;
}