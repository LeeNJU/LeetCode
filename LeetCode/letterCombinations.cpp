#include<string>
#include<vector>
#include<map>
//题目描述：给定一个数字字符串，每个数字对应手机上的字母，找出所有可能的字母组合，例如"23", 解为["ad", "ae", "af", 
//         "bd", "be", "bf", "cd", "ce", "cf"],因为数字2对应abc，数字3对应def
//解法描述：递归，用map保存数字与字母的对应关系，递归的层数作为digit的下标
void dfs(std::vector<std::string>& result, std::map<char, std::vector<char>>& data,std::string& digits, std::string temp, int depth)
{
	if (depth == digits.length())
	{
		result.push_back(temp); 
		return;
	}

	std::vector<char> t = data[digits[depth]];
	for (size_t i = 0; i < t.size(); ++i)
	{
		dfs(result, data, digits, temp + t[i], depth + 1);
	}
}

std::vector<std::string> letterCombinations(std::string digits)
{
	std::vector<std::string> result;
	if (digits.empty()) //排除特殊情况
		return result;

	std::map<char, std::vector<char>> data;
	data['2'] = { 'a', 'b', 'c' };
	data['3'] = {'d', 'e', 'f'};
	data['4'] = {'g', 'h', 'i'};
	data['5'] = {'j', 'k', 'l'};
	data['6'] = {'m', 'n', 'o'};
	data['7'] = {'p', 'q', 'r', 's'};
	data['8'] = {'t', 'u', 'v'};
	data['9'] = {'w', 'x', 'y', 'z'};
	dfs(result, data, digits, "", 0);
	return result;
}

