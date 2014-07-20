#include<string>
#include<vector>
#include<map>
#include<iostream>

void dfs(std::vector<std::string>& result, std::map<char, std::vector<char>>& data,std::string& s, std::string ret, int depth)
{
	if (depth == s.length())
	{
		result.push_back(ret); 
		return;
	}

	std::vector<char> t = data[s[depth]];
	for (size_t i = 0; i < t.size(); ++i)
	{
		dfs(result, data, s, ret + t[i], depth + 1);
	}
}

std::vector<std::string> letterCombinations(std::string digits)
{
	std::vector<std::string> result;
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

