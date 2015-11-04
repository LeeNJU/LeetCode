#include<vector>
#include<string>

int dfs(std::vector<std::string>& result, std::string t,const std::string& num, int index, int target)
{
	if (index == num.size() - 1)
	{
		if (num[num.size() - 1] - '0' == target)
		{
			result.push_back(t);
			return;
		}
	}

	for (int i = index; i < num.size() - 1; ++i)
	{
		int left_value = stoi(num.substr(index, i - index + 1));
		dfs(result, num.substr(index, i - index + 1) + "+" + num.substr(i + 1), num, i + 1, target - left_value);
		dfs(result, num.substr(index, i - index + 1) + "-" + num.substr(i + 1), num, i + 1, left_value - target);
		if (left_value != 0)
			dfs(result, num.substr(index, i - index + 1) + "*" + num.substr(i + 1), num, i + 1, target / left_value);
	}
}

std::vector<std::string> addOperators(std::string num, int target) 
{
	std::vector<std::string> result;
	dfs(result, "", num, 0, target);
	return result;
}