#include<unordered_map>
#include<string>
#include<vector>
#include<unordered_set>
//题目描述:给定一个压缩方式，字符串被压缩成<第一个字符><中间字符串的长度><最后一个字符>这种格式，现在给定一个
//        dictionary和一个字符串，判断该字符串的压缩结果是不是唯一的，即dictionary中的字符串压缩结果不与之相同
//解法描述:用map保存压缩结果和对应的字符串

class ValidWordAbbr 
{
private:
	std::unordered_map<std::string, std::unordered_set<std::string>> mp;

public:
	ValidWordAbbr(std::vector<std::string>& dictionary) 
	{
		for (std::string& d : dictionary) 
		{
			int n = d.length();
			std::string abbr = d[0] + std::to_string(n - 2) + d[n - 1];
			mp[abbr].insert(d);
		}
	}

	bool isUnique(std::string word) 
	{
		int n = word.length();
		std::string abbr = word[0] + std::to_string(n - 2) + word[n - 1];
		return mp[abbr].count(word) == mp[abbr].size();
	}
};