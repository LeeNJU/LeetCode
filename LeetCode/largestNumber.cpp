#include<algorithm>
#include<vector>
#include<string>
//题目描述：给定一个数组，把这些数组里的数拼接起来，使其形成的数最大，例如[3, 30, 34, 5, 9]，形成的最大数为9534330
//解法描述：关键是判断任意两个数a和b的先后顺序，先把数子转成string，然后通过比较a + b和b + a的大小来判断， 以此来排序，然后进行拼接，注意全是0的情况 

bool compare(const std::string& a, const std::string& b)
{
	return a + b > b + a;
}

std::string largestNumber(std::vector<int>& nums)
{
	std::vector<std::string> vec;
	for (int i = 0; i < nums.size(); ++i)
		vec.push_back(std::to_string(nums[i]));//注意这个函数，把整数转换成string

	std::sort(vec.begin(), vec.end(), compare);

	std::string result;
	for (int i = 0; i < vec.size(); ++i)//拼接
		result += vec[i];

	if (vec[0] == "0")//排除全是0的情况
		return vec[0];
	return result;
}