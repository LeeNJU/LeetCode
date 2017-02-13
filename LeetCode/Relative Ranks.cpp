#include<vector>
#include<string>
#include<algorithm>
//题目描述:给定一个数组，表示运动员的分数，对前三名的运动员分别赋予"Gold Medal", "Silver Medal"和"Bronze Medal"
//        其他运动赋予相应的名次，例如给定[5, 4, 3, 2, 1],返回
//        ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"],5最大，是金牌，4第二大，是银牌，2是第4名
//解法描述:记录每个元素以及对应的下标，然后排序，分别赋予对应的值

std::vector<std::string> findRelativeRanks(std::vector<int>& nums) 
{
	std::vector<std::pair<int, int>> vec;
	for (int i = 0; i < nums.size(); ++i)
		vec.push_back(std::pair<int, int>(nums[i], i));

	std::sort(vec.begin(), vec.end());
	std::vector<std::string> result(nums.size(), "");
	for (int i = 0; i < (int) vec.size() - 3; ++i)
	{
		std::pair<int, int> p = vec[i];
		result[p.second] = std::to_string(vec.size() - i);
	}

	std::vector<std::string> medals = { "Gold Medal", "Silver Medal", "Bronze Medal" };
	for (int i = (int) vec.size() - 1; i >= 0 && i >= (int) vec.size() - 3; --i)
	{
		std::pair<int, int> p = vec[i];
		result[p.second] = medals[vec.size() - i - 1];
	}

	return result;
}