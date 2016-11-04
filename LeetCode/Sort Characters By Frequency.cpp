#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
//题目描述:给定一个字符串，根据字符的频率进行排序，频率高的出现在前面，例如给定"tree",返回"eert"或者"eetr"
//解法描述:统计字符串频率，然后排序

std::string frequencySort(std::string str) 
{
	std::unordered_map<char, int> map;
	for (char c : str)
		++map[c];

	std::vector<std::pair<int, char>> vec;
	auto iter = map.begin();
	while (iter != map.end())
	{
		vec.push_back(std::pair<int, char>(iter->second, iter->first));
		++iter;
	}

	std::string result = "";
	std::sort(vec.begin(), vec.end());
	for (int i = vec.size() - 1; i >= 0; --i)
	{
		auto pair = vec[i];
		int index = 0;
		while (index < pair.first)
		{
			result += pair.second;
			++index;
		}
	}
	return result;
}