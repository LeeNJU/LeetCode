#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
//题目描述:给定一个字符串数组，定义如下操作:"eqdf"中每个字符都替换成字母表中的下一个字符,经过一次变换得到
//        "freg",可以继续变换，现在对字符串数组中的字符串进行分组，是的同一组内的都属于同一个变换
//解法描述:用map，把每个字符串换成最初的字符串，作为key
std::string shift(const std::string &str)
{
	std::string res = "";
	for (int i = 1; i < str.size(); ++i)
	{
		int diff = str[i] - str[i - 1];
		if (diff < 0)
			diff += 26;
		res += diff + 'a' + ',';
	}
	return res;
}

std::vector<std::vector<std::string>> groupStrings(std::vector<std::string>& strings) 
{
	std::vector<std::vector<std::string>> result;
	std::unordered_map<std::string, std::vector<std::string>> mp;
	for (auto str : strings) 
		mp[shift(str)].emplace_back(str);

	std::vector<std::vector<std::string>> res;
	for (auto elem : mp) 
	{
		if (elem.second.size() > 0) 
		{
			sort(elem.second.begin(), elem.second.end());
			res.emplace_back(elem.second);
		}
	}
	return res;
}

