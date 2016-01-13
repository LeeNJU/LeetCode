#include<vector>
#include<string>
//题目描述:给定一个已序数组和一个lower和upper范围，找到数组中消失的区间，例如[0, 1, 3, 50, 75]，lower = 0，
//        upper = 99，那么消失的区间是["2", "4->49", "51->74", "76->99"]
//解法描述:i表示当前应该出现的数字，然后遍历数组
std::vector<std::string> findMissingRanges(std::vector<int>& nums, int lower, int upper)
{
	std::vector<std::string> result;
	int i = lower;
	for (int j = 0; j < nums.size(); ++j)
	{
		if (nums[j] != i)//找到不相符的数字，说明找到了一个区间
		{
			if (i == nums[j] - 1)//区间只有一个元素
				result.push_back(std::to_string(i));
			else
				result.push_back(std::to_string(i) + "->" + std::to_string(nums[j] - 1));
			i = nums[j] + 1;
		}
		else
			++i;
	}

	if (i < upper)//最后还要考虑upper
	{
		if (i == upper)
			result.push_back(std::to_string(i));
		else
			result.push_back(std::to_string(i) + "->" + std::to_string(upper));
	}
	return result;
}