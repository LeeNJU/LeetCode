#include<string>
#include<vector>

//题目描述：给定一个没有重复元素的已序数组，返回范围，例如[0,1,2,4,5,7]，返回["0->2","4->5","7"]
//解法描述：用first和last来表示一个范围
std::vector<std::string> summaryRanges(std::vector<int>& nums)
{
	std::vector<std::string> result;
	if (nums.empty())
		return result;

	int first = 0, last = 0;
	for (int i = 1; i < nums.size(); ++i)
	{
		if (nums[i] == nums[last] + 1)
			++last;
		else //找到一个范围
		{
			if (first == last) //要判断范围中有一个元素还是有多个元素
				result.push_back(std::to_string(nums[first]));
			else
				result.push_back(std::to_string(nums[first]) + "->" + std::to_string(nums[last]));
			first = i;
			last = i;
		}
	}
	if (first == last)//加入最后的一个范围
		result.push_back(std::to_string(nums[first]));
	else
		result.push_back(std::to_string(nums[first]) + "->" + std::to_string(nums[last]));
	return result;
}