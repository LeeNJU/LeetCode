#include<string>
#include<vector>
#include<algorithm>
//题目描述:给定一个非负整数数组，对数组进行排列，使得它们组成的数最小，例如[3, 32, 321],321323是最小的
//解法描述:先排序，对于a和b两个数字，如果ab排列组成的数字比ba排列组成的数字小，那么a排在b前面

bool compare(int num1, int num2)
{
	std::string s1 = std::to_string(num1);
	std::string s2 = std::to_string(num2);

	return s1 + s2 < s2 + s1;
}
std::string minNumber(std::vector<int>& nums) 
{
	sort(nums.begin(), nums.end(), compare);
	std::string result = "";
	for (int num : nums)
		result += std::to_string(num);
	
		int index = 0; //要注意排除最前面的0
	while (index < result.size() && result[index] == '0')
		++index;

	if (index == result.size())//全部是0
		return "0";

	return result.substr(index);
}