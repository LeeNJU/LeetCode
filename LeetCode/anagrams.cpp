#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>

//题目描述:给定一个字符串数组，找出所有的anagrams,anagram是指字符串中字符种类个数都一样，只是顺序不一样的字
//        符串，例如{"aet", "tea","ate"}
//解法描述:将每个字符串排序，把排序后的字符串作为map的key，存入哈希表中，然后检查某一个key对应的数组中字符串
//        的个数是否多于1

std::vector<std::string> anagrams(std::vector<std::string> &strs)
{
	std::vector<std::string> result;
	std::unordered_map<std::string, std::vector<std::string>> group;

	for (int i = 0; i < strs.size(); ++i)//将strs中字符串进行排序，然后作为key，把可以相等的字符串存入哈希表中
	{
		std::string key = strs[i];
		sort(key.begin(), key.end());
		group[key].push_back(strs[i]);
	}

	for (auto iter = group.begin(); iter != group.end(); ++iter)//同一个key如果对应的数组大于1，说明有多个anagram
	{
		if (iter->second.size() > 1)
			result.insert(result.end(), iter->second.begin(), iter->second.end());
	}

	return result;
}