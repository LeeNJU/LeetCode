#include<string>
#include<vector>

//题目描述:给定一个没有重复元素的已序数组，返回范围，例如[0,1,2,4,5,7]，返回["0->2","4->5","7"]
//解法描述:用first和last来表示一个范围,遍历数组的时候，last表示下一位应该出现的元素，如果当前元素与last不等
//        说明找到了一个区间
std::vector<std::string> summaryRanges(std::vector<int>& nums)
{
	std::vector<std::string> result;
	if (nums.empty())
		return result;

	int first = nums[0];
	int last = first + 1; //下一个应该出现的元素
	for (int i = 1; i < nums.size(); ++i)
	{
		if (last != nums[i])
		{
			if (last - 1 == first)//该区间只有一个元素
				result.push_back(std::to_string(first));
			else
				result.push_back(std::to_string(first) + "->" + std::to_string(last - 1));
			first = nums[i];
			last = first + 1;
		}
		else
			++last;
	}

	if (last - 1 == first)
		result.push_back(std::to_string(first));
	else
		result.push_back(std::to_string(first) + "->" + std::to_string(last - 1));
	return result;
}