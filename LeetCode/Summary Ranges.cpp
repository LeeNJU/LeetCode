#include<string>
#include<vector>

//��Ŀ����������һ��û���ظ�Ԫ�ص��������飬���ط�Χ������[0,1,2,4,5,7]������["0->2","4->5","7"]
//�ⷨ��������first��last����ʾһ����Χ
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
		else //�ҵ�һ����Χ
		{
			if (first == last) //Ҫ�жϷ�Χ����һ��Ԫ�ػ����ж��Ԫ��
				result.push_back(std::to_string(nums[first]));
			else
				result.push_back(std::to_string(nums[first]) + "->" + std::to_string(nums[last]));
			first = i;
			last = i;
		}
	}
	if (first == last)//��������һ����Χ
		result.push_back(std::to_string(nums[first]));
	else
		result.push_back(std::to_string(nums[first]) + "->" + std::to_string(nums[last]));
	return result;
}